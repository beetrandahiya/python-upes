mainstr=input()
sbstr=input()
occ=0
for i in range(len(mainstr)):
    if(mainstr[i:i+len(sbstr)]==sbstr):
        occ+=1
print(occ)