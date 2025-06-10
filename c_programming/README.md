# C Programming 

## Table Of Contents
* [_Introduction_](#introduction)
	* [_Terminology_](#terminology)
    * [_Error Types_](#error-types)
    * [_Build Process_](#build-process)
    * [_Files_](#files)
	* [_Memory Types_](#memory-types)
		* [_Memory Architecture_](#memory-architecture)
* [_Syntax and Semantics_](#syntax-and-semantics)
    * [_C Source Format_](#c-source-format)
    * [_Preprocessor_](#preprocessor)
        * [_Header Files_](#header-files)
* [_C Basics_](#c-basics)
	* [_Data Types_](#data-types)
        * [_Portability Issues Data Types_](#portability-issues-data-types)
        * [_Conversions_](#conversions)
        * [_Operators_](#operators)
    * [_Variables_](#variables)
        * [_Signed Vs Unsigned Data_](#signed-vs-unsigned-data)
        * [_Storage Sizes_](#storage-sizes)
        * [_IEDD-754 Floating-point Standard_](#iedd-754-floating-point-standard)
        * [_Format Specifiers_](#format-specifiers)
        * [_Type Casting_](#type-casting)
        * [_Escape Sequences_](#escape-sequences)
        * [_Comments_](#comments)
    * [_Strings_](#strings)
	* [_Functions_](#functions)
        * [_Conditional Statements_](#conditional-statements)
        * [_User Input_](#user-input)
* [_Advanced C_](#advanced-c)
    * [_Pointers_](#pointers)
    * [_Structures_](#structures)
* [_Embedded Systems_](#embedded-systems)
    * [_Debuggers_](#debuggers)
    * [_Complication_](#complication)
    * [_Microcontroller_](#microcontroller)
* [_Appendix_](#appendix)

## Introduction

The _C Programming_ language was invented by Dennis Ritche of Bell Laboratoires. He was working on the design of the UNIX operating system.

Purpose of the _C Programming_ language was a tool for working programmers. To be useful language and easier readability and writability. _C Programming_ is to write source code that is `compiled` into _machine code_ that a CPU can understand and execute.

How _C Programming_ interacts with memory is one of the pivotially reasons why it is such a strong language compared to many other langugages. Since it sits in between the middle ground between lower level and high level language, it is a great start to understand how the CPU (central process unit) functions when a program executes. To understand and write _C Programs_ to its fullest potential, knowing how program allocates and utilizes memory will make you a better programmer in the _C Language_.

Knowing where each line of code lies in memory will help read, write and debug code. Undstanding the fundamental concepts of memory allocation gives me a way of visualizing what is happening under the hood of the source code. Which will make you a better and a more efficent programmer.

The different types of _C Standards_ are:

1. C89/C90
2. C99
3. C11

### Terminology

**Defintion** - Declares and allocates memory for a variable or provides the implementation for a function

**Declaration** - Introduces the name and type of a variable or function to compiler without allocating memory.

***Two Types of Declarations:***

**Variable Declaration** - specifies the type and name of variable.

**Function Declaration (Function Prototype)** - specifies functions return type, name, and parameters without the function body.

**Initialization** - Assigns a value to a variable or data struture.

**Parameter** - Are required variable data types to be passed into a function definition.

***Two Types of Methods For Passing in Arguments:***

**Call by Value** - The method of pass the actual data arguments into the function.

**Call by Reference** - The method of passing the address of a variable (`*pointers`) argument into the function.

**Argument** - The actual data of the set parameters being passed into a function.

**Buffer** - is temporary storage area in memory used to hold data while it is being trasnfered from one place to another.

**Operators** - symbols that represent some kind of operation to be preformed (ex. `+`, `-`, `*`, `/`, `%`, `++`, `--`)

```c
10 + 5;     /* The + symbol is the operator */
```

**Operands** - values or variables in which the **operators** are preforming on.

```c
10 + 5;     /* The 10 and the 5 are opperands */
```

**Expressions** - combination of operators and operands that are evaluated and produces a value.

```c
x = 10 + 5;     /* Using operators and operands which is evaluated is an expression */
```

### Error Types

* Linker Errors
* Runtime Errors
* Logic Errors
* Semantics Error
* Syntax Error
* Buffer Overflow
* Segment Fault

### Build Process

* Editing - Code written in the human readable form following proper syntax for machine code.
    * Source code `.c`
* Compiling - Converts source code into machine language and detects any reports and errors. Ensuring structural errors and syntax errors.
    * First Phase:
        * Preprocessing `.i` for every `.h` file
        * Parsing 
* Assembler
    * Second Stage:
        * Creates assembly code file(s) `.s` 
* Linking - To get the progrom into a final form for execution on the computer. Linking errors when trying to pull from a library that does not exist for reference.
    * Linking object file(s) `.s` -> Linux `.o` or Windows `.obj`
    * Linking Static Libraries `.lib` & `.a`
    * Producing final executable
* Executing
    * Post processing of final executable Windows `.exe` or Linux `.out`

Example work flow:
```
main.c (text) ---> (pre-processing stage) ---> main.i (text)

main.i (text) ---> (code generation stage) ---> main.s (assembly)

main.s (assembly) ---> (assembler stage) ---> main.o (binary)
```

When compling your source code in c, the following files are produced:

* `main.i`
    * Collection of code and contents of header files.
* `main.s`
    * The assembly code that is written in machine code
* `main.o`
    * The assembly code so now written in binary form

There are many ways to compile you text file in the format of `.c` to a executable (binary) file. One of the main compilers used to compiler c programs is ***GCC*** or also known as, ***GNU Compiler Collection***. This compiler was created by the GNU Project. The other compilers that could be used in ***clang*** and ***MinGW*** and many more others. 

> [!NOTE]
>  Each compiler is depended on the system and target you're trying to compile on.

### Files

**File Types**:

* Assembly Files `.s` - mnemonics instructions generated from all the `.c` statements
* Static Libraries `.a` -
* Shared Libraries `.so` -
* Object Files `.o` or `.obj` - machine code
* C File `.c` - the source code the programmer writes following the _C Programming_ syntax
* Header Files `.h` - where the preprocessor directives are
* Linker Script `.ld` -
* Executable and Linkable Format `.elf` - used for debugging
* Binary Files `.bin` - final form of the executable
* Intel HEX file `.hex` - final form of the executable

**File Tree**:

**Include (inc)** - this is where header files are located

**Source (src)** - this is where source code is located

**Startup** - needed for the micro controller

### Memory Types

Programs store the instructions in memory **(RAM)**

***The many key memory concepts are as followed:***

**Text Segment** - This is also known as the _code segment_ where the executable code of the program is stored. Contains compiled machine code of the program's functions and instructions. This segment is in **read-only** mode to prevent modification during execution.

* Compiled instructions
* Functions and code logic

**Initialized Data Segment (.data)** - Hold global and static variables that are explicitly initalized.

* Global Variables
* Static Variables

```c
extern int globalVariable = 10;
```

**Uninitialized Data Segment (.bss) (Block Started by Symbol)** - Holds global and static variables that are declared but not initialized. These operating system intialize these as zero before program starts.

* Uninitialized Global Variables
* Uninitialized Static Variables

```c
extern int globalVariable;
```

**Heap Segment** - Used for **dynamic memory** allocation during a program execution. Functions like `malloc()`, `calloc()`, `realloc()` and `free()` manages these memory segements.

* `Malloc` (memory allocation)
* `Realloc` (reallocation)
* `Calloc` (contiguous allocation)
* `Free` (frees allocated memory)

```c
int *ptr = (int *)malloc(sizeof(int)*5);
```

> [!CAUTION] 
> If the dynamic memory is not freed then a `memory leak` will occur.

**Stack Segment** - Manages function calls, local variables, and control flow. When a function call occurs a new stack frame containing its local variables and return adddress.

* Local Variables
* Control Flow
* Function Calls
* Function Parameters

```c
int localVariable = 10;
```

Visual Representation of Memory Layout in C
``` 
                                +---------------------------+ high address
                                |   Command Line Arguments  |
                                |---------------------------|
                                |           Stack           |---------+
                                |---------------------------|         |                 
                                |             |             |         |                 
                                |             |             |         |                 
                                |            \|/            |         |     +-----------+
                                |                           |         |     |  Dynamic  |
                                |                           |         |---->|  Memory   |
                                |                           |         |     |  Layout   |
                                |                           |         |     +-----------+
                                |            /|\            |         |     
                                |             |             |         |
                                |             |             |         |                 
                                |---------------------------|         |
                                |            Heap           |---------+
                                |---------------------------|
        +--------+       +------| Uninitialized Data (.bss) |
        | Static |       |      |---------------------------|
        | Memory |<------|      |  Initialized Data (.data) |
        | Layout |       |      |---------------------------|
        +--------+       +------|        Code (.text)       |
                                +---------------------------+ low address
```
Example:
```c
#include <stdio.h>

int number;		/* This is a global variable it is declared outside of a function. And number is implicitly(compiler) set to 0. (Unintialized Data (.bss) */
static age = 3;		/* This is a global variable that is intialized. (Initialized Data Segment .data) */

int main(){

	int number_in_function;		/* This is a local variable because it is declared inside a function. This sits on the (Stack Segment) */
	add_number();		/* This is a function call, and this sits on the (Stack Segment). */

	malloc(sizeof(int example);		/* This is malloc(memory allocation) and this is dynamic memory and sits on the (Heap Segment) */
	return 0;
}
```

**Segment Fault (segfault)** - runtime error that occurs when a program attempts to access a memory location that is not allowed. Like due to improper pointer usage or memory management.

> [!NOTE]
> When you get a segment fault, that means there is issue will how memory addressing is.

Program Example:
```c
#include <stdio.h>		/* Preprocessor directive */

int global_value;		/* Value does not sit inside a function. Declared global variable. */
static int static_value_global;		/* Value is a static and global variable. */

int main(){

	static int static_value_local;
	int local_uninitial_value;
	int local_initial_value = 2;

	printf("\nThis is global_value (value should be 0): %d\n",global_value);		/* Value is unitialized global value. Implicitly (compiler) be 0. */
	printf("This is address global_value: %p\n\n",&global_value);		/* Value is unitialized static global value. */

	printf("This is static_value_global (value should be 0): %d\n",static_value_global);		/* Value is unitialized static global value. Implicitly (compiler) be 0. */
	printf("This is address static_value_global: %p\n\n",&static_value_global);		/* Value is unitialized static global address. */

	printf("This is static_value_local (value should be 0): %d\n",static_value_local);		/* Value is unitialized static global value. Implicitly (compiler) be 0. */
	printf("This is address static_value_local: %p\n\n",&static_value_local);		/* Value is unitialized static local address. */

	printf("This is local_uninitial_value (value should be garbage number): %d\n",local_uninitial_value);		/* Value is uninitial value. Implicitly (compiler) be garbage value. */
	printf("This is address local_uninitial_value: %p\n\n",&local_uninitial_value);		/* Value is uninitial local address. */

	printf("This is local_initial_value (value should be 2): %d\n",local_initial_value);		/* Value is initial local value. Explicitly (programmer) by 2. */
	printf("This is address local_initial_value: %p\n\n",&local_initial_value);		/* Value is initial local address. */

	return 0;
}
```

Output:
```c

This is global_value (value should be 0): 0
This is address global_value: 0x6350fd99b014

This is static_value_global (value should be 0): 0
This is address static_value_global: 0x6350fd99b018

This is static_value_local (value should be 0): 0
This is address static_value_local: 0x6350fd99b01c

This is local_uninitial_value (value should be garbage number): 1330427056
This is address local_uninitial_value: 0x7fff4f4cb3c0

This is local_initial_value (value should be 2): 2
This is address local_initial_value: 0x7fff4f4cb3c4

```

#### Memory Architecture

***Two Types of Memory Architectures:***

**32 bit (4 Byte)** architecture

**64 bit (8 Byte)** architecture

## Syntax and Semantics

### C Source Format

In the made source code consists of proper syntax and semantics to follow to properly compiler and run.

The follow C source code consists of the following items:

- Preprocessor statements
- Data Types
- Parameters
- Variable Declarations
- Variable Definitions
- Function Declartions
- Function Prototypes
- Function `main`
- Body of Function `{}`
- Statement Terminator `;`
- Statements

To understand this I will break down the follow example explaining what each item does in the following code.
```c
#include <stdio.h>      /* This is a Preprocessor statement */

add(int value,int value2);       /* This is called a Function Definition (Prototype) */
/*
 * Where int value; value2 are parameters for the function add();
 */

static int name = 10;        /* This is a Variable Definition since the variable is initialized to 10 */

int main() {        /* int is the data type of the function and main() is where the source code executes its instructions */
    int age;     /* This is a Function Declaration the variable is not yet initialized or memory allocated to it yet */ 
    int num,num2;

    add(num,num2);       /* This is a function call */
    /*
     * Where num and num2 are arguments
     */

    return 0;       /* This is a return type for the data type defined in the function int main() */

}       /* Everything in the { } are statements that need to be executed */
```

### Preprocessor

Preprocessor statements are identified by the presence of a pound sign, `#`, which must be the first non-space character on the line.

The preprocessor can do the following:

* Create are own constants and macros with the `#define` statement
* Build you own library files with the `#include` statement
* Make more powerfule programs with the conditional `#ifdef`, `#endif`, `#else`, and `#ifndef` statements

The `#include` statement is a preprocessor directive

```c
#include <stdio.h>
```

* It is not strictly part of the executable program, however, the program won't work without it.

The symbol `#` indicates this is a preprocessing directive.

* Instruction to your compiler to do something before compiling the source code
* Are usually at the beginning of the program source file, but can be anywhere

It instructs the compiler to `include` in your program the contents of the file.

* Must have `.h` also known as a header file with an extension of `file.h`

```
+------------------------------------------------------------------+
|      #define        |        #error         |       #include     |
|      #elif          |        #if            |       #line        |
|      #else          |        #ifdef         |       #pragma      |
|      #endif         |        #ifndef        |       #undef       |
+------------------------------------------------------------------+
```

#### Header Files

Header files define information about some of the functions that are provided by that file

* `stdio.h` is the standard C library header and provides functionality for displaying output, amount many other.
* `stdio.h` contains the information that the compiler needs to understand what `printf()` means.
* `stdio` stands for standard input/output.

Header files specify information that the compiler uses to integrate any predefined functions within a program.

Two ways to `#include` header files in a program:

* Using angle brakets (`#include <stdio.h>`)
    * Tells the preprocessor to look for the file in one or more standard system directories
    * ex. `/usr/include/`
* Using double quotes (`#include "myheader.h"`)
    * Tells the preprocessor to first look in the current directory.
    * Created usually by the programmer

Header files includes many different things:

* `#define` directives
* `struct` declarations
* `typedef` statements
* `function` prototypes

Examples:
```
 C Libraries
+-------------------------+
|  stdio.h   |  string.h  |
|  stdlib.h  |  ctype.h   |
|  math.h    |  time.h    |
|  stdint.h  |            |
+-------------------------+
```

> [!WARNING]
> Executable code normally goes into a source code file, not a header file.

Example format:
```c
#ifndef NAME_FILE_ /* pre-processor directives */
#define NAME_FILE_

/* function prototypes */

#endif
```

> [!NOTE]
> Include guards `#ifndef` `#define` `#endif` prevent the inclusion of header files multiple times in the source file. include guards are written using pre-processor directives.

## C Basics

### Data Types

- Data as numbers (integer or real number)
	- Int data types: 10, 20 (represent whole numbers)
	- Float data types: 24.5, 60.000001 (represent real numbers)
- Data as characters: 'A'
    - Can be represented by ASCII values
    - Can be represented Octal values

> [!NOTE]
> Refer to ASCII Table to get representation of the character you are trying to represent

Data Types:
```
+------------------------------------------------------------+
|  int    |   short   |    long    |  long long   |   void   |
+------------------------------------------------------------+
|  char   |   float   |   double   |  long double |
+-------------------------------------------------+
```

#### Portability Issues Data Types

In C programming language the most commonly used data types `int` and `long` cause portability issues. The reason is that the storage size for `int`, `long` type variable is not defined within the C standard ( C90 or C99 ).

The compiler vendors have the choice to define the storage size for the variable depending solely on hardware capabilties of the target platform, with respect to the minimum widths defined by the standard

Use the standard library header file `stdint.h` defines fixed-width integers using alias data types for the standard data type aviable in C

stdint.h alias data types

| Exact Alias | Descriptiton | Range    |
|:-----------:|:-------------|:---------|
| int8_t | exactly 8 bits signed | -128 to 127 |
| uint8_t | exactly 8 bits unsigned | 0 to 255 |
| int16_t | exactly 16 bits signed | -32,768 to 32,767 |
| uint16_t | exactly 16 bits unsigned | 0 to 65,535 |
| int32_t | exactly 32 bits signed | -2,147,483,648 to 2,147,483,647 |
| uint32_t | exactly 32 bits unsigned | 0 to 4,294,967,295 |
| int64_t | exactly 64 bits signed | -9,223,372,036,854,755,808 to 9,223,372,036,854,755,807 |
| uint64_t | exactly 64 bits unsigned | 0 to 18,446,744,073,709,551,615 |

> [!CAUTION]
> Each `stdint.h` is different per compiler.

#### Conversions

* **Binary base-2**
* **Hexadecimal base-16**
* **Decimal base-10**
* **Octal base-8**

4 bits = 1 nibble

1 nibble = 1 hexadecmial value

8 bits = 1 Byte

8 bits = 0000 0000 in binary

1 nibble = 0000 in binary

* Hexadecimal Digits base-16 = (0-9 and A-F)
	* 0 (decimal) = 0000 (binary) = 0 (hex)
	* 15 (decimal) = 1111 (binary) = F (hex)

| Byte | Bit | Nibbles | Hexadecimal |
|:---:|:---:|:---:|:---:|
| 1 | 8 | 2 | 2 |
| 2 | 16 | 4 | 4 |
| 4 | 32 | 8 | 8 |
| 8 | 64 | 16 | 16 |

#### Operators

An operator is a symbol that tells the compiler to preform a certain mathematical or logical manipulation on the operands

```
                +------------------------------------------------------------------+
                | Operator                     | Type                              | 
 Unary          |------------------------------|-----------------------------------|
 Operator ----> |  ++  ,  --                   | Increment and Decrement Operators |
                |------------------------------------------------------------------|
           ---> |  + , - , * , / , %           | Arithmetic Operators              |
 Binary    |    |  < , <= , > , >= , == , !=   | Relational Operators              |
 Operator -|    |  && , || , !                 | Logical Operators                 |
           |    |  & , | , << , >> , ~ , ^     | Bitwise Operators                 |
           ---> |  = , += , -= , *= , /= , %=  | Assignment Operators              |
 Ternary        |------------------------------------------------------------------|
 Operator  ---> |  ?:                          | Conditional Operators             |
                +------------------------------|-----------------------------------+
```

**Operator Precedence**

_Operator precedence_ rules determine which mathematical operation takes place first, i.e takes precedence over others. Parentheses, `()`, may be used to force an expression to a higher precedence

**Increment and Decrement**

Increment
```c
uint32_t x,y;
x = 5;
y = ++x;

y = 6, x = 6;       
/* 
 * First, value of x will be incremented by 1
 * Then value of x will be assigned to y
*/
```

Decrement
```c
uint32_t x,m;
x = 5;
m = x++;

m = 5, x = 6;       
/* 
 * First, value of x will be assigned to m
 * Then value of x will be incremented by 1
*/
```

Unary Operators with pointer variables
```c
uint32_t *pAddress = (uint32_t*) 0xFFFF0000;

pAddress = pAddress +1;
/* results = pAddress = 0xFFFF0004 
 * This is based on the data type
 * Since it is int (4 Bytes) it added 4 Bytes
*/

pAddress++;     /* This can be written in the same way */
/* pAddress = 0xFFFF0004 */
```

### Variables

- Variables are identifiers for your data
- Usually stored in computer memory
- Variables acts as a label to a memory location where the data is stored
- Variable names are not stored inside the computer memory, and the compiler replaces them with memory location addresses during data manipulation

Syntax: 
Variable definition:
* `data type` + `variable name`;
Example:
* `char` myName;
Variable initialization:
* `char` number = 25;

_Variable definition vs declaration_

* A variable is **defined** when the compiler generates instructions to allocate the storage for the variable.
* A variable is **declared** when the compiler is informed that a variable exists along with its type. The compiler does not generate instructions to allocate the storage for the variable at that point.

> [!NOTE]
> A variable definition is also a declaration, but not all variable declarations are definitions.

```c
#include <stdio.h>

extern int myExamScore; // variable is a declaration (does not allocate storage)
int myExamScore; // variable is globally defined. (not in function)

int main()
{
	
	int myExamScore; // variable is locally defined. (within the function)

	return 0;
}

```

***Variable Scope***

* **Variable scope** refers to the accessibility of a variable in a given program or function
	* a variable may be only available within a _specific function_ or may be available to the entire _C program_

2 Types of Variables:

	* Local scope variables (local variables)
	* Glocal scope variables (global variables)

```c
#include <stdio.h>

/* This is a function prototype of function myFun1 */
void myFunc1(void);

int main()
{
	/*
	Local variables exists (memory claimed) for the time the function is executed.

	Once the function exits, local variables die. (memory reclaimed)

	So, local variables come and go during the run time for the function execution of a program

	They don't sit permanently on the data memory
	*/

	int myScore; 
	myScore = 900;

	printf("Value of the variable myScore = %d\n",myScore);
/* This is a function call */
	myFun1();
	
	return 0;

}
/* This is a function definition */
void myFunc1(void)
{
	myScore = 800;
	printf("002Value of the variable myScore = %d\n",myScore); // This will be a compiler error as you can not access
															   // as myScore is local to main()
}
```

**Scope** - Global variables are visiable to all functions of a program. They can access global variables from another file of the project.

**Default value** - All uninitialized global variables will have 0 as default value.

**Lifetime** - Till the end of the execution of the program.

* `extern` keyword tells the compiler that, this variable is defined outside the scope of this file.

***Address of Variables***

* using `&` gives you the memory location address of variable
	* `&variable`

***Storage Class Specifiers***

The Storage Classes in C language decides:

* Scope of variable
* Visibilty of a variable or function
* Life time of a variable

Types of storage class specifiers in C:

* `static` - global does not change for the whole program
* `extern` - global for the whole program
* `auto` - local to function

Example Static:
```c
#include <stdio.h>

// This value can only be changed within this program
// Example: main.c could only change the value any external code could not change it 
static int value;

int main()
{

	value = 100;
	
	printf("Value = %d\n",value);

	return 0;
}

```

_Extern_

* `extern` storage class specifier is used to access the global variable, which is defined outside the scope of a file.
* `extern` storage class specifier can also be used during the function call, when the function is defined outside the scope of the file.

***ASCII CODES***

* The American National Standards Institute (ANSI), which developed ANSI C, also developed the ASCII codes.
* ASCII stands for "American Standard Code for Information Interchange"
* By using ASCII standard, you can encode 128 different characters.
* That's why to encode any ASCII character you just need 7 bits

#### Signed Vs Unsigned Data

**Signed Data**

* signed data could be **positive** or **negative**
	* ex. temperature

Examples of _signed data_:
* `char`
* `short int` (`short`)
* `int`
* `float`
* `double`
* `long int` (`long`)
* `long double`
* `long long int` (`long long`)

**Unsigned Data**

* unsigned data only be **positive**
	* ex .distance between point a to point b

Examples of _unsiged data_:
* `unsigned char`
* `unsigned short int` (`short`)
* `unsigned int`
* `unsigned float`
* `unsigned double`
* `unsigned long int` (`long`)
* `unsigned long double`
* `unsigned long long int` (`long long`)

#### Storage Sizes

| Data Type  | Memory Size (Bytes) | Range |
|:----------:|:-------------------:|:-----:|
| signed char | 1 | -128 to 127 |
| unsigned char | 1 | 0 to 255 |
| short | 2 | -32,768 to 32,767 |
| unsigned short | 2 | 0 to 65,535 |
| int | 4 | -2,147,483,648 to 2,147,483,647 |
| unsigned int | 4 | 0 to 4,294,967,295 |
| float | 4 | 0 to 4,294,967,295 |
| unsigned float | 4 | 0 to 4,294,967,295 |
| double | 8 | -9223372036854775808 to 9223372036854775807 |
| unsigned double | 8 | -9223372036854775808 to 9223372036854775807 |
| long double | 8-16 |
| long | 8 | -9223372036854775808 to 9223372036854775807 |
| unsigned long | 8 | 0 to 18446744073709551615 |
| long long int | 8 | -9223372036854775808 to 9223372036854775807 |
| unsigned long long int | 8 | 0 to 18446744073709551615 |

> [!NOTE]
> The following data types and memory size depends on the complier and architecture (32 bit or 64 bit).
> 32 bit = 4 Bytes 
> 64 bit = 8 Bytes

**Sizeof Operator**

* `sizeof` operator of C programming language is used to find out the size of a variable

* C standard does not fix the storage sizes of different data types. It only talks about the minimum and maxiumum values.
* Information about the complier can be found in the manufacturers _datasheet_.

**Integer Data Type: char**

* This is an integer data type to store a single character(ASCII code) value or 1 byte of signed integer value (+ve or -ve value)
* A `char` data type variable consumes 1 bytes (8 bits) of memory.
* `char` Happens to be the smallest integer data type of 1 byte.
* There is no other special meaning for the `char` data ype, and it is just another integer data type.

Range of `char` data type
* char range: -128 to 127
	* A char data type will be used to store 1 byte of signed data
* Unsigned char range: 0 to 255
	* An unsigned char data type will be used to store 1 byte of unsigned data

**Float Data Type**

* A decimal Number contains a Decimal Point.
	* 125.55 is a decimal number (a real number)
* In computer memory, the real numbers are stored according to the representation standardized by the **IEEE** standard 754
* **IEEE754** floating-point representation is an approximate representation of real numbers.
* All computer systems and microcontrollers use this standard to store real numbers in memory.
* If working with numbers that have a fractional part or in case you are using integers that don't fit into a long data type, then we can use floating-point representation.

#### IEDD-754 Floating-point Standard

Exaample:
```
    +7.432 x 10^48
```

* Stores the sign `+`
* Significand `7.432`
* Exponent `48`

Single precision --> 32 bit representation
```
     1         8                    23
  ---|---------|--------------------|--------------
  |     |            |                            |
 +------+------------+----------------------------+
 | sign |  Exponent  |         Significand        |
 +------+------------+----------------------------+
 31     30           22                           0
```

Double precision --> 64 bit representation
```
     1         11                   52
  ---|---------|--------------------|--------------
  |     |            |                            |
 +------+------------+----------------------------+
 | sign |  Exponent  |         Significand        |
 +------+------------+----------------------------+
 63     62           51                           0
```

Format Specifier:
                                    
|  Format Specifier  |  Data Type            |
|:------------------:|:----------------------|
|       %f           |    float              |
|       %lf          |    double             |
|       %e %le       |  scientific notation  |

Range of Float

- Storage size: 4 bytes
- Precision: Up to 6 decimal places
- Value range: 1.2x10<sup>-38</sup> to 3.4x10<sup>38</sup>

Range of Double

- Storage size: 8 bytes
- Precision: Up to 15 decimal places
- Value range: 2.3x10<sup>-308</sup> to 1.7x10<sup>308</sup>

Example
```c
#include <stdio.h>

int main(void) {

    float number = 45.203023095;
    
    printf("Number = %f\n",number);     /* This prints out in decimal for up to 6 decimals */
    printf("Number = %e\n",number);     /* This prints the format in exponent form 4.520302e+001 */

    return 0;
}
```

To Represent A Values In Scientific Notation
```c
float chareE = -1.60217662 x 10-19;     /* You cant do this to represent it use the following */
float chareE = -1.60217662e-19;
```

#### Format Specifier

| Format Specifier |      Description        |
|:-----------------|:------------------------|
|        %d        |      Signed Int         |
|        %ld       |      Long Int           |
|        %u        |      Unsigned Int       |
|        %lu       |      Unsigned Long Int  |
|        %f        |      Float              |
|        %lf       |      Double             |
|        %Lf       |      Long Double        |
|        %c        |      Character          |
|        %s        |      String             |
|        %p        |      Pointer            |
|        %x        |      Hexadecimal        |
|        %o        |      Octal              |

* For signed data a dedicated 1 bit is reserved and the other 7 bits for magnitute

```
Example -25

This is represented by base 2^0...2^7
[2^0] 1 , [2^1] 2 , [2^2] 4 , [2^3] 8 , [2^4] 16 , [2^5] 32 , [2^6] 64 , [2^7] 128

[7][6][5][4][3][2][1][0]
[7] bit for signed - 
[6][5][4][3][2][1][0] for the magnitute 25

A nibble is represented as 4 bits
[7][6][5][4] | [3][2][1][0]
  1 nibble      2 nibble

[1][1][1][0] | [0][1][1][1]
[8][4][2][1] | [8][4][2][1]

8+4+2+0 = 14 = E | 0+4+2+1 = 7
hex value of decimal -25 = 0xE7
```

For `signed char` -128 to 127

_When sign is +:_

```
Least Value [7][6][5][4][3][2][1][0]
             0  0  0  0  0  0  0  0
Magnitude: 0

Higest Value [7][6][5][4][3][2][1][0]
Higest Value  0  1  1  1  1  1  1  1
Magnitude: 127

Range is 0 to 127 for +ve data
```

_When sign is -:_

```
Least Value [7][6][5][4][3][2][1][0]
Higest Value 1  0  0  0  0  0  0  0
Magnitude: -128

Higest Value [7][6][5][4][3][2][1][0]
Higest Value  1  1  1  1  1  1  1  1
Magnitude: -1

Range is -128 to -1 for -ve values
```

For `unsigned char` 0 to 255

```
Least Value [7][6][5][4][3][2][1][0]
Higest Value 0  0  0  0  0  0  0  0
Magnitude: 0

Higest Value [7][6][5][4][3][2][1][0]
Higest Value  1  1  1  1  1  1  1  1
Magnitude: 255

Range is 0 to 255 for unsigned values
```

For `signed short`:

* Consumes short is always 2 _bytes_

```
Example Representation -25 for short 2 byte 

2 Bytes (16 bits)

[15][14][13][12][11][10][9][8][7][6][5][4][3][2][1][0]
  0   0   0   0   0   0  0  0  0  0  0  1  1  0  0  1
Arithmetic can be represented by 2^(n+1)-1
2^(15+1)-1 = 65535
```

* `signed short` range: -32,768 to 32,767 
	* hexadecimial 0x0000 to 0xFFFF
* `unsigned short` range: 0 to 65,535

For `signed int`:

* Consumes 2 _bytes_ or 4 _bytes_
* `sizeof` `int` depends on compiler

For `long`:

* Consumes 4 _bytes_ or 8 _bytes_
* `sizeof` `long` depends on compiler

#### Type Casting

Typecasting is a way of converting a variable or data from one data type to another data type. Data will be **truncated** when the higher data type is converted in to lower.

Example:
`unsigned char data = 0x87 + 0xFF00;`
* 0x87 in decimial is 135 which is an int (4 byte data type) this will implicitly be promoted up to an integer
* So you are trying to store it into a 1 byte data type which is `char`
* Because of that it will be **truncated** to fufill the conversion
	* This will cause _data_ lose

2 types of casting:
* Implicit casting (compiler does this)
* Explicit casting (programmer does this)

> [!CAUTION]
> Not having the correct data type when preforming an expression is dangerous it can cause a ***loss*** of data as the data will be ***truncated*** to conform to the corresponding data type. Ex. `char = 1 byte` vs `int = 4 bytes
`

To `type cast` a data type or variable to the correct data type the following will happen:
```c
float number = 80 / 3;
// To type case the
printf("%f\n", number);
// Output 26.000000
// Notice that the value is whole number that is because you are dividing an int by an int.
// To change this all you have to do is type cast (explicitly) one of the values and the other value will be type cast (implicitly) from the compiler

float number = (float) 80 / 3;
printf("%f\n", number);
26.666666
```

* To type cast `(data type)` followed by the value you want to type cast.
	* ex. float (44) / 3
#### Escape Sequences

* `\` is escape sequence
* `\n` the escape sequence followed by `n` is the escape "code"

| escape characters	| purpose | description |
|:---:|:----|:---|
| `'` | single quote | makes a single quote as a normal printable character |
| `"` | double quote | makes a double quote as a normal printable character |
| `\` | backslash |
| `\0` | null |
| `\a` | bell |
| `\b` | backspace |
| `\f` | form Feed |
| `\n` | newline | moves the cursor to the beginning of the new line vertically |
| `\r` | carriage return | moves the cursor  to the beinning of the current line horizontally |
| `\t` | horizontal tab |
| `\v` | verical tab |

```c
printf("Message\r");
printf("Hello");

/* Output */
Hello

carriage return, returns the cursor back to the beginning of the line overwritting any text that was there before.
```

#### Comments

* Comments do not consume memory space or comments do not affect program
* Two Types of comments:
	* `//` Singe line comments
	* `/*  * /` Multiline comments
### Strings

- Operators are not used for manipulate a string in C

***Null Character***

- String arrays end with the '\0' NULL character
- ASCII character code 0: \0
- Storage must be allocated for the null character

Creating String Storage

- Set aside buffer size for all the text plus the null charcter
```
Example ----> char string[32];
```
- 31 Characters + Last Character for Null
-  Putting more charaters into a string buffer is overflow  *
-  Ensure that strings never overflow  *
Example
```
char hello[] = "Hello" -> hello[0] = 'H' hello[1] = 'e' hello[2] = 'l' hello[3] = 'l' hello[4] = 'o' hello[5] = '\0'
```

- EOF (End of File) is a integer
  - To end texting use control + d in linux
  - To end texting use control + z in windows

| FUNCTIONS USED FOR STRINGS |
|:---|
| putchar() - prints out a character 't' **does NOT end with \n** |
| puts(const char *str) - prints out a string of chars followed by a \n |
| fgets(variable_name, BUFFER SIZE, stdin) better than scanf ----> example  char name[10]; fgets(name,10,stdin); |
| printf(const char *format,...) - prints formatted output, such as strings, integers, floats, characters |
| getchar() - \
| scanf()  - not really good for string input does not catch spaces or tabs and can cause buff overflow ---> char[11] but someone input 15 characters instead (buff overflow) |

 string.h
 ```
+----------------------------------------
|  strlen() - to find a string's length 
|  strstr() - to earch a string 
|  strcpy() - to copy a string 
|  strcat(string,text) 
+----------------------------------------
```

 ctype.h

- functions that test characters are called is functions
- functions that multiple characters start with TO
```
-----------------------------------------------------
|  isalpha() - character is a letter of the alphabet
|  isdigit() - character is a number (0 to 9)
|  isupper() - character is uppercase
|  islower() - characer is lowercase
------------------------------------------------------
|  tolower() - converts uppercase to lowercase
|  toupper() - converts lowercase to uppercase
------------------------------------------------------
```

### Functions

* In `C`, you write executable statments inside a function
* A `C`, function is nothing but a collection of statements to preform a specific task
* Every C program, at least, has one function called "main".
* Using functions bring modularity to your code, easy to debug, modify and increases the maintainability of the code
* Using C function also minimizes code size and reducing code redundancy

Function Format:
```c
return_data_type function_name(parameter list)
{
	body of the function
}
```

Function prototype(declaration):

> return_data_type function_name(parameter list);

* In `C` functions first have to be declared before they are used.
* Prototype(declaration) lets compiler to know about the return data type, argument list and their data type and order of agruments being passed to the function.

2 Ways For main function definition:

* int main() { } -> this has no arguements
* int main(int argc, char* argv[]) { } -> 2 input arguments (command line arguments)

> [!WARNING]
> The 2nd option is usually not used in embedded systems because most of the time, there are no command-line arguments in embedded systems.

* `main` takes only zero or two arguments
* main() is the special function in C from where  execution of a program starts and ends.
* main() function returns the status of a program to the Parent process, showing the success or failure of the programm. 0 means SUCCESS. Non zero ERROR.
* main() function suppose to return an _int_ value to the calling process as per the standard (C89 and above)

```c
/* Function prototyping or Function declartion */
void function_add_numbers(int a, int b, int c);

int main()
{
	function_add_numbers(12,13,14); /* Function calling */
	return 0;
}

// This is function definition
void function_add_numbers(int a, int b, int c) /* int a, int b , int c
												  are local scope variables they are used to recieve data
												  from other parts of the program. These variables are also
												  called 'formal' parameters
												*/
{
	int sum;
	sum = a+b+c;
	printf("Sum = %d\n",sum);
}
```

#### Conditional Statemnets

`ternary` statements

Format:
```c
condition ? expression1 : expression2
```

`ternary` example:
```c
x = y > 7 ? 25 : 50;    /* results in x being set to 25 if y is greater than 7, or to 50 otherwise */

/*  breakdown
 *  if( y > 7 )
 *      x = 25;
 *  else
 *      x = 50;
 */ 
```

`if` statements

Format:
```c
if (expression) {
    
    program statements;
}    
else if (expression) {

    program statements;
}

else {

    program statements;
}
```

`if` example:
```c
if (number == 1) {

    printf("Error");
}
if else (number == 2) {
    
    printf("Okay");
}
else {
    printf("Good");
}

```

`switch` statements

Format:
```c
switch(parameter) {
    case (parameter 1):
        statements;
        break;
    case (parameter 2):
        statements;
        break;
    default:
        statements;
        break;
}
```

`switch` example:
```c
#include stdio.h
#include math.h

int main() {
char opp;

scanf("%c",&opp);

switch(opp) {
    case '+':
        add(2,3);
        break;
    case '-':
        sub(2,3);
        break;
    case '*':
        multiple(3,5);
        break;
    case '/':
        subtract(3,10);
        break;
    default:
        printf("Invalid Input");
        break;
}

    return 0;
}
```

#### User Input

`scanf()`

- `scanf` is a standard library function that allows you to read input from standard in
- Standard in for usually the keyboard
- By using scanf library function you can read both characters and numbers from the keyboard

```c
int age;
printf("Enter your age:");
scanf("%d",&age);

/* scanf reads and integer %d which the user enters */
/* scanf puts the read value at the address & of 'age' variable */
```

`getchar()`

- If you want to read a single character from the keyboard in ASCII format then just use `getchar()`
- `getchar` function takes no arguments and just returns an int vaue which happens to be a the ASCII value of the key pressed

```c
int a = getchar();      /* Here the program hangs until you press a key followed by pressing the enter key */
```

How `scanf` works
```
      +------------+
      |  Keyboard  |------------
      +------------+           |
                              \|/
                        +--------------+
                        | Input Buffer |
                        +--------------+
                               |____________
                                           |
                                    +--------------+
                                    |   Program    |
                                    +--------------+
                                        scanf
                                        getchar()
```
Code Under The Hood
```c
#include <stdio.h>

int main(void) {

    int age;

    printf("Enter Your Age: ",age);
    scanf("%d",&d);

    getchar();      /* In this program it automatically exits because it fetches /n as show below */

    /* To fix this do this instead */

    while (getchar() != \n) {
        printf("Enter any key to exit program");
        getchar();
    }

    return 0;
    
}
```

Usage:
```
      +------------+
      |  Keyboard  |------------
      +------------+           |
                              \|/
                        +--------------+        +-------------+
                        |     10\n     | ------>|     \n      |
                        +--------------+        +-------------+
                              /|\                     /|\   
                               |____________           |____
                               |           |               |
                               |          \|/              |
                               |    +--------------+       |
                               |    |   Program    |       |
                               |    +--------------+       |
                               |------- scanf              |
                                        getchar() fetches \n
```

## Advanced C

### Pointers

Pointers are one of the essential programming features which are available in C. Pointers make C programming more powerful

Pointers are heavily used in embedded `C programming` to:

- Configure the peripheral register address
- Read/Write into peripheral data registers
- Read/Write into SRAM/Flash locations and for many other things.

Diagram Of What Pointers
```
                   +---------------+
0x00007FFF8E3C3828 |0|1|1|0|0|1|1|1| <-----------
                   -----------------            |
0x00007FFF8E3C3827 |0|1|1|0|0|1|1|1|            |
                   -----------------            |
0x00007FFF8E3C3826 |0|1|1|0|0|1|1|1|            |
                   -----------------            |
0x00007FFF8E3C3825 |0|1|1|0|0|1|1|1|            |        Different 
                   -----------------            |------> memory
0x00007FFF8E3C3824 |0|1|1|0|0|1|1|1|            |        locations of
                   -----------------            |        the computer
0x00007FFF8E3C3823 |0|1|1|0|0|1|1|1|            |        memory
                   -----------------            |
0x00007FFF8E3C3822 |0|1|1|0|0|1|1|1|--------    |
                   -----------------       |    |
0x00007FFF8E3C3821 |0|1|1|0|0|1|1|1| <-----|----|
                   +---------------+       |
    Pointers                              \|/
                                     Value Stored in a memory location
                                     0x000007FFF8E3C3822
On 64 bit machine, the pointer size (memory location address size) is 8 bytes (64 bits)
```

**Pointer Variable Definition**

`pointer data type` `variable name`;

| Point Data Types|
|:---------------:|
| char* |
| int* |
| long long int* |
| float* |
| double* |

For the following pointer data types above.

- The compiler will always reserve **8 Bytes** for the pointer variable irrespective of their pointer data type.
- In other words, the pointer data type doesn't control the memory size of the pointer variable.

Example:
```c
#include <stdio.h>

int main(void) {

    char* address1 = 0x000007FFF8E3C3824;       /* This is considered a normal number */

    char* address1 = (char*) 0x000007FFF8E3C3824;       /* This is a pointer by explicitly type casting it */

    return 0;
}
```

- `*`: Value of Address Operator
- `&`: Address of Operator

```c
char data = *address1;      /* Dereferencing a pointer to read data */

/* Means dereference the address of data
*/ And grabing the value store at address data
```

To Write Operation on the pointer
```c
*address1 = 0x89;       /* Dereferencing a pointer to write data */
```

**Pointer Arithmetic**

When preforming pointer arithmetic, based on the `data type` used for the point depends how much the address will increment.

Example
```c
#include <stdio.h>

long long int g_data = 0xFFFEABCD11112345;

int main(void) {

	char *pAddress1 = (char*) &g_data;
	
	printf("Value at address %p\n",pAddress1);
	printf("Value at address %p is: %x\n",pAddress1,*pAddress1);
    
	pAddress1 = pAddress1 + 1;
	printf("Value at address %p\n",pAddress1);
	printf("Value at address %p is: %x\n",pAddress1,*pAddress1);

	int *pAddress2 = (int*) &g_data;
	
	printf("Value at address %p\n",pAddress2);
	printf("Value at address %p is: %x\n",pAddress2,*pAddress2);

	pAddress2 = pAddress2 + 1;
	printf("Value at address %p\n",pAddress2);
	printf("Value at address %p is: %x\n",pAddress2,*pAddress2);
	return 0;
}
```

Output
```
Value at address 0x556cd80038
Value at address 0x556cd80038 is: 45        /* Value is 45 which is the first byte of 0xFFFEABCD11112345 */
Value at address 0x556cd80039       /* Noticed the change in address when you increment up +1 */
Value at address 0x556cd80039 is: 23        /* Value is 23 which is the next byte of 0xFFFEABCD11112345 */
Value at address 0x556cd80038
Value at address 0x556cd80038 is: 11112345
Value at address 0x556cd8003c
Value at address 0x556cd8003c is: fffeabcd
```

How is Pointer Used in Embedded Programming?

- Store data into required SRAM locations
- For copying data from Peripheral register to SRAM memory and vice versa
- To configure the peripheral registers. Because peripheral registers are memory-maped and each register will be given unique address in the MCU memory map
- Pointers to ISRs (Interrupt Service Routine) are sotred in a vector table to handle the interrupts
- Pointers are also used to configure the memory-mapped processor specific registers like interrupt configuration registers

### Structures

## Embedded Systems

### Debuggers

**Hardware Debuggers**

SWD interface has a **ITM (Instrumentation Trace Macrocell Unit)**

Within the **ITM** there is `FIFO` (First in First Out), this is a buffer/register which is connected to the SWO Pin.
```
ITM unit [FIFO] -> SWD [Connector] -> SWO Pin -> ST link circuitry -> STM32 IDE -> Console View [printf]
```

* SWD - Serial Wire Debug (ARM debug interface)
	* 2-pin debugger not including (GND & +V)
		* **SWDIO**: A bidirectional data line used for communication
		* **SWCLK**: A clock line driven by the debugger
	* Used SWO ( serial wire output) over SWD interface
	* Used only in ARM Cortex M3/M4/M7 or higher processors
	* The other good thing about SWD is you can use the serial wire viewer for printf statements for debugging.

By using SWD interface should be able to program MCUs internal flash, you can access memory regions, add breakpoints, stop/run CPI.


* JTAG (Joint Test Action Group)
	* 10 pin connector
		* **TDI** (Test Data In): Used to send data to the device's JTAG interface
		* **TDO** (Test Data Out): Used to receieve data from the devices's JTAG interface
		* **TCK** (Test Clock): Provides the timing for data transfer etween the JTAG programmer and the device
		* **TMS** (Test Mode Select): Used to control the different JTAG modes (e.g. boundary scan, programming)
		* **TRST** (Test Reset): Used to reset the JTAG interface and the device.
	* Use for ARM7/9 family

### Compilation

* **Cross Compilation** - runs code a host machine and using a cross compiler to produce an executable for a different architecture.
	* x86_64 ---> ARM architecture
	* host machine : arm-none-eabi-gcc ( cross compiler )
	* target machine : .elf / .bin / .hex 
		* .elf (executeable and linkable format)
			* Used for debugging
		* .bin (binary)
			* Pure executable used for production
		* .hex (Intel HEX file)
			* Pure executable used for production

* **Native Compilation** - compiler runs on host machine and produces executable which also runs on the same machine.

### Microcontroller

**Microcontroller** (MCU) - is a small computer system on a single chip. But its resources and capabilities such as memory, speed, external interfaces are very limited than other desktop computer becasue of MCU targets embedded applications.

Typical microntroller includes a processor, volatile and non-volatile memories, input/output(I/O) pins, peripherals, clock, bus interfaces on a single chip.

MCU is also known as SoC (System on Chip) meaning it has all the following hardware in the microcontroller.

Example:

* Processor CPU (Central Processing Unit)
* Peripherals
	* ADC (Analog to Digital Converter)
	* DAC (Digital to Analog Converter)
	* Timers
	* UART (Universal Asynchronous Receiver/Transmitter)
	* USB
* Memories
	* SRAM (Static Random Access Memory) (volatile memory)
	* Flash (non-volatile memory)
	* ROM (Read Only Memory)
	* EEPROM (Electrically Erasable Programmable Read Only Memory) (non-volatile memory)
* Clock
* BUS (Binary Unit System)

Instructions of the CPU is located in `program memory` (non-volatile)

Once power is given to the MCU -> `program memory` starts executing the program memory utilized bus interfaces to communicate to the CPU. Also know of `address bus` then goes to -> `data bus` (instruction bus) then it goes back to CPU to decodes the instructions from the `data bus`.

The speed of how quickly the CPU preforms those instructs is based on the `clock` supplied.

* Code memory: non-volatile, and it is used to store your program instructions.
* Data memory: volatile memory and it is used to store data of your program and also used as a scratch pad (store temporary data)

* External modules are connected to serial I/Os and then data received is stored in the data memory.

**Code Memory**

The purpose of code(Program) memory is to store instructions and constant data of your program.

There are different types of code memory:
	* ROM (Read Only Memory)
		* MPROM (Mask Programmable Read Only Memory)
		* EPROM (Ultraviolet Erasable Programable ROM)
		* EERPROM (Electrically Erasable Programmable ROM)
	* OPT (On time programmable)
	* Flash
	* FRAM (Ferroelectric Random Acces Memory)

To analyze code of .elf

Use `arm-none-eabi-objdump.exe -h` name.elf

Where `-h` Display the contents of the section headers.

.ELF File has many sections:
	* .text section of the elf file contains `codes` or all the instructions of your program
	* .rodata section contains all the `read-only data` of your program
	* .data section contains all the `data` of your program

LMA: Load Memory Address (Source in Flash)
	* LMA where the section is currently loaded 
VMA: Virtual Memory Address (Destination in SRAM).
	* VMA says where the section should finally be copied to

The LMA address is copied into the VMA address location. This is done by the software.

The software that does this process is the `start up` code.

In the start up file a routine `reset_handler` happens when it undergoes a reset the first routine that gets called is `reset_handler`. This gets called up from the handler.

Example:
```c
Reset_Handler:
  ldr   r0, =_estack
  mov   sp, r0          /* set stack pointer */
/* Call the clock system initialization function.*/
  bl  SystemInit

/* Copy the data segment initializers from flash to SRAM */
  ldr r0, =_sdata
  ldr r1, =_edata
  ldr r2, =_sidata
  movs r3, #0
  b LoopCopyDataInit

CopyDataInit:
  ldr r4, [r2, r3]
  str r4, [r0, r3]
  adds r3, r3, #4

LoopCopyDataInit:
  adds r4, r0, r3
  cmp r4, r1
  bcc CopyDataInit

/* Zero fill the bss segment. */
  ldr r2, =_sbss
  ldr r4, =_ebss
  movs r3, #0
  b LoopFillZerobss
```

Example Code:
```c
003Add.elf:     file format elf32-littlearm

Sections:
Idx Name          Size      VMA       LMA       File off  Algn
  0 .isr_vector   00000188  08000000  08000000  00001000  2**0
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
  1 .text         00001174  08000190  08000190  00001190  2**4
                  CONTENTS, ALLOC, LOAD, READONLY, CODE
  2 .rodata       00000040  08001304  08001304  00002304  2**2
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
  3 .ARM.extab    00000000  08001344  08001344  00003064  2**0
                  CONTENTS, READONLY
  4 .ARM          00000008  08001344  08001344  00002344  2**2
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
  5 .preinit_array 00000000  0800134c  0800134c  00003064  2**0
                  CONTENTS, ALLOC, LOAD, DATA
  6 .init_array   00000004  0800134c  0800134c  0000234c  2**2
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
  7 .fini_array   00000004  08001350  08001350  00002350  2**2
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
  8 .data         00000064  20000000  08001354  00003000  2**2
                  CONTENTS, ALLOC, LOAD, DATA
  9 .ccmram       00000000  10000000  10000000  00003064  2**0
                  CONTENTS
 10 .bss          00000170  20000064  20000064  00003064  2**2
                  ALLOC
 11 ._user_heap_stack 00000604  200001d4  200001d4  00003064  2**0
                  ALLOC
 12 .ARM.attributes 00000030  00000000  00000000  00003064  2**0
                  CONTENTS, READONLY
 13 .debug_info   00000950  00000000  00000000  00003094  2**0
                  CONTENTS, READONLY, DEBUGGING, OCTETS
 14 .debug_abbrev 00000320  00000000  00000000  000039e4  2**0
                  CONTENTS, READONLY, DEBUGGING, OCTETS
 15 .debug_aranges 00000118  00000000  00000000  00003d08  2**3
                  CONTENTS, READONLY, DEBUGGING, OCTETS
 16 .debug_rnglists 000000be  00000000  00000000  00003e20  2**0
                  CONTENTS, READONLY, DEBUGGING, OCTETS
 17 .debug_macro  00002bc7  00000000  00000000  00003ede  2**0
                  CONTENTS, READONLY, DEBUGGING, OCTETS
 18 .debug_line   00001415  00000000  00000000  00006aa5  2**0
                  CONTENTS, READONLY, DEBUGGING, OCTETS
 19 .debug_str    00009917  00000000  00000000  00007eba  2**0
                  CONTENTS, READONLY, DEBUGGING, OCTETS
 20 .comment      00000043  00000000  00000000  000117d1  2**0
                  CONTENTS, READONLY
 21 .debug_frame  00000b08  00000000  00000000  00011814  2**2
                  CONTENTS, READONLY, DEBUGGING, OCTETS
 22 .debug_line_str 00000071  00000000  00000000  0001231c  2**0
                  CONTENTS, READONLY, DEBUGGING, OCTETS
```

#### Disassemble

**Disassemble** - translate (a program) from machine code into a higher-level programming language.

Used `objdump` tool to disassemble the machine code generated.

Processor Architecture and instruction set

`Processor`: ARM Cortex M4\
`Process architecture`: ARMv7E-M\
`Instruction set architecture(ISA)`: Thumb-2 instruction set(16/32 bits instruction encoding)

* `ldr` - load instructions
* `str` - store instructions
* `add` - modify registers where two registers are added

Preform this `arm-none-eabi-objdump.exe -d` if you want to preform instruction level debugging.

To preform instruction level debugger for a specific location or function. You need to add breakpoints.

To get this run:\
arm-none-eabi-objdump.exe -d
```c
Reading Registers
-------------------------------------------------------------
|08000274:   ldr     r3, [pc, #28]   @ (0x8000294 <main+36>)|
|08000276:   ldr     r2, [r3, #0]						    |
|08000278:   ldr     r3, [pc, #28]   @ (0x8000298 <main+40>)|
|0800027a:   ldr     r3, [r3, #0]						    |
-------------------------------------------------------------
Example:
|08000276:   ldr     r2, [r3, #0]						    |
From register r3 is read and placed into r2


Modifying Registers (adding r3 to r2)
------------------------------------------------------------
|0800027c:   add     r3, r2								   |
------------------------------------------------------------
Writing Registers
-------------------------------------------------------------
|0800027e:   ldr     r2, [pc, #28]   @ (0x800029c <main+44>)|
|08000280:   str     r3, [r2, #0]							|
-------------------------------------------------------------
```

#### Representation of decimals numbers in C


## Appendix

```
Data Types
+---------------------------------------------------------------------------------------------+
|  int    |    short    |    long   |    double    |     float    |     char     |    void    |
+---------------------------------------------------------------------------------------------+
 Conditional  Iteration    Other
+-----------+------------+--------+                
|  if       |  while     |  goto  |                
|  else if  |  do        +--------+                
|  else     |  continue  |
+-----------+------------+
|  switch   |  for       |
|  default  |  break     |
+-----------+------------+
Other
+---------------------------------------------------------------------------------------------+ 
| unsigned |    enum    |   struct  |    typedef   |    const     |    static    |  volatile  |
+---------------------------------------------------------------------------------------------+ 
```
