from tkinter import *
root = Tk()
root.geometry("400x300")
root.title("Tkinter Class")
def myclick():
    mylabel1.config(text="I have been clicked!")
    mylabel2.config(text="I have been clicked again!")
mylabel1 = Label(root, text="Hello World!")
mylabel2 = Label(root, text="Hello World again!")
mybutton = Button(root, text="Click Me!", command=myclick)
mylabel1.grid(row=0,column=0)
mylabel2.grid(row=1,column=1)
mybutton.grid(row=2,column=2)
root.mainloop()

