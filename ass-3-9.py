import os

#read file with records
def find_max():
    f=open("records.txt","r")
    records=f.readlines()
    roll_no=records[0].split()
    names=records[1].split()
    marks=[int(x) for x in records[2].split()]

    stud_max=marks.index(max(marks))

    return roll_no[stud_max],names[stud_max],marks[stud_max]
