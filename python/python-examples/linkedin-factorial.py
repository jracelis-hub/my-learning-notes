#!/usr/bin/env python3

def factorial(number):
	if type(number) != int:
		return None 
	if number < 0:
		return None 
	fact = 1
	counter = 1
	while counter <= number:
		print(f'Factorial({counter}) = {counter} * {fact}')
		fact *= counter
		counter += 1
	return fact

