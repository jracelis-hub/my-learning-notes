#!/usr/bin/env python3

class Dog:
	_legs = 4 # class variable the same for each object created

	def __init__(self, name):
		self.name = name # instance variable different for each object created

	
	def getLegs(self):
		return self._legs


	def speak(self):
		print(self.name + ' says: Bark!')

myDog = Dog('Jarron')
myDog._legs = 3
print(myDog._legs)
# 3
print(Dog._legs)
# 4
