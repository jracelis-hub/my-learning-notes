#!/usr/bin/env python3

def recursive_factorial(number):
	if type(number) != int:
		return None
	if number < 0:
		return None
	print(f'{number}')
	if number == 1:
		return 1
	return number * recursive_factorial(number - 1)
	
