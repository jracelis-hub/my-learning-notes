#!/usr/bin/env python3

def open_file() -> None:
	"""
	Get input from user
	"""
	path: str = input("Enter path of file: ")
	mode: str = input("Enter file mode: ")

	file_mode = ('r', 'w', 'a')
	if mode not in file_mode:
		raise ValueError(f"Input {mode} is not a valid mode")
	with open(path, mode) as file:
		if 'r' in mode:
			print(file.read())
		elif 'w' in mode:
			file_info = input("> ")
			file.write(file_info)

open_file()
