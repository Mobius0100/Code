import sounddevice as sd
import os
import soundfile
import threading
import time

# 使用 sox 修改音频属性
# sox -V xx.wav -n
# 复制一份wav文件保存audio_ok_name, 利用sox调整参数：通道-1 位-16 采样率-16k
# subprocess.call(["sox {} -r 16000 -b 16 -c 1 {}".format(audio_name, audio_ok_name)], shell=True)
# bash$ sox filename -r 48000 -b 16 -c 1 outfile
# 
# 使用aplay -l 查询声卡信息
# 使用amixer -c 声卡id  查询具体参数
# 使用amixer -c id set name 10 设置输出音量 

DATA_TYPE = "float32"

def query_output_id(name):

    # 查询当前主机能用的声卡声道
    devices_list = sd.query_devices()  
    out_list = []
    for index,device_msg_dict in enumerate(devices_list):
        if name in device_msg_dict["name"] and device_msg_dict["max_output_channels"] > 0 and device_msg_dict["hostapi"] == 0:
            out_list.append(index)
    
    return out_list

# ======================
# 播放函数，用于多线程调用
# 输入：声卡ID，音频数据
# Linux播放声音要修改采样率
# ======================
def playOnUsb(audioId,audioData):
    sd.default.device[1] = audioId           # 设置默认输出声卡id，1表示输出，0表示输入
    sd.play(audioData,samplerate=48000,blocking=True)   # 播放声音，blocking表示是否允许播完

def playthread():
    outPutId = query_output_id("JieLi AC46") # 按声卡名称查找声卡设备id
    print(outPutId)
    file_path = []
    file_path.append( "/home/ubuntu1/project/yolo_test/tensorrtx-yolov5-v5.0/yolov5/output_sound/Alarm.wav") 
    file_path.append( "/home/ubuntu1/project/yolo_test/tensorrtx-yolov5-v5.0/yolov5/output_sound/piku.wav") 
    print(file_path)

    fileData = []
    for index,id in enumerate(outPutId):
        data,sampleRate = soundfile.read(file_path[index])    # 读取音频文件
        fileData.append(data)

    print("playing!")

    # 创建线程，注意for in zip的用法
    # zip将两个序列压缩成一个对象，返回一个列表
    # for in将zip列表中的值分别赋给变量
    threads = [threading.Thread(target=playOnUsb, args = [outId,audioData]) for outId,audioData in zip(outPutId,fileData)]   

    for thread in threads:
        thread.start()  
    
    for thread,device_index in zip(threads, outPutId):
        print("Waiting for device", device_index,"to finish!")
        thread.join()
   
if __name__ == "__main__":
    playthread()
