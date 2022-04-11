import os, sys, json
from PyQt5.QtCore import QFileSystemWatcher, QTime, QTimer, Qt
from PyQt5.QtWidgets import QWidget, QPushButton, QApplication, QLabel, QMainWindow,QPlainTextEdit, QMessageBox
from PyQt5.QtGui import QPalette, QBrush, QPixmap
from Show_picture_v1UI import Ui_MainWindow

root_path = '/Users/lucifer/PythonCode/pyqt5/picture/'
logfile = '/Users/lucifer/PythonCode/pyqt5/picture/log.json'
logcnt = 5

class ShowWindow(QWidget):
    """ 将一个显示图片的lable及其关联属性打包 """
    def __init__(self, name, title):
        super().__init__()
        self.name = name
        self.title = title
        self.path = ''
        self.file_list = []
        self.cnt = 0
        self.watcher = QFileSystemWatcher()
        self.time = QTimer(self)
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
        # print(f'{self.title.text()} : {self.cnt} , FileList: {len(self.file_list)}')
        pixmap = QPixmap(self.path + '/' + self.file_list[self.cnt])
        pixmap.scaled(400, 400, aspectRatioMode=Qt.KeepAspectRatio)
        self.name.setPixmap(pixmap)
        
        self.cnt += 1

    # 监控槽函数
    # 检测到有新添加的文件后对图片文件列表进行更新，使其能显示最新图片
    def update_file(self, path):
        file_list = os.listdir(self.path)
        filename = []
        for i in file_list:
            t = i.split('.')[-1]
            if 'jpg' == t or 'jpeg' == t or 'png' == t:
                filename.append(i)
        filename = sorted(filename,  key=lambda x: os.path.getctime(os.path.join(self.path, x)), reverse=True)
        filename = filename[:50]
        self.file_list = filename

        self.cnt = 0
        print(path + ' has changed!')


class MainWindow(QMainWindow):

    def __init__(self):
        super().__init__()
        self.ui = Ui_MainWindow()  # 创建UI对象
        self.ui.setupUi(self)      # 构造UI
        
        self.window_init()

        # 添加监控文件目录
        self.file_watcher1 = QFileSystemWatcher()
        self.file_watcher1.addPath(logfile)
        self.file_watcher1.fileChanged.connect(self.update_log)
        self.update_log(logfile)
        self.old_size = 0
        self.new_size = 0
        # fw_list = self.file_watcher1.directories() # 查看被监控文件或目录

    """ 
        初始化图片显示窗口 
        将一个图片窗口的 路径，名称，标题，文件列表,监控路径 进行初始化    
    """
    def window_init(self):
        self.show_windows = {}

        self.show_windows['pic1'] = ShowWindow(self.ui.label1, self.ui.label1_title)
        self.show_windows['pic2'] = ShowWindow(self.ui.label2, self.ui.label2_title)
        self.show_windows['pic3'] = ShowWindow(self.ui.label3, self.ui.label3_title)
        self.show_windows['pic4'] = ShowWindow(self.ui.label4, self.ui.label4_title)

        path_list = os.listdir(root_path)
        index = 1

        for i in path_list:
            path = root_path + i
            if os.path.isdir(path):
                name = 'pic' + str(index)
                self.show_windows[name].set_path(path)
                self.show_windows[name].title.setText(path.split('/')[-1])
                self.show_windows[name].watcher.addPath(path)
                self.show_windows[name].set_file_list(self.update_dir(path))
                self.show_windows[name].name.setScaledContents(True)

                # print(str(index),' ', self.show_windows[name].watcher.directories())

                index += 1
        
        self.show_windows['pic1'].set_interval(2000)
        self.show_windows['pic2'].set_interval(2000)
        self.show_windows['pic3'].set_interval(2000)
        self.show_windows['pic4'].set_interval(2000)

    def timer_timeout(self):
        # self.cnt += 1
        # if(self.cnt > 20):
        #     self.cnt = 0
        try:
            for i in self.show_windows.values():

                i.name.setPixmap(QPixmap(i.path + '/' + i.file_list[i.cnt]))
                i.cnt += 1
                if i.cnt > 20:
                    i.cnt = 0

                # self.ui.label1.setPixmap(QPixmap(self.file_path[0] + '/' + self.filename_list[0][self.cnt]))
                # self.ui.label2.setPixmap(QPixmap(self.file_path[1] + '/' + self.filename_list[1][self.cnt]))
                # self.ui.label3.setPixmap(QPixmap(self.file_path[2] + '/' + self.filename_list[2][self.cnt]))
                # self.ui.label4.setPixmap(QPixmap(self.file_path[3] + '/' + self.filename_list[3][self.cnt]))
        except:
            pass

    """ 实时更新显示日志文件 """
    def update_log(self,file):
        mess_list = []
        self.ui.textBrowser.clear()
        with open(file, 'r') as f:
            content = json.load(f)

            key_list = list(content)[-logcnt:]
            for i in key_list:
                self.ui.textBrowser.append(content[i]['description'])
        
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

app = QApplication([])
mainw = MainWindow()
mainw.show()
app.exec_()
