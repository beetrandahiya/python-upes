# WAP to create to files
# 1. file1.txt
# 2. file2.txt

import os

f1=open("file1.txt","w")
f2=open("file2.txt","w")

f1.write("This is file1.txt")
f1.close()
#read file 1
f1=open("file1.txt","r")
ftxt=f1.read()[::-1]
f1.close()

f2.write(ftxt)




