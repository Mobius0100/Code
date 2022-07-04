import json,os,time

from PyQt5.QtCore import QFileSystemWatcher, QSettings, Qt
from PyQt5.QtWidgets import (QApplication, QFileDialog, QLabel, QMainWindow,
                             QMessageBox, QPushButton, QSizePolicy, QWidget)
from picWindow import ShowWindow
from ui_v2 import Ui_MainWindow

root_path = ''
logpath = ''
logcnt = 20

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
        elif len(path_list) == 3:
            self.update_widget(4, 2)
            self.ui.gridLayout.setRowStretch(1,1)
            self.ui.gridLayout.setRowStretch(3,1)
            self.show_windows = self.show_windows[:-1]
        elif len(path_list) >= 4:
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
            # self.show_windows[i].set_interval(2000) # 设置定时并启动
            # self.show_windows[i].cnt_add()
            self.show_windows[i].set_cnt(0)
        
    """ 按键触发事件 """
    def keyPressEvent(self, event): 
        # print(len(self.show_windows))
        if event.key() == Qt.Key_D:
            print("right key press")
            for window in self.show_windows:
                window.cnt_add()
                filename = window.get_file_name() + '.json'
                # print(filename)
                self.update_log(os.path.join(logpath, filename))
        
        if event.key() == Qt.Key_A:
            print("left key press")
            for window in self.show_windows:
                window.cnt_min()
                filename = window.get_file_name() + '.json'
                # print(filename)
                self.update_log(os.path.join(logpath, filename))

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
            self.ui.textBrowser.append(str(content))   
        self.ui.textBrowser.ensureCursorVisible()  

    """ 实时更新显示日志文件 """
    def update_log(self,file):
        time.sleep(0.5)
        self.ui.textBrowser.clear()
        flag = 0
        try:
            with open(file, 'r', encoding='UTF-8') as f:     # 出现gbk解码问题 ‘r’ 后可加encoding='UTF-8'
                content = json.load(f)
                self.ui.textBrowser.append(str(content))

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
    # logcnt = int(settings.value("Count/log_cnt"))
    logpath = settings.value('Path/log_path')

    app = QApplication([])
    mainw = MainWindow()
    mainw.showMaximized()
    app.exec_()
