inpstr=input()
inpstr=inpstr.lower()
letters={}
for i in inpstr:
    if(i in letters):
        letters[i]+=1
    else:
        letters[i]=1

print(letters)