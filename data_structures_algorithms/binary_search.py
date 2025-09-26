#!/usr/bin/env python3

def binary_search(list, target):
# assign first and last
# constant time operation
	first = 0
	last = len(list) - 1

	while first <= last:
		# // is floor division which rounds to the nears whole number
		# ex 7/2 = 3.5 so itll round down to 3 as the midpoint
		# constant time operation
		midpoint = (first + last)//2
	
		# constant time operation
		if list[midpoint] == target:
			return midpoint
		elif list[midpoint] < target:
			first = midpoint + 1
		else:
			last = midpoint - 1

	return None

#  list[10] | 1 2 3 4 5 6 7 9 10 15 |	
#                     |         
#                  midpoint
#  if list[midpoint] < target:
#
#  list[4] | 1 2 3 4 |
#              |
#            midpoint
#
#  else list[5] | 6 7 8 9 10 15 |
#                     |
#                   midpoint
def verify_binary_search(target):
	if target is not None:
		print("Found target at:", target)
	else:
		print("Did not find target")

numbers = [1,3,4,5,6,7,8,10,33,45]

target = binary_search(numbers, 45)
verify_binary_search(target)
