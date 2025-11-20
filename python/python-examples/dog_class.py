#!/usr/bin/env python3

class Dog:
	# class variable the same for each object created
	# would only do this for constant instances
	_legs: int = 4 

	def __init__(self, name: str):
		self.name = name # instance variable different for each object created
	
	def getLegs(self):
		return self._legs


	def speak(self):
		print(self.name + ' says: Bark!')

class Husty(Dog):

	def __init__(self, eye_color: str = None):
		super().__init__
		self.eye_color = eye_color
	
