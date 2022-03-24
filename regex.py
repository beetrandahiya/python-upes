import re
from re import findall
a="hello world , how's stuff going?"

#find all matches of a substring

print(re.findall("g",a))

#search return match object, if exist

print(re.search("o",a))
print(re.search("o",a).span())

# split at particular character

print(re.split("o",a,maxsplit=2))             # \s is space


# sub , substitutes/replace all occurences

a1=re.sub("o","a",a)
print(a1)


#metacharacters and sybmols
'''
[] --> returns a match if string contains shit inside brackets
^  --> returns a match if string starts with a given pattern
$  --> returns a match if string ends with a given pattern
.  --> any character except new line
*  --> zero or more occurences
+  --> one or more occurences
{} --> specified number of occurences
/  --> special sequences
\d --> returns match where the string contains digits
\D --> doesnt have any digits
\w --> have word character
\W --> doesnt have word charcater
\s --> have a white space
\S --> doesnt have a white space
\Z --> if the specified characters are at the end of the string

-------Sets-------

[abc] --> returns a match if string contains any of the characters inside brackets
[a-n] --> returns a match if string contains any character in a range
[^abg]--> if string contains characters except those mentioned in the brackets, i.e. except a, b, g
[045] --> if string contains any number among specified
[0-5] --> number available in a given range
[3-5][2-8] --> double digit , with tens between 3, 5 and ones between 2,8
'''
a="hello world , how's stuff going?"
print("-----findall shite -----")
print(findall("[os]",a))
print(findall("i^",a))
print(findall("[?]$",a))
