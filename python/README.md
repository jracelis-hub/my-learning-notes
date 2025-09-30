# Python

Python is an interpreted language that supports many fields of software engineering:
- Data
- Scripting
- Machine Learning

```bash
python --version
python3 --version

Python 3.12.3
```

## Data Types

Variables - the name that is associated with the value
- Don't use variables with upper case letters (used for `Class`)

Data type - type of data the computer is representing

Data Type

Numbers - numbers representation of a variable
- int - whole numbers (1, 3, 4)
- float - decimial numbers (3.14, 7.99, 2.32)
- complex - complex numbers 2j

String - array of characters that represents a word(s)/sentence(s)
- single quotes 'string'
- doulbe quotes "string"

Bool - binary value representation 0 (False) or 1 (True)
```python3
# Statement
if 1 == 1: # <--- this will return true 1
	print("True")
else:
	print("False")
if 1 == 2: # <--- this will return false
```

To see what data type of variable use `type()` and the variable name inside the `type(variableName)`

```python
#!/usr/bin/env python3

name = "Jarron Racelis"

print(type(name))
<class 'str'>
```

Data Structures

List - is a dynamic array that is able to hold any type of data type
- Represent with brackets `[]`
- Since dynamic python interpret primitively allocates space for list

Example:
```python3
my_list = [1, 3, 4, 5]
print(my_list)
my_list = [1, "Jarron Racelis, 3.14, True]
```

To get the length (sizeof) a list use the builtin `len()` function
```
print(len(my_list))

4
```

The order of a list matters 
```python3
[1, 2] == [1, 2] -> true

[1, 2] == [1, 2] -> false
```

> [!NOTE]
> In python List is an array that can hold any type of data compared to other data structures in other languages

Set - is the same as a list but all the items have to be unique
- Represented with curly brackets `{}`
- If the item has duplicate values it will represent the duplicate values as one value

Example:
```python3
my_set = {1, 4, 55, "Jarron"}
print(my_set)

# Output
{1, 4, 55, "Jarron"}

# if duplicate values
my_dup_set = {1, 1, 2, 2, 3}
print(my_dup_set)
print("Length = %d" % len(my_dup_set))

# Output
{1, 2, 3}
Length = 3
```

Order does not matter in sets
```python3
{1, 2, 3} == {1, 3, 2} # <-- true
```

Tuples - can be see as static and immutable arrays meaning once the values are declared it can not change
- Represented with `()`
- Can not add/change the values in the tuple
- Memory efficient

> [!WARNING]
> Since tuple can hold other data structures like list... etc those values and change inside

```python3
my_tuple = (1, 3, 44, 56)
my_tuple.append(5)

# This will cause an error
my_list = [1, 2, 3]
my_tuple = (my_list, 44)
my_list.append(55)
```

Dictionaries - stores a collection of key-value pairs
- Represented with `{}`

```python3
my_dictionary = {
	'key_1': 'Value pair 1',
	'key_2': 'Value pair 1',
	'key_1': 'Value duplicate'
}

print(my_dictionary['key_1'])
Value duplicate
```

## Operators

Arithmetic Operators 

- Subtraction `-`
- Addition `+`
- Division `/`
- Multiplication `*`
- Exponent `**`
- Modulo `%` - remainder after division

```python3
16 % 5
# 16 / 5 = 15 with a remainder of 1
# Output
1
```

String concatenation
```python3
first_name = "Jarron"
last_name = "Racelis"
full_name = first_name + last_name
print(full_name)
JarronRacelis
```

Comparison Operators

- Less than `<`
- Less than or equal to `<=`
- Greater than `>`
- Greater than or equal to `>=`
- Equal to `==`
- Not equal to `!=`

Logical Operators

- `and` is like `&&` in C
	- Both have to evaluate True True or False False
- `or` is like `||` in C
	- One has to be True
- `not` flips the operations 
	- True -> false

Membership Operators

```
1 in [1, 2, 3, 4]
True
# True because it is included

1 in [2, 4, 5, 10]
False
# False because it is not included
# can do the following

my_string = 'hi jarron'
'jarron' in my_string
true
```

Control Flow

Control flow statements are represented with a `:` after the statement and anything
under that control flow statement has to be indented

If Statements

Think of it as `if bool:` do something else do the other
- Where bool is a True or False
	- True is any value that is non-zero
	- False is any value that is zero or empty string

```python3
a = True

if a:
	print('Hello')
else:
	print('False')
```

For Statements

For loops iterate until the end of an iterable
- iterable is a list for an example

```
list = [1, 3, 5]

# item is a place holder for each element in the list

for item in list:
	print(item)
# What is does is 
# print(item[0])
# print(item[1])
# print(item[2])
# Until the list is reached at the end
```

While Statements

While loops iterates until the condition returns True or False depending the condition
```python3
while a < 3:
	a++
	print('Hello')
```

## Functions

To create a function in python it starts with the keyword `def`
	- keyword `def`
	- functionName()
	- (arguments)
	- `:`
	- indentation for everything that applies to that function
```python3
# This does not return any value
def functionName(arguments):
	print('Hello In Functuon')	

def returnValue(argument):
	return 3 * argument
```

In order to hold that return value just create a variable to hold the return value
```python3
def functionMultipleByThree(value):
	return 3 * value

value = 5

# Calling the function
new_value = functionMultipleByThree(value)
print(new_value)

# Output
15
```

## Class and Objects

Classes is a way to keep functions and attributes organized under a specific object

To create class it requires the keyword `class` followed by the class
```python3
class Dog:
```
