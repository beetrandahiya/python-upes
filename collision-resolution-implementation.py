fruits=['apple','mango','cherry','banana','orange','grapes','kiwi','pineapple','papaya','melon']

def hashfn(value):
    alpha_var=ord(value[0])-96
    return alpha_var%4

arr = [[],[],[],[]]
for fruit in fruits:
    key = hashfn(fruit)
    arr[key].append(fruit)

for i in arr:
    print(i)
