#!/usr/bin/env python3

def triangle(num):
	print(f'{num}')
	if num == 1:
		return num
	return num + triangle(num - 1)


def square(num):
	return triangle(num) + triangle(num - 1)


