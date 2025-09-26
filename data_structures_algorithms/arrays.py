#!/usr/bin/env python3

# This is an array "list" in python
# Each index in an array in python is actually just holding the
# reference to which the value is point out
# new_list = [ 04, 08, 12]
new_list = [1, 2, 3]
list_zero = new_list[0]

def loop_list(list_value, value):
	for i in range(0,len(new_list)):
		if new_list[i] == value:
			print(True)
			break
		else:
			print(False)

loop_list(new_list, 3)
