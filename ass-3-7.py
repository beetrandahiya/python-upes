#zero division error
try:
    print(5/0)
except ZeroDivisionError:
    print("Fix your math! Division by zero is not allowed")

#NameError
try:
    print(a)
except NameError:
    print("Variable a is not defined, its a name error")

#IOError
try:
    f=open("ABCDEF.txt","r")
    f.write("Hello")
except IOError:
    print("File not found")


