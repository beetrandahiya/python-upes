n=int(input())

s=0
#looping from 1/1 to 1/n and adding them
for i in range(1,n+1):
    s+=1/i

print("sum  : "+str(s))