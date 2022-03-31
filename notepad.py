# tkinter notepad 

from tkinter import *
root=Tk()
root.geometry("500x600")
root.title("Notepad")
root.attributes('-alpha',0.9)

text_area=Text(root,width=500,height=600)
text_area.pack()

#make menu
my_menu=Menu(root)
root.config(menu=my_menu)
def save_as():
    file=open("my_file.txt","w")
    text=text_area.get("1.0",END)
    file.write(text)
    file.close()

file_menu=Menu(my_menu)
my_menu.add_cascade(label="File",menu=file_menu)
file_menu.add_command(label="Save",command=save_as)
file_menu.add_command(label="Exit",command=root.quit)


root.mainloop()