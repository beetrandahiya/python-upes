n=int(input("No. of stamps = "))
stamps=[]
for i in range(n):
    stamps.append(input())

stamps=set(stamps)
print(stamps)