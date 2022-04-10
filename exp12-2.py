from tkinter import *

root = Tk()              # create a window

root.title("Exp12-2")    # set title

root.geometry("600x600")  # set window size
my_label = Label(root, text="Hello").grid(row=0, column=1)

def my_function2():
    username=my_entry.get()
    new_label = Label(root, text=username)
    new_label.grid(row=5, column=1)

def my_function3():
    new_label = Label(root, text="You have selected"+str(var.get())).grid(row=6, column=1)

var =IntVar()
f= Radiobutton(root, text="first choice", value=1, command=my_function3, variable=var)
f.grid(row=1, column=0)

s= Radiobutton(root, text="second choice", value=2, command=my_function3, variable=var)
s.grid(row=1, column=1)

th= Radiobutton(root, text="third choice", value=3, command=my_function3, variable=var)
th.grid(row=1, column=2)


my_entry= Entry(root, width=40)
my_entry.grid(row=2, column=1)



my_button = Button(root, text="Click me", command=my_function2,bg="#f05fe8",fg="#fff").grid(row=3, column=1)

root.mainloop()

