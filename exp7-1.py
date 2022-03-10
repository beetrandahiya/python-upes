import os
file1=open("abc.txt","r")
a=file1.readlines()
nstr=""

for j in a:
    for i in j:
        if i=='"':
            nstr+=' \\"'
        else:
            nstr+=i

print(nstr)
file2=open("abc1.txt",'w')
file2.write(nstr)
