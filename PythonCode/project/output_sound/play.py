from threading import *
import time
from playsound import playsound
import pyaudio
import wave
# 定义数据流块
CHUNK = 1024
class MyThread(Thread):
    def init(self,filename):
        self.wf = wave.open(filename, 'rb')  # (sys.argv[1], 'rb')
        self.p = pyaudio.PyAudio()  # 创建一个播放器
        # 打开数据流
        self.stream = self.p.open(format=self.p.get_format_from_width(self.wf.getsampwidth()),
                             channels=self.wf.getnchannels(),
                             rate=self.wf.getframerate(),
                             output=True)
        # 读取数据
        self.data = self.wf.readframes(CHUNK)

        self.__flag =  Event()  # 用于暂停线程的标识
        self.__flag.set()
        self.ifdo = True

    def run (self):

        while self.ifdo and self.data != '' :
            self.__flag.wait()
            #print('I am running...')
            # time.sleep(2)

            # 播放
            self.stream.write(self.data)
            self.data = self.wf.readframes(CHUNK)
        # self.data = ''

    def stop (self):
        print('I am stopping it...')
        self.ifdo = False
    # def restart(self):
    #     self.ifdo


def playss():
    tr = MyThread()
    tr.init("/home/ubuntu1/project/yolo_test/tensorrtx-yolov5-v5.0/yolov5/output_sound/Alarm.wav")
    # tr.setDaemon(True)
    tr.start()
    time.sleep(3)
    tr.stop()

playss()
