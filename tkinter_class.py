from tkinter import *
root = Tk()
root.geometry("400x300")
root.title("Tkinter Class")

my_menu = Menu(root)
root.config(menu=my_menu)
def command():
    my_label=Label(root,text="You clicked").pack()

#create menu item
file_menu = Menu(my_menu)
my_menu.add_cascade(label="File",menu=file_menu)
file_menu.add_separator()
file_menu.add_command(label="New",command=command)
file_menu.add_command(label="Exit",command=root.quit)

#edit menu
edit_menu = Menu(my_menu)
my_menu.add_cascade(label="Edit",menu=edit_menu)
edit_menu.add_command(label="Cut",command=command)
edit_menu.add_command(label="Copy",command=command)

root.mainloop()
