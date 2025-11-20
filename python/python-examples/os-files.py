# open parameters take the path and the mode
# where the mode is read, write, append etc
# with handles clean up if an exception occurs
# usually paired with as 
# with method() as object:

with open('notes.txt', 'r') as f:
	# f is the object and read() is the method
	print(f.read())
