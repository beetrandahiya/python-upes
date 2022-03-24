inpstr=input()

inpstr=inpstr.split()

#sort according to length of string
#simple insertion sort based on the length of the element
def sortwords(arr):
    n=len(arr)
    for i in range(1, n):
        temp = arr[i]
 
        j = i - 1
        while j >= 0 and len(temp) > len(arr[j]):
            arr[j + 1] = arr[j]
            j -= 1
 
        arr[j + 1] = temp

    return arr

print(sortwords(inpstr))

#printing in order with number of letters

for i in sortwords(inpstr):
    print(i+" : "+str(len(i)))

