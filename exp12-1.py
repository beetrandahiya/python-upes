from tkinter import *

root = Tk()              # create a window

root.title("Exp12-1")    # set title

root.geometry("300x600")  # set window size

my_label = Label(root, text="Hello").pack()

def my_function():
    new_label = Label(root, text="Button was clicked").pack()

my_button = Button(root, text="Click me", command=my_function,bg="#f05fe8",fg="#fff").pack()

root.mainloop()

