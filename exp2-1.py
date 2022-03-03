n=int(input())
studs={}
for i in range(n):
    inpstr=input()
    name,grade1,grade2,grade3=inpstr.split()
    studs[name]=[int(grade1),int(grade2),int(grade3)]

name=input()

avg=float(sum(studs[name])/3)

print(round(avg,2))
    