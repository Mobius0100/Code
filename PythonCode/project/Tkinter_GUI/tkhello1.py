from os import link
from threading import local
import threading
import tkinter
import tkinter.messagebox
import socket
from tkinter.constants import BOTH, BOTTOM, END, HORIZONTAL, LEFT, LEFT, RIGHT, S, TOP, W, X, Y
from typing import Text


def resize(ev=None):
    lable.config(font=('Courier', scale.get(), 'bold'))

top = tkinter.Tk()
top.title = 'kkkk'
top.pack
lable = tkinter.Label(top, text='Hello Tk!')
lable.pack(fill=Y, expand=1)

scale = tkinter.Scale(top, from_=10, to=40, orient=HORIZONTAL, command=resize)
scale.set(12)
scale.pack(fill=X, expand=1)


textsb = tkinter.Scrollbar(top)
textsb.pack(side=LEFT, fill=Y)
text = tkinter.Text(top, height=5, width=50, yscrollcommand=textsb, )
text.pack()
 
data = tkinter.StringVar(top)
data.set('Hello world!\nFUCK')


quit = tkinter.Button(top, text='Bye Tk!', 
    command=top.quit, bg='blue', fg='white')
quit.pack()

tkinter.mainloop()