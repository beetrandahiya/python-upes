import numpy as np

#convert list to complex array
numbers=[10,50,16,21]
arr=np.array(numbers,dtype=complex)
print(arr)

#convert all elements to string

arr=arr.astype(str)
print(arr)

#print 50 random numbers between 10 and 1000

print(np.random.randint(10,1000,50))

arr=np.arange(10,51,2)