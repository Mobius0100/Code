import os
import time
import tkinter
from tkinter.constants import BOTH, END, LEFT, NONE, RIGHT, Y

class DirList():
    def __init__(self, initdir=None, win_name = 'Windows'):
        
        self.top = tkinter.Tk()
        self.top.title = win_name
        self.lable = tkinter.Label(self.top, text='Directory Lister v1.0')
        self.lable.pack()

        # dir1 显示当前路径，cwd保存当前路径变量名
        self.cwd = tkinter.StringVar(self.top)
        self.dir1 = tkinter.Label(self.top, fg='blue', font=('Helvetica', 12, 'bold'))
        self.dir1.pack()

        # dirs 列出目录文件列表
        # dirsb使该列表可以滚动
        # 将列表与setdirgo函数绑定；绑定意味着将一个函数与按键、鼠标操作等一些事件连接起来，当双击列表中任意条目时，就会调用函数
        self.dirfm = tkinter.Frame(self.top)
        self.dirsb = tkinter.Scrollbar(self.dirfm)
        self.dirsb.pack(side=RIGHT, fill=Y)
        self.dirs = tkinter.Listbox(self.dirfm, height=15, width=50, yscrollcommand=self.dirsb.set)
        self.dirs.bind('<Double-1>', self.setdir_andgo)
        self.dirsb.config(command=self.dirs.yview)
        self.dirs.pack(side=LEFT, fill=BOTH)
        self.dirfm.pack()

        # dirn为输入目录的文本框，用于查询目的目录文件
        self.dirn = tkinter.Entry(self.top, width=50, textvariable=self.cwd)
        self.dirn.bind('<Return>', self.doLS)
        self.dirn.pack()

        # bfm 按钮框架
        # 定义了三个按钮并配置其回调函数
        self.bfm = tkinter.Frame(self.top)
        self.clr = tkinter.Button(self.bfm, text='Clear', command=self.clrDir, activeforeground='white', activebackground='blue')
        self.ls = tkinter.Button(self.bfm, text='List Directory', command=self.doLS, activeforeground='white', activebackground='blue')
        self.quit = tkinter.Button(self.bfm, text='Quit', command=self.top.quit, activeforeground='white', activebackground='red')
        self.clr.pack(side=LEFT)
        self.ls.pack(side=LEFT)
        self.quit.pack(side=LEFT)
        self.bfm.pack()

        # 以当前目录为起点
        if initdir:
            self.cwd.set(os.curdir)
            self.doLS()

    def clrDir(self, ev=None):
        self.cwd.set('')

    def setdir_andgo(self, ev=None):
        self.last = self.cwd.get()
        self.dirs.config(selectbackground='red')
        check = self.dirs.get(self.dirs.curselection())
        if not check:
            check = os.curdir
        self.cwd.set(check)
        self.doLS()
    
    def doLS(self, ev=None):
        error = ''
        tdir = self.cwd.get()
        if not tdir:
            tdir = os.curdir
        
        if not os.path.exists(tdir):
            error = tdir + ': no such file'
        elif not os.path.isdir(tdir):
            error == tdir + ': not a directory'
        
        if error:
            self.cwd.set(error)
            self.top.update()
            time.sleep(2)
            if not (hasattr(self, 'last') and self.last):
                self.last = os.curdir
            self.cwd.set(self.last)
            self.dirs.config(selectbackground='LightSkyBlue')
            self.top.update()
            return
        
        self.cwd.set('Fetching Directory Contents...')
        self.top.update()
        dirlist = os.listdir(tdir)
        dirlist.sort()
        os.chdir(tdir)

        self.dir1.config(text=os.getcwd())
        self.dirs.delete(0, END)
        self.dirs.insert(END, os.curdir)
        self.dirs.insert(END, os.pardir)

        for file in dirlist:
            self.dirs.insert(END, file)
        self.cwd.set(os.curdir)
        self.dirs.config(selectbackground='LightSkyBlue')

def main():
    d = DirList(os.curdir, 'FUCK')
    tkinter.mainloop()



if __name__ == '__main__':
    main()