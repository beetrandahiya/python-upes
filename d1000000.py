t=int(input())
for ti in range(t):
    n=int(input())
    d=input().split()
    d=[int(x) for x in d]
    d.sort()
    v=d[n-1]
    l=0
    for i in range(n):
        if(v-1<=d[n-i-1]):
            l+=1
    
    print(l)