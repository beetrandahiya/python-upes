class Employee:
    def __init__(self,fname,lname,pay):
        self.fname=fname
        self.lname=lname
        self.mail=fname+"."+lname+"@company.com"
        self.pay=pay
    

emp1=Employee("Mohandas","Gandhi",50000)

print(emp1.fname)