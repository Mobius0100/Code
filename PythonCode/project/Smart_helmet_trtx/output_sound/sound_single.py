# encoding:utf-8
import sounddevice as sd
import os
import soundfile
import time
#from threading import Lock
def queryOutputId(name):

    # 查询声卡声道
    devicesList = sd.query_devices()  # 返回一个列表
    outList = []
    for index,device_msg_dict in enumerate(devicesList):
        if name in device_msg_dict["name"] and device_msg_dict["max_output_channels"] > 0 and device_msg_dict["hostapi"] == 0:
            outList.append(index)
    
    return outList

def Play_Sound():
    #lock = Lock()
    #lock.acquire()
    outPutId = queryOutputId("JieLi AC46")
    print(outPutId)
    filePath = []
    filePath.append( "/home/ubuntu1/test/yolov5-tensorrt-master/python/lib/output_sound/helmet_.wav") 
    #filePath.append( "/home/ubuntu1/project/yolo_test/tensorrtx-yolov5-v5.0/yolov5/output_sound/piku.wav") 
    print(filePath)
    for index,id in enumerate(outPutId):
        sd.default.device[1] = id            # 系统默认输出
        dataArray , sampleRate = soundfile.read(filePath[index])
        print(sampleRate)
        sd.play(dataArray,samplerate=48000,blocking=True)
    #lock.release()
    #time.sleep(2)
    return 1
#Play_Sound()
