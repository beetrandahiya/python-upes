import os

# comments are for braindeads

f=open("abc.txt","r")    # open file
a=f.readlines()          # read all the lines and store it in an array
nstr=""                  # make an empty string

for i in range(len(a)):
    if(i%2!=0):
        nstr+=a[i]       # add odd lines to the empty string

f2=open("abc2.txt","w")  # write emty string to new file
f2.write(nstr)

f.close()                # close both files
f2.close()