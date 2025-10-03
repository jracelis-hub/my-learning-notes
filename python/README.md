# Python

- [Data Types](#data-types)
	- [Data Structures](#data-structures)
- [Operations](#operations)
- [Control Flow](#control-flow)
- [Functions](#functions)
	- [Packages and Modules](#packages-and-modules)
	- [Lambda Functions](#lambda-functions)
	- [Try Except](#try-except)
	- [Packages and Modules](#packages-and-modules)
- [Class and Objects](#class-and-objects)
- [Strings](#strings)

Python is an interpreted language that supports many fields of software engineering:
- Data
- Scripting
- Machine Learning

```bash
# old version python 2
python --version

# newest version python 3
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
- double quotes "string"

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

### Data Structures

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
- Unordered 
- Set is subscriptable can not get index of a set `set[0]`
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

## Control Flow

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

functions can also take preset values so it does not have to be passing everytime
```python3
def performOperations(num1, num2, operation='sum'):
	if operation == 'sum':
		return num1 + num2
	if operation == 'multiply':
		return num1 * num2

performOperations(2, 3)
5

# Notice the 3rd parameter did not have to be passed
# it was implicitly declared but if another operation wants
# to be performed just pass in another parameter
performOperation(2, 3, multiply)
6
```

There are two types of positional arguments
- positional arguments
- keyword arguments

Positional arguments have to be in a specific order take `performOperations(2, 3)` as an example

Keyword arguments can be in any order AFTER positional arguments and passed in with the key and value
- `key='value'`

To create a variety of position arguments
```python3
performOperations(*args)
```
To create a variety of keyword arguments
```python3
performOperations(*args, **kwargs)
# kwargs - keywork arguments
```

### Variable Scope

To find the scope of variables there are two built-in functions called:
- `locals()`
- `global()`

Local scope is visible within the function itself
```python3
def localFunctions(varA, varB)
	print(locals())

localFunctions(1, 2)
{'varA': 1, 'varB': 2}
```

But if you create a variable outside of the function it is known as a global variable

```python3
# This is global variable and can be see in all functions
message = 'Hello World'

def localFunctions(varA, varB)
	print(message)
	print(locals())

localFunctions(1, 2)
Hello World
{'varA': 1, 'varB': 2}
```

### Lambda Functions

Convenient way to write "mini functions" as values

Example:
```python3
(lambda x: x + 3)(5)
# x is the defined variable argument and (5) is the parameter being
# passed in for that argument

myList = [{'num': 3}, {'num': 3}, {'num': 3}]
sorted(myList, key=lambda x: x['num'])
```

### Try Except

Try and except is used to catch specific errors that is known to happen
```
# note you cannot divide by 0
# so an error will occur
def causeError():
	try:
		return 1/0
	except Exception as e:
		return e

causeError()
ZeroDivisionError('division by zero')
```

### Packages and Modules

A package contains submodule(s) and a `__init__.py` file

A module is just a single `.py` file

To load a specific module in it uses the keyword `import`
```python3
import time

# This imports the whole time module so it is 
# visible to the current file being worked on
```
To load a specific function from a specific module do
```python3
from time import sleep
# this only brings visibility to the sleep function that
# is in the time.py file
```

To load a package
```python3
import OpenSSL._util
```
This imports the specific submodule `_util` from the folder called OpenSSL

To then get a specific function from that submodule
```python3
from OpenSSL._util import path_bytes
```

- `OpenSSL._util` = submodule
- `path_bytes` = function in that submodule

> [!NOTE]
> This package is found in /usr/lib/python3/dist-packages/OpenSSL

## Class and Objects

Classes is a way to keep functions and attributes organized under a specific object

Classes:
- instances = objects
- functions = methods
- parameters = attributes

To create class it requires the keyword `class` followed by the class
```python3
class Dog:
	# The underscore is notation to tell the user that it is
	# static and change at your own risk
	_legs = 4 # this is called a class variable as it is the same through out
	          # all objects that are created

	# When creating the Dog class it requires one parameter
	# the parameter is name
	def __init__(self, name):
		self.name = name # this is called an instance variable as it changes per
		                 # object created
	
	# self is reference to the variable assigned for the class
	# myDog = Dog(Jarron)
	# where myDog is the self parameter getting passed into
	# the function
	def speak(self):
		print(self.name + 'says: Bark!')

# my_dog is an instance of the class Dog
my_dog = Dog('Jarron')
my_dog.speak()
```

So when it it says self the instance is implicitly getting passed in as a parameter

For example:
```python3
my_dog = Dog('Jarron')
# indirectly what is happening is
# Dog(my_dog, 'Jarron')
```

Another name of these instances are called Objects which gets into Object Oriented Programming (`OOP`)

To create static methods inside of a `class`

```python3
class WordSet:
	replacePuncs = ['!', '.', ',', '\'']	

	def __init__(self):
		self.words = set()
	
	# Now calling the method .cleanText it utilizes the class WordSet object
	# rather than the self, this method not works with any thing that is a WordSet
	def addText(self, text): # this would be call an instance method, method that belongs to a specific instance of a class
		text = self.cleanText(text) # the static decorator lets you know that self does not need to be passed into clean
		for word in text.split():
			self.words.add(word)

	# Notice this method does not have a self argument even though it is inside the class object
	# since there is no use for self. it is not passed in this is called a "static" method
	@staticmethods # <--- this is called a decorator - which defines special attr or information about the function
	def clean(text): 
		# chaining functions
		for punc in WordSet.replacePuncs:
			text = text.replace(punc, '')
		return text.lower()

```

Inheritance

To define an inheritance use the name of the `class` as follows:
```
class Dog:
	_legs = 4 

	def __init__(self, name):
		self.name = name 
		                
	
	def speak(self):
		print(self.name + 'says: Bark!')

# Chihuahua is the inheritance class of the Dog class
class Chihuahua(Dog): 
	def speak(self):
		print(f'{self.name} says: Yap yap yap!')
# if any methods conflict with the parent method the 
# child method of be used instead
	def wagTail(self):
		print('Vigorous wagging!')
```

Lets say you want to extend the properties of a built in class

Take the class `list()` for example, you can extend the class to create specific properties
```
class UniqueList(list):
	
	# If you want to create the UniqueList to have its own constructor
	# use __init__ as usual but its important that it over writes the constructor
	# from list to make sure that also gets initialized use the key word super
	def __init__(self):
		super().__init__() # this inits the constructor of the parent class (list)
		self.someProperty = 'Unique List!' # then it does the constructor for UniqueList
	
	def append(self, item):
		if item in self:
			return
		super().append(item) # the super() makes sure it is using the list.append() and not 
		                     # the append created 

```

python has built-in classes like:
- int
- float
- bool
- string

Boolean Logic
- Any number that is non-zero is True
- Any number that is zero is False
- Any string is True bool(`'False'`) is True
- Any empty tring is false bool(`''`) is False
- The keywork `None` bool(`None`) is False

Bool can work with any thing even empty lists`[]`, dicts`{}`, and tuples`()`... etc.

```python3
something = False

if not something:
	print('If something is false it will print this')
else:
	print('If something is true it will print this')

# Output
If something is false it will print this
```

Means if `not` false then do something else do the other

When using if `not` logic the first condition is evaluated with not 

## Strings

String manipulation can be seen as each character in a string is an index in an array

Example:
```python3
name = 'Jarron Racelis'
name[0]
# Output
J
```

To get a range of characters in a string use:
- `name[0:7]`
The name will list out the list of characters from index 0 and up to index 7

The colon `:` represents a range...
- `[:7]` is the same as `[0:7]`
- `[7:]` goes from index 7 to the end of the string

Formatting Strings

- 'My number is: '+str(5) <- this is typecasting the value into a string
- f'My number is: {5}' <- this is using formatting string as getting the same output
- 'Pi is: {}'.format(path.pi) where the `{}` location is being formatted 

To use multi-line strings can be denoted with 3 `"""` followed by another 3 `"""`

```python3
multi_string_line = """
This is multi
string line
with newlines in it
"""

multi_string_line

"\nThis is multi\nstring line\n with newlines in it"
```

### Lists

Slicing Lists is getting each individual index in a list `list[0]`

This can work with lists `[]` as well
```python3
my_list = [1, 2, 3, 5]

my_list[:3]

# Output
[1, 2, 3]
```

For slicing there can be another parameters passed in when trying to get indexes in a List

`my_list[:3:2]` - this starts from 0 to 3 incrementing every 2 indexes

```python3
my_list = [1, 3, 5, 10, 33, 55]
my_list[::2]

# Output
[1, 5, 33]
# Notice it skips every two
```

If 3rd parameter is a negative value it will increment backwards
```python3
my_list = [1, 3, 5, 10, 33, 55]
my_list[::-1]

# Output
[55, 33, 10, 5, 3, 1]
```

Sets

```python
mySet = {1, 3, 4, 5}
```

To manipulate sets using the following methods
- `.add(value)` to add to the end of a set
- `.pop()` to remove from the set
- `.discard(value)` to remove a specific value from a set

Tuples

```python
myTuples = (1, 3, 4, 10)
```

- Have an order
- Can not be modified

when returning multiple comma seperated items it is a tuple
```python3
def returnTuples:
	return 1, 2, 3

a, b, c = returnTuples()
print(a)
1
print(b)
2
print(c)
3
```

Dictionaries (Dict)

To create a dictionary it requires a key + a value
```python
cars = {
	'b': 'bmw',
	't': 'tesla',
}

# To get the value at that specific key
cars['b']
bmw

# To get keys in the dict cars
cars.keys()
dict_keys(['b', 't'])

# To get values in the dict cars
cars.values()
dict_keys(['bmw', 'tesla'])
```

Dict can hold a list as a value for each key
```python3
cars = {
	'b': ['bmw', 'boom'],
	't': ['tesla'],
}

# To add into the list 
cars['b'].append('bam')

# Not if the key does not exist an error occur
if 'c' not in cars:
	cars['c'] = []

cars['c'].append('cruiser')
```

Or Could use the default dict library by importing it
```python3
from collections import defaultdict

# The argument passing in has to be a specific data structure
cars = defaultdict(list)

cars['m'].append('mercedes')
```

