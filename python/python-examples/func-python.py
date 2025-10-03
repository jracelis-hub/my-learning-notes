#!/usr/bin/env python3

# class is a keyword to create a class named Dog
class Dog:

	def	__init__(self, name: str, breed: str, age: int):
		"""
		The __init__ is a constructor which sets up the object
		with the proper values, allocates resource, etc...
		"""
		self.name = name
		self.breed = breed
		self.age = age
	
	def dogDetails(self):
		"""
		The parameter self is essentially the object name (instance) that 
		is created when assigning a instance to the class
		myDog = Dog(myDog, name, breed, age)
		onces the constructor is initialized all the self values can be seen
		when being passed
		"""
		print(f'Name: {self.name}\nBreed: {self.breed}\nAge: {self.age}')
	
	def bark(self):
		print(f'{self.name} bark!')
	
	def getName(self):
		return self.name
