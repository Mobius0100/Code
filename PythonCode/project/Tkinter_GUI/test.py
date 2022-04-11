import tkinter as tk

def add_one_line():
    global counter

    chat_record_box.configure(state=tk.NORMAL)
    text = f'Line {counter}'
    if counter:
        text = '\n'+text
    chat_record_box.insert("end", text)
    chat_record_box.see("end")
    chat_record_box.configure(state=tk.DISABLED)
    counter += 1

mainWnd = tk.Tk()
mainWnd.title("test")

mainWnd.attributes("-alpha",0.95)
chat_record_box = tk.Text(mainWnd, fg='Violet', font=("楷体"),bg='FloralWhite',
    highlightthickness='2', selectbackground='blue')
chat_record_box.pack(padx=10, pady=10)
chat_record_box.configure(state=tk.DISABLED)

button = tk.Button(text="Add one line", command=add_one_line)
button.pack()
counter = 0

mainWnd.mainloop()