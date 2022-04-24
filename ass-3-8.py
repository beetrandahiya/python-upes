import numpy as np
# a

#array of 10 zeros
arr=np.zeros(10)
print(arr)

# array of even numbers between 10 and 50
arr=np.arange(10,51,2)
print(arr)

# given question

mat=np.arange(1,26).reshape(5,5)
print(mat[2:5,1:5])

print(mat[0:3,1])
