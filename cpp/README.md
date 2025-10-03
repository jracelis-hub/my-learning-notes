# C++

## C++ Keywords

The `::` scope resolution operator tells exacly which scope a name belongs to
- For built-in classes `std::vector`
- For user defined classes in source code `Dog::getDog()`;

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
- public - only thing can access it (no strict)
- priviate - only the class that declares it can access it (most strict)
- protected - only the class and any derived class can access it (medium strict)
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

## Functions

A function consists of a return type, name, parameter list, and function body
```
int nameFunc(int parm1, char parm2) 
{
	int body = 2;
	if ( parm2 == 'B') {
		return parm1 + body;
	}

	return parm1 + body;

}
```

Function Signature
- A function's unique identifier
- Consits of the function's name and its parameter types
- The return type is not part of the signature
- The signature must be unique within its scope

Function Declaration vs Definition
- Declaration (prototpe): introduces the function to the compiler
```c++
double calculateDistance2D(double x, double y);
```
- Definition: contains the implementation
```c++
double calculateDistance2D(double x, double y)
{
	return x + y;
}
```
Function Prototype
- Prototypes are function declarations without the body
- Prototypes are often in header files `.h` or `.hpp`

3 Types of Ways to Define Parameters
1. Pass by value
```c++
int passValue(int x, int y)
{
	return x + y;
}
```
2. Pass by address
- Needs to dereference
```c++
void passValue(int x, int y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}
```
3. Pass by reference
- Does not need to dereference
```c++
void passValue(int& x, int& y)
{
	int temp = x;
	x = y;
	y = temp;
}
```

Returning Values from a Function
- Return built-in types: simple and direct (`int`) (`float`)
- Return pointers: use for dynamic memory
- Return references: provides direct access
- Return void: does not need to return anything

Returning a pointer
```c++
Weapon* createWeapon(const std::string& name) 
{
	/* Passes the string argument name in to be used when
	 * allocating memory and returning the address     */
	Weapon* weapon_x = new Weapon(name);
	return weapon_x;
}
```

Returning Reference
```c++
Player& findTopScorer(std::vector<Player>& players)
{
	auto topScored = players.begin();
	for (auto& player : players) {
		if (player.score > topScorer->score) {
			topScorer = &player;
		}
	}
	return *topScorer
}
```

### Function Overloading

Function overloading is the process to have multiple variations of a function
based on the arugments passed into the function to give a different output
```c++
int getSpeed(int speed, int multiplier)
{
	return speed * multipler;
}

double getSpeed(int speed, int multiplier)
{
	return static_cast<double>(speed * multipler);
}
```

> [!NOTE]
> This feature is only available in C++ and not in C

Notice based on the parameters they return different values. This is called overloading.

Function Parameters

Function parameters can come with default values. It is important to note that values
that are provided with default arugments need to have a proper format
```c++
/* Default value type */
void createZombie(const std::string& name = "Zombie", int health = 100);

int main()
{
	/* Creating a zombie with the default name of Zombie
	 * and default health 100                         */
	createZombie();
	/* Passing a string value of Jarron with default value
	 * health of 100                                   */
	createZombie("Jarron");
	/* It is important to note that the order of how the parameters
	   are given will affect the feasibility of providing default values
	   for isntance the follow can not be done                      */
	createZombie(150);
	/* The Zombie name will not be populated and will cause an error */
}
```

When doing default argument parameters the first value has to be initialize and everything to the right of it
will be "defaulted" but if the first value is not initialized and the 2nd argument is passed in it will cause an
error.

### Operator Overload

In C++ not only can you overload functions but you can also do overload on operator overload

Think of the `+` for the `std::string` stl
```c++
#include <string>

std::string firstName = "Jarron";
std::string lastName = "Racelis";
std::string fullName = firstName + lastName;
```

Overload operators can be unary(1), binary(2), or ternary(3) opperands
- All operators must return a value compared to function which my return `void`

For instance
```
class Numbers {
	/* if a function is returning a void the do the following */
	void addNumber(int index);
	/* the operator of what is above is the class name plus operatory */
	Numbers& operator+=(int index);
	/* To return a value do the following */
	int operator+=(int index);
};
```

## Class

A class is a "blueprint" of creating objects

Objects are instances of a class
```c++
Dog *my_dog = new Dog();
/* my_dog is the object instance of the class Dog */
```
Classes have data and functions members
- A data member holds the state of that object
	- A data member is also known as attributes
- A function members methods that define the objects behavior
	- Operate on data members
	- A function member is also known as a method

Members can be `public`,`private`, or `protected`
- public - can be access anyway in the program
- private - can only be access within the class itself
- protected - can only be accessed by derived classes
	- inheritance
	- polymorphism

Encapsulation allows to group a objects state and behavior together, while controlling 
access to that state through well define interfaces

Contructors and Destructors
- Constructors initialize objects
- Constructors can be overloaded
	- different sets of parameters
- Destructors clean up resources
	- memory (heap)
	- file handles (fd)
- Desctructors are called automatically when a object is destoryed
	- either by going out of scope (stack)
	- or being `delete` (heap)

The is also a short had notation for constructors called a member initilizer list
- After the parameter list add a `:` of initilizers seperated by `,`
```c++
class Zombie {
public:
	/* These are the same */
	Zombie() {
		health = 0;
		name = "Zombie";
	}

	/* Different notation */
	Zombie(): health(10) {
		name = "Zombie";	
	}

private:
	int health;
	std::string name;
}
```


Objects can be creating on the stack or on the heap
```c++
/* Zombie is the class 
 * zombie is the object (instance) that is is creating */

/* This is allocating space on the heap by using malloc */
Zombie *zombie = new Zombie();
/* It is important to delete(free) the zombie or memory leak will occur */
delete zombie 

/* Or using destructor */
zombie->~Zombie();

/* This is just on the stack */
Zombie zombie = Zombie();
```
Destructors are used when you create it on the heap

## Headers

For headers it is similar to C but there are some underlying differences such as `class`.

```c++
#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>
#include <iostream>
#include <vector>
#include <alogrithm>

class Inventory {
public:
	/* Constructor */
	Inventory();

	/* Overload Constructor */
	Inventory(int capacity);
	
	~Inventory();

	std::string getItem(int index);

private:
	std::vector<std::string> *items;
	int capacity;
};

#endif /* INVENTORY_H */
```

But in the source file
```c++
#include "inventory.h"

/* The class does not have to mentioned in this just the definitions 
   but the Inventory:: has to be included for each time it is used inside
   the class                                                           */

   Inventory::Inventory(): capacity(10) {
		items = new std::vector<std::string>();	
   }

   std::string Inventory::getItems(int index) {
		/* Code goes here */
   }

   Inventory::~Inventory(){
		delete items;
   }
```

### Inheritance

Inheritance is create of a sub class under already existing class to create modular design

Often called the derived class, and inherits the attributes and behaviors (data members and function members) of another class
called the base class

It is a way of categorizing objects reflecting the real-world heiarchies as an example

- A weapon is a item
- A piece of ammo is an item
- Some items are values

For the subclass
- a bandage a type of aid and aid is an item therefore, a bandage is an item
- an arrow a type of ammo and ammo is an item therefore, an arrow is an item

The hiearchy tiers is shown in the following
```
                     base class
                   class Person
				     protected
				         |
               ----------------------
               |                    |
               |                    |
               |                    |
           dervied class        dervied class
           class Father        class Mother
		     private              private
			   |                    |
			   |                    |
          class Son           class Daughter
```

| Hierarchy |       |       |
|:---:|:---:|:---:|
|class | Public | Protect | Private|
|Person| yes | yes(father, mother, son, daughter) | yes (themselves) |
|father| no  | yes(son) and themself | yes (themselves)
|son | no  | yes themself | yes (themselves)

### Polymorphism

Polmorphism allows to use a single interface to be represented different underlying data
types in C++

It uses the keyword `virtual` in the base class

Then anything derived can override the function to provide specific behavior during runtime base on the
actual object type

Overriding is a function means of providing a new implementation for base class function within a 
derived class

> [!IMPORTANT]
> Overriding is the not that same as overloading which invloves functions with the same name but different parameter lists

To override a function in a derived class use the keyword `override`
```c++
class Aid : public Item{
public:
	void use() const override{

		/* Code stuff */
	}
};
```

And in the base class `item` the `virual` keyword to know that it can be `override`
```c++
class Item {
public:
	virtual void use() const{

		/* Code stuff */
	}
};
```

To create a "pure virtual function" do the following:
```c++
virtual void use() const = 0;
```
This is making it a pure virtual class which each class implement specific behavior
Ensuring their own unique implementation

- Inheritance for "is-a" relationship
- Polymorphism for flexibility
