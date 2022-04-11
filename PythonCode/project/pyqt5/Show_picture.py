import json
import os
import threading
import time

from playsound import playsound
from PyQt5 import QtWidgets
from PyQt5.QtCore import QFileSystemWatcher, QSettings, QTimer
from PyQt5.QtGui import QPixmap
from PyQt5.QtWidgets import (QApplication, QFileDialog, QLabel, QMainWindow,
                             QMessageBox, QPushButton, QSizePolicy, QWidget)

from ui_v2 import Ui_MainWindow

root_path = ''
logpath = ''
logcnt = 20
soundfile = '/Users/lucifer/Downloads/15233.wav'

class ShowWindow(QWidget):
    """ 
        显示窗口
        输入: 一个图片lable对象，一个标题label对象
        属性: 图片存放路径， 图片文件列表， 目录监控器， 定时器， 最多显示数量
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
        self.time.timeout.connect(self.timer_timeout)
        self.time_interval = 2000
        self.watcher.directoryChanged.connect(self.update_file)
    
    def set_path(self, path):
        self.path = path
    
    def set_file_list(self, file_list):
        self.file_list = file_list
    
    def set_cnt(self, cnt):
        self.cnt = cnt
    
    def set_watcher(self, watcher):
        self.watcher = watcher

    def set_interval(self, time):
        self.time_interval = time
        self.time.start(self.time_interval)

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

class MainWindow(QMainWindow):

    def __init__(self):
        super().__init__()
        self.ui = Ui_MainWindow()  # 创建UI对象
        self.ui.setupUi(self)      # 构造UI
        self.show_windows = []
        
        # global root_path
        # root_path = QFileDialog.getExistingDirectory(self, "选择根路径")
        self.window_init()

        # # 添加监控文件目录
        self.file_watcher1 = QFileSystemWatcher()
        self.logpath_watcher2 = QFileSystemWatcher()
        self.init_log(logpath)
        self.logpath_watcher2.addPath(logpath)
        self.file_watcher1.fileChanged.connect(self.update_log)
        self.logpath_watcher2.directoryChanged.connect(self.update_logpath)

    """ 
        初始化图片显示窗口 
        将图片显示窗口的 路径，名称，标题，文件列表,监控路径 进行初始化    
    """
    def window_init(self):  
        path_list = []
        temp_list = os.listdir(root_path)

        for i in temp_list:
            path = os.path.join(root_path, i)
            if os.path.isdir(path):
                path_list.append(path)

        self.clear_layout(self.ui.gridLayout)


        # 根据文件夹的多少来设置Grid布局并初始化显示窗口
        if len(path_list) == 1:
            self.update_widget(2, 1)
            self.ui.gridLayout.setRowStretch(1,1) # 设置图片占比最大，第一行占一
        elif len(path_list) == 2:
            self.update_widget(2, 2)
            self.ui.gridLayout.setRowStretch(1,1)
        elif len(path_list) <= 4:
            self.update_widget(4, 2)
            self.ui.gridLayout.setRowStretch(1,1)
            self.ui.gridLayout.setRowStretch(3,1)
        elif len(path_list) > 4:
            self.update_widget(4, 2)
            self.ui.gridLayout.setRowStretch(1,1) 
            self.ui.gridLayout.setRowStretch(3,1) # 第三行占1
        
        # 设置显示窗口的属性
        for i, path in enumerate(path_list):
            self.show_windows[i].set_path(path) # 设置图片路径
            self.show_windows[i].title.setText(path.split(os.sep)[-1]) # 设置title
            self.show_windows[i].watcher.addPath(path) # 添加监控目录
            self.show_windows[i].set_file_list(self.update_dir(path)) # 更新图片文件列表
            self.show_windows[i].name.setScaledContents(True) # 使图片自适应lable大小
            self.show_windows[i].set_interval(2000) # 设置定时并启动

    """ 添加Grid中的控件，并实例化相应的显示窗口"""
    def update_widget(self, row, col):
        lable = {}
        positions = [(i,j) for i in range(row) for j in range(col)]
        for i, pos in enumerate(positions):
            lable[i] = QLabel(str(i))
            self.ui.gridLayout.addWidget(lable[i], *pos, 1, 1)
        
        if row == 2 and col == 1:
            self.show_windows.append(ShowWindow(lable[1], lable[0]))
        else:
            for i in range(2, row*col, 4):
                self.show_windows.append(ShowWindow(lable[i], lable[i-2]))
                self.show_windows.append(ShowWindow(lable[i+1], lable[i-1]))
        
    """ 清除Grid布局中的所有控件 """
    def clear_layout(self, layout):
        for i in range(layout.count()):
            layout.itemAt(i).widget().deleteLater()

    """ 初始化日志显示 """
    def init_log(self, path):
        ori_list = os.listdir(path)
        log_list = []

        if self.file_watcher1.files():
            self.file_watcher1.removePaths(self.file_watcher1.files())

        for i in ori_list:
            t = i.split('.')[-1]
            if 'json' == t:
                log_list.append(i)

        self.log_list = sorted(log_list, key=lambda x: os.path.getctime(os.path.join(path, x)), reverse=True)
        
        self.file_watcher1.addPath(os.path.join(logpath, self.log_list[0]))
        
        self.ui.textBrowser.clear()

        with open(os.path.join(logpath, self.log_list[0]), 'r', encoding='UTF-8') as f:     # 出现gbk解码问题 ‘r’ 后可加encoding='UTF-8'
            content = json.load(f)

            key_list = list(content)[-logcnt:]
            for i in key_list:
                self.ui.textBrowser.append(content[i]['description'])   
        self.ui.textBrowser.ensureCursorVisible()  

    """ 实时更新显示日志文件 """
    def update_log(self,file):
        time.sleep(0.5)
        self.ui.textBrowser.clear()
        flag = 0
        try:
            with open(file, 'r', encoding='UTF-8') as f:     # 出现gbk解码问题 ‘r’ 后可加encoding='UTF-8'
                content = json.load(f)

                key_list = list(content)[-logcnt:]

                for i in key_list:
                    if 'helmet' == content[i]['event_type']:
                        flag = 1

                for i in key_list:
                    self.ui.textBrowser.append(content[i]['description'])
                    # if flag:
                    #     t = threading.Thread(target=playsound, args=(soundfile,))
                    #     t.start()
                    #     t.join()
                    #     flag = 0
        except Exception as ex:
            print(f'update log found ERROR! {ex}')

        self.ui.textBrowser.ensureCursorVisible()

    """ 更新图片文件列表 """
    def update_dir(self, path):
        # os.path.getmtime() 函数是获取文件最后修改时间
        # os.path.getctime() 函数是获取文件最后创建时间
        file_list = os.listdir(path)
        filename = []
        for i in file_list:
            t = i.split('.')[-1]
            if 'jpg' == t or 'jpeg' == t or 'png' == t:
                filename.append(i)

        filename = sorted(filename,  key=lambda x: os.path.getctime(os.path.join(path, x)), reverse=True)
        filename = filename[:50]

        return filename 
    """ 更新日志文件夹，监控最新日志文件"""
    def update_logpath(self, path):
        print(f'{path} has changed!')
        ori_list = os.listdir(path)
        log_list = []

        if self.file_watcher1.files():
            self.file_watcher1.removePaths(self.file_watcher1.files())

        for i in ori_list:
            t = i.split('.')[-1]
            if 'json' == t:
                log_list.append(os.path.join(path, i))
        try:
            self.log_list = sorted(log_list, key=lambda x: os.path.getctime(x), reverse=True)
        except Exception as ex:
            print('sort error, not found file, maybe watcher is too fast.')
            print(ex)

        self.file_watcher1.addPath(self.log_list[0])
        self.update_log(self.log_list[0])

        print(self.file_watcher1.files())


if __name__=='__main__':
    settings = QSettings("./config.ini", QSettings.IniFormat)
    root_path = settings.value('Path/root_path')
    print(root_path)
    logcnt = int(settings.value("Count/log_cnt"))
    logpath = settings.value('Path/log_path')

    app = QApplication([])
    mainw = MainWindow()
    mainw.showMaximized()
    app.exec_()
