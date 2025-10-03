#!/usr/bin/env

class Shape:
	width = 5
	height = 5
	printChar = '#'

	def printRow(self, i):
		raise NotImplementedError("Will be implemented by children extending this class")

	def print(self):
		for i in range(self.height):
			self.printRow(i)


class Square(Shape):
	def printRow(self, i):
		print(self.printChar * self.width)

class Triangle(Shape):
	
	def __init__(self, height, width):
		self.height = height
		self.width = width

	def printRow(self):
		for h in range(self.height):
			print(self.printChar * (self.width - h))
