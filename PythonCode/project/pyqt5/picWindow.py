from PyQt5.QtWidgets import QWidget, QSizePolicy
from PyQt5.QtGui import QPixmap
from PyQt5.QtCore import QFileSystemWatcher, QSettings, QTimer, Qt
import os,time

class ShowWindow(QWidget):
    """ 
        显示窗口
        输入: 一个图片lable对象，一个标题label对象
        属性: 图片存放路径， 图片文件列表， 目录监控器， 定时器， 显示数量
        方法: 设置参数， 图片增减， 
    """
    def __init__(self, name, title):
        super().__init__()
        self.name = name
        self.title = title
        self.path = ''
        self.file_list = []
        self.cnt = 0
        self.watcher = QFileSystemWatcher()
        self.time = QTimer(self)

        self.name.setSizePolicy(QSizePolicy.Ignored, QSizePolicy.Ignored)  # 禁止图片标签放大
        # self.time.timeout.connect(self.timer_timeout)
        self.time_interval = 2000
        self.watcher.directoryChanged.connect(self.update_file)
        
    # 控制边界
    def is_out_index(self):
        if self.cnt < 0:
            self.cnt = 0
        if self.cnt >= len(self.file_list):
            self.cnt = len(self.file_list)-1

    # 超时槽函数，定时超时后触发
    # 更换显示图片
    def timer_timeout(self):
        if self.cnt >= 20 or self.cnt >= len(self.file_list):
            self.cnt = 0

        if len(self.file_list) == 0:
            return 
        #print(f'{self.title.text()} : {self.cnt} , FileList: {len(self.file_list)}')
        try:   
            self.name.setPixmap(QPixmap(os.path.join(self.path, self.file_list[self.cnt])))
            self.cnt += 1
        except Exception as ex:
            print(f'Timeout found error! {ex}')

    # 监控槽函数
    # 检测到有新添加的文件后对图片文件列表进行更新，使其能显示最新图片
    def update_file(self, path):
        print(path + ' has changed!!')
        time.sleep(0.5)

        file_list = os.listdir(self.path)
        filename = []

        for i in file_list:
            t = i.split('.')[-1]
            if 'jpg' == t or 'jpeg' == t or 'png' == t:
                filename.append(i)

        if len(filename) == 0:
            self.name.clear()
            return 

        try:
            filename = sorted(filename,  key=lambda x: os.path.getctime(os.path.join(self.path, x)), reverse=True)
        except Exception as ex:
            print(f'Found Error!\n{ex}')

        filename = filename[:50]
        self.file_list = filename

        self.cnt = 0

    def set_path(self, path):
        self.path = path
    
    def get_file_name(self):
        self.is_out_index()
        return self.file_list[self.cnt].split('.')[0]
    
    def set_file_list(self, file_list):
        self.file_list = file_list

    def set_cnt(self, cnt):
        if len(self.file_list) == 0: return 
        self.cnt = cnt
        self.name.setPixmap(QPixmap(os.path.join(self.path, self.file_list[self.cnt])))
    
    def show_cnt(self):
        print(self.cnt)
        print(len(self.file_list))
    
    def set_watcher(self, watcher):
        self.watcher = watcher

    def set_interval(self, time):
        self.time_interval = time
        self.time.start(self.time_interval)
    
    # 向下新显示图片
    def cnt_add(self):
        if len(self.file_list) == 0: return 

        self.cnt += 1
        self.is_out_index()
        self.name.setPixmap(QPixmap(os.path.join(self.path, self.file_list[self.cnt])))

    # 向上新显示图片
    def cnt_min(self):
        if len(self.file_list) == 0: return

        self.cnt -= 1
        self.is_out_index()
        self.name.setPixmap(QPixmap(os.path.join(self.path, self.file_list[self.cnt])))

    