#!/usr/bin/env python3

hexNumbers = {
    '0': 0, '1': 1, '2': 2, '3': 3, '4': 4, '5': 5, '6': 6, '7': 7, '8': 8,
	'9': 9, 'A': 10, 'B': 11, 'C': 12, 'D': 13, 'E': 14, 'F': 15
}

def hexToDec(hexNum):

	if len(hexNum) > 3:
		print(f'{hexNum} is to long')
		return None
	
	results = 0
	for i in hexNum:
		if i not in hexNumbers:
			return None
		else:
	return int(results)
