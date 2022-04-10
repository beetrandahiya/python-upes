class Vehicle:
    def __init__(self,name,max_speed,mileage,color="white"):
        self.name=name
        self.max_speed=max_speed
        self.mileage=mileage
    
    def seating_capacity(self,capacity):
        return f"The seating capacity of a {self.name} is {capacity} passengers."



class Bus(Vehicle):
    def __init__(self,name, max_speed, mileage):
        super().seating_capacity(50)
    

Buss=Vehicle('Pinky',100,10)

# display stuff

print(Buss.max_speed)
print(Buss.mileage)
