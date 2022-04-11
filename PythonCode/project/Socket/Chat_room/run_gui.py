import sys
import socket
import tkinter.messagebox
from tkinter.constants import BOTH, BOTTOM, DISABLED, END, LEFT, LEFT, NORMAL, RIGHT, S, TOP, W, E, X, Y
import threading
import tkinter


BUFFSIZ = 1024

class ChatWin(object):

    def __init__(self):
        """ 初始化图形界面 """
        self.root = tkinter.Tk()
        self.root.title('Socket通信 - 客户端V1.0')
        self.root.geometry('500x400')
        self.root.attributes('-alpha', 0.98) # 设置透明度
        self.root.protocol('WM_DELETE_WINDOW', self.exit) # 绑定退出按钮事件

        self.localhost = tkinter.StringVar(self.root)
        self.portstr = tkinter.IntVar(self.root)
        self.nickstr = tkinter.StringVar(self.root)
        self.localhost.set('127.0.0.1')
        self.portstr.set(21567)
        # self.nickstr.set('Link')

        # 定义初始连接框架
        self.info_frame = tkinter.Frame()
        self.host = tkinter.Label(self.info_frame, text='服务器IP：')
        self.port = tkinter.Label(self.info_frame, text='服务器端口：')
        self.nick = tkinter.Label(self.info_frame, text='昵称：')
        self.hostet = tkinter.Entry(self.info_frame, width=10, textvariable=self.localhost)
        self.portet = tkinter.Entry(self.info_frame, width=10, textvariable=self.portstr)
        self.nicket = tkinter.Entry(self.info_frame, width=10, textvariable=self.nickstr)
        self.connbt = tkinter.Button(self.info_frame, text='连接', command=self.connect_host)
        self.host.pack(side=LEFT, expand=1)
        self.hostet.pack(side=LEFT, expand=1)
        self.port.pack(side=LEFT, expand=1)
        self.portet.pack(side = LEFT, expand=1)
        self.nick.pack(side=LEFT, expand=1)
        self.nicket.pack(side=LEFT, expand=1)
        self.connbt.pack(side=LEFT, expand=1)
        self.info_frame.pack(expand=1, fill=BOTH,side=TOP)

        # 定义显示消息框架
        self.msg_frame = tkinter.Frame()
        self.msg_head_frame = tkinter.Frame()

        self.infolb = tkinter.Label(self.msg_head_frame, text='消息记录：')
        self.clearbt = tkinter.Button(self.msg_head_frame, text='清空消息',command=self.clear_msg)
        self.infolb.pack(side=LEFT, fill=X, expand=1)
        self.clearbt.pack(anchor=E)  # anchor= ? WENS 分别指代东南西北，还有其组合NE 东北
        self.msg_head_frame.pack()

        self.infosb = tkinter.Scrollbar(self.msg_frame)
        self.msglog = tkinter.Text(self.msg_frame,
                    yscrollcommand=self.infosb.set, 
                    font=("微软雅黑", 12), width=50,height=10,
                    wrap='word', state=DISABLED, ) # state=disable 设置text为只读;wrap=word/none/char 指定自动换行
        
        self.infosb.pack(side=RIGHT, fill=Y)
        self.msglog.pack()
        self.msg_frame.pack()

        # 定义发送消息框架
        self.input_frame = tkinter.Frame()
        self.inputlb = tkinter.Label(self.input_frame, text='输入消息：')
        self.input = tkinter.Entry(self.input_frame, width=45)
        self.inputbt = tkinter.Button(self.input_frame, text='发送', command=self.send_msg)
        self.input.bind('<Return>', self.send_msg)
        self.inputlb.pack(side=LEFT,expand=1)
        self.input.pack(side=LEFT,expand=1)
        self.inputbt.pack(side=LEFT,expand=1)
        self.input_frame.pack()

    def clear_msg(self):
        self.msglog.config(state=NORMAL)
        self.msglog.delete(1.0, END)
        self.msglog.config(state=DISABLED)

    def exit(self):
        """ 退出处理 """
        if tkinter.messagebox.askyesno('提示','确定要退出吗'):
            self.root.destroy()
            self.tcpcli_sock.send(b'#@exit')
            self.tcpcli_sock.close()
            sys.exit(0)

    def add_one_line(self, msg):
        
        self.msglog.config(state=NORMAL)
        self.msglog.insert(END, msg+'\n')
        self.msglog.see(END)
        self.msglog.config(state=DISABLED)

    def connect_host(self):
        """ 连接到主机 """
        if self.nickstr.get() == '':
            tkinter.messagebox.showwarning('提示','请输入昵称')
            return

        addr = (self.localhost.get(), self.portstr.get())
        self.tcpcli_sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        try:
            self.tcpcli_sock.connect(addr)
            self.tcpcli_sock.send(self.nickstr.get().encode('utf-8')) 

            # 开启接受信息线程
            self.start_thread()
        except:
                tkinter.messagebox.showerror('连接失败!','检查网络是否通畅或服务器状况。')

    def send_msg(self, ev=None):
        """ 发送消息 """
        msg = self.input.get()
        if msg == '':
            tkinter.messagebox.showwarning('提示','消息不能为空')
            return
        #self.msglog.insert(END, f'> {msg} \n')

        try:
            self.tcpcli_sock.send(msg.encode('utf-8'))
        except:
            # tkinter.messagebox.showerror('发送失败!','未连接服务器。')
            self.add_one_line('发送失败，未连接服务器')

        self.add_one_line(msg)
        self.input.delete(0, END)  # 删除文本框内容
        self.input.update()

    def recv_msg(self):
        """ 接收广播的消息 """
        while True:
            msg = self.tcpcli_sock.recv(BUFFSIZ)
            self.add_one_line(msg.decode('utf-8'))
            # self.msglog.insert(END, msg.decode('utf-8')+'\n')
            # self.msglog.update()

    def start_thread(self):
         """ 开启接收消息线程"""
         self.t = threading.Thread(target=self.recv_msg, args=())
         self.t.setDaemon(True)
         self.t.start()


def main():
    c = ChatWin()
    c.root.mainloop()

if __name__ == "__main__":
    main()