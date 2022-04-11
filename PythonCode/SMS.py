import Jetson.GPIO as GPIO
import serial
import time
from smspdu.codecs import GSM, UCS2
import yaml
import threading


class SMSend(threading.Thread):
	def __init__(self):
		super().__init__()
		self.ser = serial.Serial("/dev/ttyUSB2",115200)
		self.ser.flushInput()
		with open('./config/config.yaml', 'r') as stream:
			config = yaml.safe_load(stream)
		self.phone_number = config['phone_number']
		self.text_message = '安全帽测试\nTest...'
		
		self.powerKey = 6
		self.rec_buff = ''

	def sendAt(self, command,back,timeout):
		rec_buff = ''
		self.ser.write((command+'\r\n').encode())
		time.sleep(timeout)
		if self.ser.inWaiting():
			time.sleep(0.01 )
			rec_buff = self.ser.read(self.ser.inWaiting())
		if back not in rec_buff.decode():
			print(command + ' ERROR')
			print(command + ' back:\t' + rec_buff.decode())
			return 0
		else:
			print(command + ' back:\t' + rec_buff.decode())
			return 1

	def SendShortMessage(self, phone_number,text_message):
		text_message = UCS2.encode(text_message)
		print("Setting SMS mode...")
		self.sendAt('AT+CSCS="UCS2"', 'OK', 1)
		self.sendAt('AT+CMGF=1','OK',1)
		self.sendAt('AT+CSMP=17,128,2,25','OK', 1)

		print("Sending Short Message")
		for number in phone_number:
			answer = self.sendAt("AT+CMGS=\""+ UCS2.encode(number) +"\"",">",2)
			if 1 == answer:
				self.ser.write(text_message.encode())
				self.ser.write(b'\x1A')
				answer = self.sendAt('','OK',20)
				if 1 == answer:
					print('send successfully')
				else:
					print('error')
			else:
				print('error%d '%answer)

	def powerOn(self, powerKey):
		print('SIM7600X is starting:')
		GPIO.setmode(GPIO.BCM)
		GPIO.setwarnings(False)
		GPIO.setup(powerKey,GPIO.OUT)
		time.sleep(0.1)
		GPIO.output(powerKey,GPIO.HIGH)
		time.sleep(2)
		GPIO.output(powerKey,GPIO.LOW)
		time.sleep(20)
		self.ser.flushInput()
		print('SIM7600X is ready')

	def powerDown(self, powerKey):
		print('SIM7600X is loging off:')
		GPIO.setmode(GPIO.BCM)
		GPIO.setwarnings(False)
		GPIO.setup(powerKey,GPIO.OUT)
		GPIO.output(powerKey,GPIO.HIGH)
		time.sleep(3)
		GPIO.output(powerKey,GPIO.LOW)
		time.sleep(18)
		print('Good bye')

	def checkStart(self):
		while True:
			self.ser.write( ('AT\r\n').encode() )
			time.sleep(0.1)
			if self.ser.inWaiting():
				time.sleep(0.01)
				recBuff = self.ser.read(self.ser.inWaiting())
				print( 'try to start\r\n' + recBuff.decode() )
				if 'OK' in recBuff.decode():
					recBuff = ''
					return
			else:
				self.powerOn(self.powerKey)
				time.sleep(1)

	def run(self):
		try:
			self.checkStart()
			self.SendShortMessage(self.phone_number, self.text_message)
			self.powerDown(self.powerKey)
		except:
			self.powerDown(self.powerKey)
			self.ser.close()
			GPIO.cleanup()

# s = SMSend()
# s.start()
