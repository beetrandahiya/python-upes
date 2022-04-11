import numpy as np
# a
# astype method is used to cast the data type of the array
arr=[1,2.0,3]
arr=np.array(arr)
arr=arr.astype(np.str)
print(arr)

#b

arr2d=[[1,2,3],[4,5,6]]
arr2d=np.array(arr2d)
arr2d=arr2d.astype(np.int32)
print(arr2d)

#c
#use shape method to get the shape of the array : for 2d array shape = rows, columns
rows=arr2d.shape[0] 
cols=arr2d.shape[1]
print(rows,cols)

#d
# numpy random module is used to generate random numbers
for i in range(10):
    print(np.random.randint(1,100))

