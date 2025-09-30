#!/usr/bin/env python3

# This is a list of methods that can be used on lists
# methods is a function for that specific class/object

# Create a list
my_list = [3, "Jarron", True, 5, 3.12]

# To get length of a list (quantity in that list)
print("Printing originial list")
print(my_list)
my_list_len = len(my_list)

# To add an element to the end of a list use method .append
my_list.append("Racelis")
print("Using Method: append()")
print(my_list)

# To copy a list into another list use method .copy()
print("Using Method: copy()")
another_list = my_list.copy()
print(another_list)

print("Using Method: extend()")
my_list.extend(another_list)
print(my_list)

# Counts the amount of duplicated values within the list 
print("Using Method: count()")
count = my_list.count("Jarron")
print("The count of Jarron = %d" % count)

# To remove all elements in the list use method .clear()
my_list.clear()
print(my_list)

