def add_natural(n):
    if n == 0:
        return 0
    else:
        return n + add_natural(n - 1)

def fibbonaci(n):
    fibb=[1,2]
    if n==0:
        return 0
    elif n==1:
        return 1
    else:
        for i in range(2,n+1):
            fibb.append(fibb[i-1]+fibb[i-2])   

    print(fibb)         
