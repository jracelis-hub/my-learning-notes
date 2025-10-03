# C++

## C++ Keywords

The `::` scope resolution operator tells exacly which scope a name belongs to

```
std::cout
```
Belongs to the std namespace

Data Types:
- int - whole numbers
	- hex `0x3A`
	- binary `0b1100`
	- unsigned `23U`
- char (8 bits 1 Byte) - represent charcters (ASCII) can be small numbers too
	- `'a'`
- float - represents decimal point values lower percision
	- `23.0f`
- double - double percision of floating point numbers
	- without trailing f `13.3`
- bool - true or false
- void - no data type
- pointer - hold addresses

Specifiers:
- signed
- unsigned
- long

Use the following to have a compatilble data:
- `stdint.h` 
- `cstdint`

Qualifers:
- const - value can not change
- static 
	- for local variables it extends their life to entire duration of the program, rather than just the function's execution
	- static functions
- volatile - tells compiler that varaible's value may change at any time
- mutable - allows a member of an object to be modified even if the object is declared as a `const`
- inline - a hint t othe compiler to generate a copy of the function's code at each point where the efunction is called rather than
generating a normal function call
- constexpr - to indicate that the value of a variable or the result of a function can be evaluated at compile time

Conditional:
- if 
- else
- else if
- switch
- case
- default

Classes:
- struct
- class
- public
- priviate
- protected
- virtual

Iteration:
- for
- while
- do

Memory allocation:
- new
- delete

Directives:
- namespace

Other:
- throw
- nullptr
- using
- try
- catch

`iostream`

* std::cout - character out `<<`
* std::cin - character in `>>`
* std::endl - end line(`\n`) 
* std::flush - makes sure the output is completely sent onto the terminal

Example:
```c++
#include <iostream>
#include <string>

int main() 
{
	std::string prompt = "Enter a number: ";
	std::cout << prompt << std::flush;
	std::cin >> number;
	std::cout << "My number is: " << number << std::endl;
	std::cout << "Hello World" << std::endl;
}
```

Variable Aliases 

`typedef` - is to alias a data type with a given variable name

Example:
```c++
typedef long int Score;

Score team = 0;
```

`using` - introduced in C++, same as typedef
- Support template aliases
- Preferred over typedef for clarity
Example:
```c++
using Score = unsigned long;
```

Difference in syntax and readability
```c++
typedef struct GameCharacter* (*CharacterCreator)(int);

using CharacterCreator = struct GameCharacter* (*)(int)
```

Enumeration - enums are just a way of providing a name to a integer

```c++
enum colors {
	red, /* this = 0 */
	blue, /* this = 1 */
	green, /* this = 2 */
	yellow = 10 /* you can also set the value */
};

int main() 
{
	int color = red; /* color = 0 */
}
```

In c++ there is a enum class `variable` name which is called a `Strongly Typed`
```c++
enum class rgb {
	red,
	blue,
	green,
	yellow
};

int main() 
{
	int color = rgb::red; /* this will cause an error as red 
	                    belongs to a specific class (rbg) */
	/* Two ways to fix this */
	/* 1st way by typecasting it */
	int color = (int) rgb::red;
	/* 2nd way by declaring it */
	rgb color = rbg::red;
}
```

Typecasting

- specifying how to interpret a piece of data
- useful for converting data types
Example:
```c++
/* C version */
(float)(expression)

/* c++ */
static_cast<float>(expression)
```

the `auto` keyword assigns the declared values based on the values provided
```c++
auto score = 8; /* Implicilty assign it to be int */
auto height = 5.6f; /* Impliicility assign it to be a float */
auto first_letter = 'f'; /* Implicility assign it to be a char */

/* to get the type of id use typeid */
```

## Preprocessor Directives

- hash directive - `#include <iostream>` - looks in predefined location

## Pointers

NULL vs nullptr: legacy and modern C++

nullptr is type safety

NULL is just a int value of 0

To create pointers in C++ it uses the `new` keyword to dynamically allocate memory
Example:
```c++
# Dog
Dog *my_dog = new Dog();
/* this create a pointer object Dog called my_dog and the Dog()
   is constructor for the Dog class */

/* To free the allocated memory use the delete keyword to free the pointer */
delete my_dog;
```

### References

- Aliases to existing variables: `int&` my_ref = my_int;
- Uses the same syntax as the references variable
- References are not pointers
- References are not objects or variables
- There are no arrays of references
- There are no pointers to references
- There are no references to references

## Strings

- Not a native type in the language
- In C, strings are arrays of characters (char)
- The `std::array` class comess with the C++ library

> [!NOTE]
> References must be initialized at declaration

Uses the `<string>` library

```c++
#include <iostream>
#include <string>

int main()
{
	std::string first_name = "Jarron";
	std::string last_name = "Racelis";
	/* This is called overload which during runtime it changes based
	 * on the parameter that it takes in                          */
	std::string firstLast = first_name + last_name;

	std::cout << "First name " << first_name << std::endl;
	std::cout << "Last name " << last_name << std::endl;
	std::cout << "Full name " << firstLast << std::endl;

	return 0;
}
```

## Standard Template Library (STL) Vectors

Dynamic size containers
- the memory is managed for you
- Generic container class (can store any type of data)
- Part of the Standard Template Library
- Found in the vector header `#include <vector>`
- they are stored consecutively in memory like arrays
- stored on heap managed internally
- can only insert at the end
- supports [] notation to get the value like arrays

```c++
#include <vector>
#include <string>
#include <iostream>

int main() 
{
	/* std::vector class type <> 
	 * defines the type of data it is holding
	 * std::string class type
	 * checkpoints variable name
	 * {} are the items stored into the dynamic array
	 */
	std::vector<std::string> checkpoints = {"Start", "Forest", "Castle"};

	checkpoints.push_back("Cave");
	checkpoints.push_back("Finish");

	std::cout << "The game has " << checkpoints.size() << " checkpoints." << endl;

	return 0;
}
```

## Templates

`<>` when using these with variables `duration<double>` the `<>` are called a template
