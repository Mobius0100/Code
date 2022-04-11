import Jetson.GPIO as GPIO
import serial
import time
from smspdu.codecs import GSM, UCS2


ser = serial.Serial("/dev/ttyUSB2",115200)
ser.flushInput()

phone_number = ['18890572700', '17851301892']
text_message = '安全帽测试\nTest...'

text_message = UCS2.encode(text_message)
powerKey = 6
rec_buff = ''

def sendAt(command,back,timeout):
	rec_buff = ''
	ser.write((command+'\r\n').encode())
	time.sleep(timeout)
	if ser.inWaiting():
		time.sleep(0.01 )
		rec_buff = ser.read(ser.inWaiting())
	if back not in rec_buff.decode():
		print(command + ' ERROR')
		print(command + ' back:\t' + rec_buff.decode())
		return 0
	else:
		print(command + '\nback:\t' + rec_buff.decode())
		return 1

def SendShortMessage(phone_number,text_message):
	
	print("Setting SMS mode...")
	sendAt('AT+CSCS="UCS2"', 'OK', 1)
	sendAt('AT+CMGF=1','OK',1)
	sendAt('AT+CSMP=17,128,2,25','OK', 1)

	print("Sending Short Message")
	for number in phone_number:
		answer = sendAt("AT+CMGS=\""+ UCS2.encode(number) +"\"",">",2)
		if 1 == answer:
			ser.write(text_message.encode())
			ser.write(b'\x1A')
			answer = sendAt('','OK',20)
			if 1 == answer:
				print('send successfully')
			else:
				print('error')
		else:
			print('error%d '%answer)

def ReceiveShortMessage():
	rec_buff = ''
	print('Setting SMS mode...')
	sendAt('AT+CMGF=1','OK',1)
	sendAt('AT+CPMS=\"SM\",\"SM\",\"SM\"', 'OK', 1)
	answer = sendAt('AT+CMGR=1','+CMGR:',2)
	if 1 == answer:
		answer = 0
		if 'OK' in rec_buff:
			answer = 1
			print(rec_buff)
	else:
		print('error%d'%answer)
		return False
	return True

def powerOn(powerKey):
	print('SIM7600X is starting:')
	GPIO.setmode(GPIO.BCM)
	GPIO.setwarnings(False)
	GPIO.setup(powerKey,GPIO.OUT)
	time.sleep(0.1)
	GPIO.output(powerKey,GPIO.HIGH)
	time.sleep(2)
	GPIO.output(powerKey,GPIO.LOW)
	time.sleep(20)
	ser.flushInput()
	print('SIM7600X is ready')

def powerDown(powerKey):
	print('SIM7600X is loging off:')
	GPIO.setmode(GPIO.BCM)
	GPIO.setwarnings(False)
	GPIO.setup(powerKey,GPIO.OUT)
	GPIO.output(powerKey,GPIO.HIGH)
	time.sleep(3)
	GPIO.output(powerKey,GPIO.LOW)
	time.sleep(18)
	print('Good bye')

def checkStart():
	while True:
		ser.write( ('AT\r\n').encode() )
		time.sleep(0.1)
		if ser.inWaiting():
			time.sleep(0.01)
			recBuff = ser.read(ser.inWaiting())
			print( 'try to start\r\n' + recBuff.decode() )
			if 'OK' in recBuff.decode():
				recBuff = ''
				return
		else:
			powerOn(powerKey)
			time.sleep(1)
try:
    checkStart()
    print('Sending Short Message Test:')
    SendShortMessage(phone_number,text_message)
    #print('Receive Short Message Test:\n')
    #print('Please send message to phone ' + phone_number)
    #ReceiveShortMessage()
    powerDown(powerKey)
except:
    if ser != None:
        ser.close()
    powerDown()
    GPIO.cleanup()
