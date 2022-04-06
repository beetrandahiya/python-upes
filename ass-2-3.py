import os

f=open("temp.txt","r")
a=f.readlines()
products=[]
for i in a:
    ap=i.split()
    products.append(ap)    

def all_prod_details():
    print("\nProduct Details")
    print("----------------")
    for i in products:
        print(i[0],i[1],i[2],i[3])
    
def avg_sale():
    print("\nAverage Sales")
    print("-------------")
    for i in products:
        sum=(int(i[1])+int(i[2])+int(i[3]))/3
        print("Average Price for",i[0],":",sum)

def min_sale():
    print("\nMinimum Sales")
    print("-------------")
    total_sales=[]
    min_index=0
    sump=0
    for i in products:
        sum=(int(i[1])+int(i[2])+int(i[3]))/3
        if sum<sump:
            sump=sum
            min_index=products.index(i) 
        else:
            sump=sum
    
    print(products[min_index][0],":",sump)


while(True):
    print("\n1. All Product Details")
    print("2. Average Sales")
    print("3. Minimum Sales")
    print("4. Exit")
    ch=int(input("Enter your choice: "))
    if ch==1:
        all_prod_details()
    elif ch==2:
        avg_sale()
    elif ch==3:
        min_sale()
    elif ch==4:
        break
    else:
        print("Invalid choice")