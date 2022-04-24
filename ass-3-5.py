import os

t=input("TATA : ").split()
h=input("Hyundai : ").split()

f=open("auto.txt","w")

for i in t:
    f.write(i+" ")
f.write("\n")
for i in h:
    f.write(i+" ")


f.close()
#compute average

f=open("auto.txt","r")

sales=f.readlines()
t=[int(x) for x in sales[0].split()]
h=[int(x) for x in sales[1].split()]

t_avg=sum(t)/len(t)
h_avg=sum(h)/len(h)

print("TATA : ",t_avg)
print("Hyundai : ",h_avg)

#max index for tata
max_t=t.index(max(t))
print("Month with maximum sales for TATA : ",max_t+1)

#matplotlib to represent data

import matplotlib.pyplot as plt

months=["Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"]

plt.plot(months,t,label="TATA",color="blue")
plt.plot(months,h,label="Hyundai",color="red")
plt.show()