#!/usr/bin/env python3

# number is a variable and setting it equal to a 
# data type int that is a value of 1
number = 1

# def is to create a function
# print_number is the name of the function
# number is the parameter that needs
# to be passed into the variable 
# to produce the output
def print_number(number):
	if 1 == number:
		print("True")
	else:
		print("False")

# Note this takes no arguments therefore
# no argument must be passed when being called out
def do_something():
	print("Do something")

# print_number is calling the function
print_number(1)
do_something()

