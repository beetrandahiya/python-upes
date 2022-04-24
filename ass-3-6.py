import tkinter as tk
from tkinter import *
from tkinter import messagebox

root=Tk()
root.title("Registration Form")
root.geometry("500x500")

#input boxes and labels
fullname=StringVar()
email=StringVar()
country=StringVar()
prog_lang=StringVar()

l1=Label(root,text="Full Name")
l1.grid(row=0,column=0)

e1=Entry(root,textvariable=fullname)
e1.grid(row=0,column=1)

l2=Label(root,text="Email")
l2.grid(row=1,column=0)

e2=Entry(root,textvariable=email)
e2.grid(row=1,column=1)

l3=Label(root,text="Country")
l3.grid(row=2,column=0)

e3=Entry(root,textvariable=country)
e3.grid(row=2,column=1)

l4=Label(root,text="Programming Language")
l4.grid(row=3,column=0)

e4=Entry(root,textvariable=prog_lang)
e4.grid(row=3,column=1)

def submission():
    if(fullname.get()=="" or email.get()=="" or country.get()=="" or prog_lang.get()==""):
        print("Please fill all the fields")
        m1=messagebox.showinfo("Error","Please fill all the fields")
    else:
        print("Submitted Successfully")
        m2=messagebox.showinfo("Success","Submitted Successfully")
    


b1=Button(root,text="Submit",command=submission)
b1.grid(row=4,column=1)


root.mainloop()




