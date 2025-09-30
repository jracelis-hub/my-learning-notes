#!/usr/bin/env python3

class Dog:
	def __init__(self, name):
		self.name = name
		self.legs = 4

	def speak(self):
		print(self.name + ' says: Bark!')

my_dog = Dog('Jarron')
my_dog.speak()
