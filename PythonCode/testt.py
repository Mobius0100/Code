import time
from threading import Thread


class PrintTimeThread(Thread):
  """ 自定义线程类：用于打印当前时间 """
  
  def __init__(self):
    Thread.__init__(self)
    
  def run(self):
    """ 重写 run 方法：实现子线程处理逻辑 """
    while True:
      print(time.asctime())      # 打印时间
      time.sleep(1)              # 休眠1秒
      
      
if __name__ == "__main__":
  # 实例化子线程对象
  my_thread = PrintTimeThread()
  
  # 启动子线程
  my_thread.start()
  
  # 为了作对比，主线程中每隔三秒打印一次 “hello”
  while True:
    print("hello")
    time.sleep(3)