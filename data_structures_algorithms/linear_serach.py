#!/usr/bin/env python3

# def to create a function
# linear_serach name of function
# list and target are parameters to the function
# The algorithm for linear_search is
# input = list
# output = target
# if target not found return none
# else return position of the target
def linear_search(list, position):
	# The """ Is a here doc to document the code"""
	"""
	Returns the index position of the target if found, else returns None
	"""
	# i is just the index of which range is located at
	# range starts at 0 and the length of the list parameter
	for i in range(0, len(list)):
		if list[i] == position:
			return i
	return None

def verify_linear_search(index):
	if index is not None:
		print("Target found at index:", index)
	else:
		print("Target not found in list")
	
numbers = [1,2,3,4,5,6,7,8,9,10]

index = linear_search(numbers, 8)
verify_linear_search(index)
