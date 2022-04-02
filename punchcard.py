t= int(input())
ans=[]
for i in range(t):
    rc=input().split()
    r=int(rc[0])
    c=int(rc[1])
    r=2*r+1
    c=2*c+1
    card=[]
    for j in range(r):
        card.append([])
        if(j==0):
            for k in range(c):
                if(k<2):
                    card[j].append(".")
                elif(k%2==0):
                    card[j].append("+")
                else:
                    card[j].append("-")
        elif(j==1):
            for k in range(c):
                if(k<2):
                    card[j].append(".")
                elif(k%2==0):
                    card[j].append("|")
                else:
                    card[j].append(".")
        elif(j%2==0):
            for k in range(c):
                if(k%2==0):
                    card[j].append("+")
                else:
                    card[j].append("-")
        else:
            for k in range(c):
                if(k%2==0):
                    card[j].append("|")
                else:
                    card[j].append(".")

    ans.append(card)

for i in range(t):
    print("Case #"+str(i+1)+":")
    card=ans[i]
    for j in range(len(card)):
        for k in range(len(card[j])):
            print(card[j][k],end="")
        print()