
# open parameters take the path and the mode
# where the mode is read, write, append etc

with open('notes.txt', 'r') as f:
	print(f.read())
