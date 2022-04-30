# pass by reference 

def f(lst):
    lst.append(4)
    print(lst)

# pass by value

def f2(lst):
    lst = lst + [4]
    print(lst)

print("PASS BY REFERENCE")
a=[1,2,3]
f(a)
print(a)

print("PASS BY VALUE")
a=[1,2,3]
f2(a)
print(a)



###################################################################

# map function 

a= [12,34,56]

a= list( map (str,a) )     # maps a function to every element of a list

new = " ".join(a)
print(new)
print(len(new))