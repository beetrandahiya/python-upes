import os


f=open("abc.txt","r")
a=f.readlines()
nstr=""

for i in range(len(a)):
    if(i%2!=0):
        nstr+=a[i]

f2=open("abc2.txt","w")
f2.write(nstr)

f.close()
f2.close()