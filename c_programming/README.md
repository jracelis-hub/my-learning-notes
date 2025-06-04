# C Programming

# Section 1 C Program Fundamentals
### Keywords in C Language
Variables
-----------------------------------------------------------------------------------------------
|  int    |    short    |    long   |    double    |     float    |     char     |    void   |
-----------------------------------------------------------------------------------------------
Conditional
-----------------------------------------------------------------------------------------------
|  if     |    ifelse   |   switch  |     case     |      do      |     while    |  default   |
|  break  |   continue  |    for    |     else     |      goto    |
-----------------------------------------------------------------------------------------------
Other
------------------------------------------------------------------------------------------------
|  auto   |    enum     |   struct  |    typedef   |    const     |    static    |  volatile  |
| register|   unsigned  |
------------------------------------------------------------------------------------------------

### Flow Chart On C Programming
.c ----> .o -----> .l ------> executlable

## Preprocessor 
- Directives that are carried out before source code is carried out before object code
  - Helps compiling
--------------------------------------------------------------------
|      #define        |        #error         |       #include     |
|      #elif          |        #if            |       #line        |
|      #else          |        #ifdef         |       #pragma      |
|      #endif         |        #ifndef        |       #undef       |
--------------------------------------------------------------------
- These files are found in linux under the file systems /usr/include or /usr/local/include
  - If used in <> they are searched in default directory if used in "" they are obtained in local directory
- the main headers files that are used are
---------------------------
|  stdio.h   |  stdlib.h  |
---------------------------

### Header Files Versus Libraries
- Header Files are used in source code source.c
  -Located in /usr/include
- Libraries are used for the linkers.l
  -Located in /usr/lib
- man pages for more info
  - telling you which linker needed
- if linker error use man page to explain which library to use

## Comments
- To use comments in C either use /* */ and anything in the those are commented
- To use comments in C either use // and anything on that line is commented

### The Main C Data Types are
### The Main C Data Types are
|-----------------------------------------------------------------|
|    int    |    float    |   char    |    double    |    void    |   
|----------------------------------------------------|------------|
int - integer or whole-number values | 1 Bytes
float - real numbers, single precision | 4 or 8 Bytes
char - single character bytes | 1 Bytes
double - real numbers, double precision | 4 or 8 Bytes
void - no data type (used for allocating memory or used for function definitions)
*C has no string data type*

## Data Type Qualifiers
signed - assign both positive and negative values
unsigned - assign only positive values


### Character and Strings
FUNCTIONS USED FOR STRINGS
-----------------------------------
| putchar() - put a character 't'
| puts()
| fgets(variable_name, BUFFER SIZE, stdin) better than scanf ----> example  char name[10]; fgets(name,10,stdin);
| printf()
| getchar()
| scanf()  - not really good for string input does not catch spaces or tabs and can cause buff overflow ---> char[11] but someone input 15 characters instead (buff overflow)
------------------------------------
C Library String Functions
------------------------------------
string.h
|  strlen() - to find a string's length
|  strstr() - to earch a string
|  strcpy() - to copy a string
|  strcat(string,text)
- Operators are not used for manipulate a string in C

# The Null Character
- String arrays end with the '\0' NULL character
- ASCII character code 0: \0
- Storage must be allocated for the null character

Creating String Storage
- Set aside buffer size for all the text plus the null charcter
EXAMPLE ----> char string[32];
- 31 Characters + Last Character for Null
*  Putting more charaters into a string buffer is overflow  *
*  Ensure that strings never overflow  *
EXMAPLE
char hello[] = "Hello" -> hello[0] = 'H' hello[1] = 'e' hello[2] = 'l' hello[3] = 'l' hello[4] = 'o' hello[5] = '\0'

- EOF (End of File) is a integer
  - To end texting use control + d in linux
  - To end texting use control + z in windows

## C-type functions
- ctype.h 
- functions that test characters are called is functions
- functions that multiple characters start with TO
-----------------------------------------------------
|  isalpha() - character is a letter of the alphabet
|  isdigit() - character is a number (0 to 9)
|  isupper() - character is uppercase
|  islower() - characer is lowercase
------------------------------------------------------
|  tolower() - converts uppercase to lowercase
|  toupper() - converts lowercase to uppercase
------------------------------------------------------
