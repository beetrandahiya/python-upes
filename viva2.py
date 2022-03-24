#factorial
#looping from n to 1 and multiplying them
def factorialofn(n):
    fact=1
    i=n
    while i>0:
        fact*=i
        i-=1
    return fact

#nCr
# formula => nCr = (n!)/(r! * (n-r)!)
def nCr(n,r):
    return (factorialofn(n)/(factorialofn(r)*factorialofn(n-r)))

#nPr
# formula => nCr = (n!)/((n-r)!)
def nPr(n,r):
    return (factorialofn(n)/(factorialofn(n-r)))

print(nCr(5,2))
print(nPr(5,2))