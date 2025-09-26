#!/usr/bin/env python3

# Recursive binary search is a function that calls itself until reaching the desired output
# How the return statement works is
# recursive_binary_search == target? No
# then return back to the top of recursive_binary_search and evaluate with modified parameters
# once the return statements evalutes as true or false and then goes back to the original
# statement and returns the reevaluated parameter and provides return value

def recursive_binary_search(list, target):
	if len(list) == 0:
		return False
	else:
		midpoint = (len(list))//2
	
		if list[midpoint] == target:
			return True
		else:
			if list[midpoint] < target:
				# list[midpoint + 1:] means start at midpoint and go to the end noted by :
				return recursive_binary_search(list[midpoint + 1:], target)
			else:
				# list[:midpoint] means start at the beginning 0 and go until the midpoint
				return recursive_binary_search(list[:midpoint], target)

def verify_recursive_binary_search(target):
		print("The target is at: ", target)

numbers = [1,3,5,6,7,10,13,15,22]

position = recursive_binary_search(numbers, 33)
verify_recursive_binary_search(position)
