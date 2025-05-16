# Linux && Bash Scripting

## Table of Contents

* [***Terminology***](#terminology)
	* [_Definitions_](#definitions)
* [***Purpose***](#purpose)
* [***Prerequisites***](#prerequisites)
* [***Section 1: Introduction***](#section-1-introduction)
	* [_Scripting Basics_](#scripting-basics)
	* [_Where Are Commands_](#where-are-commands)
	* [_Variables_](#variables)
	* [_Syntax_](#syntax)
	* [_Help Commands_](#help-commands)
* [***Section 2: Advanced Bash Concepts***](#section-2-advanced-bash-concepts)
	* [_Return Status_](#return-status)
	* [_Compund Commands_](#compound-commands)
		* [_Looping Contructs_***(While, Until, For, Select)***](#looping-constructs)
		* [_Conditional Constructs_***(If, Case, Test)***](#condition-constructs)
		* [_Command Groups_](#command-groups)
* [***Section 3: STDIN, STDOUT, STDERROR***](#section-3-stdin-stdout-stderror)
	* [_Redirection_](#redirection)
	* [_Manipulating Output_](#manipulating-output)
* [***Section 4 Parameter Manipulation***](#section-4-parameter-manipulation)
	* [_Parameters_](#parameters)
		* [_Parameter Expansion: Conditionals_](#parameter-expansion-conditionals)
		* [_Parameter Expansion: Substring_](#parameter-expansion-substring)
		* [_Parameter Expansion: Indirection Listing and Length_](#parameter-expansion-indirection-listing-and-length)
		* [_Parameter Expansion: Pattern Substitution_](#-parameter-expansion-pattern-substitution)
* [***Appendix***](#appendix)
	* [_Table References_](#table-references)
		* [_Bash Operators_](#bash-operators)
		* [_Commands_](#commands)
* [***References***](#references)
	* [_Links_](#links)

## ***Terminology***

***What is Unix?***

To understand a set of tools that is utilized, it is important to know the origin of those set of tools. ***Unix*** is a multi-user _OS_ (Operating System) that originated in the 1970s at AT&T's **Bell Labs**. Developed by Ken Thompson, Dennis Ritchie, and many others, Unix introduced keys concepts like hierarchical file systems, process control, and modular design. 

***What is POSIX?***

**POSIX** or Portable Operating System Interface) is set of IEEE standards designed to main compatibility between operating systems. It defines **APIs** (application programming inferfaces), command-line shells, and utility interfaces to ensure software portability across **Unix**-like systems

***What is Linux?***

**Linux** kernel is the program in the system that allocates the machine's resources to ther other programs that you can run. It is an essential part of an operating system, but it is useless without. It facilitates the communication between the **hardware** and software.

***What is GNU?***

**GNU** or GNU's Not Unix is an operating system whose purpose was to develop a _complete free Unix-like system_. The project was initiated by Richard Stallman the emphasise was for its free software philosophy. The project produced many essential components, such as compliers, editors and shell utilities.

From here GNU/Linux was formed, combining the Linux kernel to be able to communicate to the hardware and the software to utilize the kernel.

***What is Bash?***

Bash is the shell, or command language interpreter, for the GNU ***(GNU's Not Unix)***. While Bash stands for ***Bourne-Again Shell***.

### ***Definitions***

- **word** : sequence of ***characters*** considered to be a single unit.
- **list** : sequence of ***commands*** or ***pipelines***
- **name** : a ***word*** consisting only a alphanumberic characters and underscores. can <ins>not</ins> begin with a numeric character.
- **parameter** : an ***entity*** that stores ***values***. a variable is a parameter denoted by a **name**; there are also _positional_ and _special_ parameters.

## ***Purpose***
Bash `scripting` is a great way to automate tasks within a ***GNU*** operating system to make navigating through information easy. It is fully customizable to satisfy the specific needs of the ***user***. This project is a great way to utilize the command line and get use to many linux commands.

## ***Prerequisites***

* Command line [downloand linux here](https://ubuntu.com/desktop/wsl)

## ***Section 1: Introduction***

### ***Scripting Basics***

The _shebang_ or `#!/bin/bash` or `#!/usr/bin/env bash` is the first shell script that has to be included to be able to intreprete the specific programing that is being utilized.

> [!CAUTION]
> Without the _shebang_ the code will not be able to interpret the script


```bash
#Examples of defining the right language

#!/bin/bash
#!/usr/bin/env bash
#!/usr/bin/env python
#!/usr/bin/env c

# Notation
#!/usr/bin/env [programing language]

or

#!/usr/bin/env bash [more portable]
#!/bin/bash [also seen]
```

### ***Where Are Commands***

To find out which command path that it is preforming from do `which command`.

```bash
$which ls
/usr/bin/ls
```
You can find the path of these specific commands by typing `$PATH`. This is where all the executeables are and when calling the command it will look in the `$PATH` directories to execute it.
> [!TIP]
> You can make a `bash.sh` script and `mv` it into one of the `$PATH` directories and you won't need to be in the same directory of the `bash.sh` script. You'll be able to run it any where within the shell.

Also you can add your own path in the $PATH file by doing:

```bash
# This will append your $HOME/usr/bin in front of your $PATH meaning it will search here first and if it can't find it here it will move to the next $PATH directory to execute

PATH=$HOME/usr/local/bin:$PATH
# To remove this path from $PATH
PATH=${PATH#*:}
# This removes contents from the first : starting from the left side

# This will append it to the end of the $PATH rather than the front

PATH=$PATH:~/usr/local/bin
# to remove this from $PATH
PATH=${PATH%:*}

# This removes contents from the first : starting from the right side
```

> [!CAUTION]
> This will only set your $PATH during that current shell session. Once you leave the session it will reset back to original state.
 
To configure your $PATH configuration make a `$HOME/.bashrc` and type:
`export PATH=$HOME/usr/bin:$PATH`

The `.sh` on a bash script is technically not needed but the reason it is added is to to get a clear visualization that it is indeed a bash script. As long as the file has a shebang `#!/bin/bash` or `#!/usr/bin/env bash` it will know it is a bash script.

To check what type of file a file is you can use the `file` command along with the file you want to check.

Example
```bash
file script.sh

# Output
script.sh: Bourne-Again shell script, ASCII text executable
```

> [!WARNING]
> Just because it has a `.sh` does not mean that it is a bash script. It has to have the shebang in the file!

Example
```bash
cat script.sh

# Output
hello

file script.sh
# Output
script.sh: ASCII text

#####################
#### Compared to ####
#####################

cat script
# Output

#!/usr/bin/env bash
echo "HELLO WORLD"

file script
# Output
script: Bourne-Again shell script, ASCII text executable
```

### ***Variables***

* Variables could be initiated with the variable name equal to the contents. 
* Must begin with a letter or an underscore
* Any character excepter the first can be a number
* No spaces between the variable the = sign

> [!TIP]
> _Best practice_   
> * Variable names in all CAPS  
> * Variable spaces used underscores _  
> * Variable "contents" enclosed with quotation
> * Enclose contents in `${BRACKETS}`

```bash
# EXAMPLE

VARIABLE_NAME="contents"
FIRST_NAME="Jarron"
LAST_NAME="Racelis"
COLOR="BLUE"
WORK_DIRECTORY="/jracelis/bash-learnings/READMD.md"
```

* To call the variables within the script use the dollar sign `$` +  `{VARIABLE_NAME}` the variable name 

```bash
# Variables

FAV_COLOR="blue"
WORK_DIRECTORY="/jracelis/bash-learnings/READMD.md"

# Command Line
echo "My favorite color is ${FAV_COLOR}"
cd ${WORK_DIRECTORY}

```

### ***Syntax***

To understand how shell scripts work it is important to know syntax of how `commands` operate.

Take the following example in the shell
```bash
# Lets say you ls in your ~ directory
ls -a ~ 

# Output 
DOCUMENTS DOWNLOADS .ssh .git
```

You can preform multiple `commands` in one line from left to right by adding a `;` between each `command`

Example
```bash
cd DOWNLOADS; touch text.txt; mv text.txt ~

# Now lets break down what we just did and what it does

# Changes directories into DOWNLOADS 
~$cd DOWNLOADS 
# OUTPUT
user@ubuntu~/DOWNLOADS$
# touch text.txt creates text.txt in current working directory which is DOWNLOADS
user@ubuntu~/DOWNLOADS$ touch text.txt
# OUTPUT
user@ubuntu~/DOWNLOADS$ touch text.txt
# mv text.txt to home directory ~
user@ubuntu~/DOWNLOADS$ mv text.txt ~
# OUTPUT
user@ubuntu~$ text.txt
cd DOWNLOADS -> touch text.txt -> mv text.txt ~

# You can preform the same output by typing each command line by line like this

cd DOWNLOADS
touch text.txt
mv text.txt ~

# By doing this you get the same results except you type each command and use the return key 3 times rather than once
```
Now use these principles on bash scripting
```bash
#!/usr/bin/env bash

# Using the knowledge we know from the previous example technically we can write the same task in script form...calling it practice.sh

cd DOWNLOADS; touch text.txt; mv text.txt ~

# This will give us the same output as the first example but this notation does not look as clean. With the shell script it treats the script name as one long list of commands to be preformed on a shell.

# Example this can be rewritten as:

cd DOWNLOADS
touch text.txt
mv text.txt ~

# Notice this is like typing each command and returning it in a shell terminal to get the same output. Each newline represents a new command.
```

***Pipes and Redirection***

* The pipe symbol `\|` sends the output of one process to anoter
	* `ls | wc -l`
* Redirections end streams of (stdin, stdout and stderr) to or from files
	* `ls > list.txt`

Redirection

| Stream | Name | Content |
|:---:|:---|:---|
| 0 | Standard input (stdin) | Keyboard or other input
| 1 | Standard output (stdout) | Regular output
| 2 | Standard error (stderr) | Output marked as `error`

| Symbol | Function |
|:---:|:---|
| > | Output redirection (truncate)
| >> | Output redirection (append)
| < | Input redirection
| << | Here document

Example
```bash
# Redirection
ls > list.txt
cat list.txt
Downloads
Documents
myFiles
# This lists the out of the contents into the file list.txt

# To redirection stderr 2
# To redirection stdin 1
ls /random 1>output.txt 2>error.txt

# To use input redirection
cat < README.md
# This lists all the contents in the README.md without having to type cat README.md using the input of README.md to cat the information

# To use Here document <<
cat << EndOfText
> This is a 
> multiline
> test string
> EndOfText
This is a
multiline
text string
# Notice when I use can on << EndOfText it stop at the specific word
```

> [!NOTE]
> Standard output (stdout) `1` is assumed in redirection

Key Differences
* Piping is used to send streams from one command to another.
* Redirection is used to send streams to and from files.

### ***Help Commands***  

***bash*** consists of two types:
* builtin
* command
To see if a command is a built do the following:
```bash
command -V df
df is /usr/bin/df
command -V echo
echo is a shell builtin

# To run the command or built in just add the following keyword to the beginning
command echo hello
builtin echo
```
The main difference is that builtins takes precedents over commands.

To disable specific builts just used `enable -n [builtin]`.
```bash
enable -n echo
command -V echo
echo is /usr/bin/echo
# Note they are using different command version 
```
* Use `enable -n` to see the disable built ins.
* Built ins use a different documentation than `man` just use `help [bulitins]` or `help`

> [!Note]
> For more information use the following commands to go more indepth into the concepts

- `type`: determined type of command, list contets of aliases and functions.
- `help` : display usagage information about bash bultins and keywords
- `apropos` : search man pages
- `man` : system manual
- `info` : advanced manual system primarily used for GNU programs.


## ***Section 2: Advanced Bash Concepts***

* `echo` is used to display text and end with a new line character `\n`
* `printf` is used to format and print data and does not include `\n`

Example
```bash
echo hello there
hello there
$
# Compared to print
printf hello there
hello there$
# Noticed that the $ sign is added with hello there because it did not include and new line
```
### ***Return Status***

```bash
Success: Command should return a status of 0.

Failure: Command should return a non-zero status.

> Return values can range from 0 to 255
> The return value of the last command to have executed is captured in the special parameter $?
```

Example
```bash
mkdir file
echo $?
0
cd random  
bash: cd: random: No such file or directory
echo $?
1
```

### ***Arrays***

Arrays is a data structure that stores a collection of elements of the same data type, like numbers and strings, using a single variable name. To declare a variable the notation is as follows.

```bash
myArray=(hi joe jim)
```

For arrays they are seperated by a space in between in string/number. To add a string with spaces they will be contained in `""` quotation marks.\
Example:\
`myARRAY=("joe" "him" "foo joe")`

Like many programming languages the array uses zero-based numbering meaning the array `myARRAY[0]=joe` and `myARRAY[1]=him` and so on.

Tricks and Tips:
```
# To get the size of an array use
$#myArray[@]
# To go through the list of all the arrays use
$myArray[@]
# To skip or start at a specific location on the array
${myArray[@]:1}
# The following mean starts at myArray[1]=him
```

### ***Compound Commands***

#### ***Iteration:***

Continuously loop over **list** of commands delineated by the keywords of `do` and `done`.

```bash
#Example
                    while until for select
```

<details>
<summary>While and Until Loops</summary>

---
**While and Until Loops**  
_(Typically) iterate based on an external resource_ 

`while` **list1**; `do` **list2**; `done`

> execute **list1**l if **success**, execute **list2** and repeat.  
> continue unit **list1** returns a **non-zero** status _(fails)_.

---

`until` **list1**; `do` **lists2**; `done`

> execute **list1**; if **failure**, execute **lists2** and repeat.  
> continue unit **list1** returns a status of **0** _(succeeds)_.

</details>

<details>
<summary>For and Select Loops</summary>

**For and Select Loops**  
_Iterate based on command line arguments_

`for` **name** `in` **words**; do **list**; `done`

> During each iteration, assign **name** the value of the next **word**, then execute **list**. Repeat until all **words** have been exhausted.

***C programming notation***
      
`for` (( **initialization** ; **condition**; **afterthought** )); `do` **list**; `done`

> Evaluate **initialization**, then loop of **list** of commands untill **condition** returns non-zero status _(fails)_. After each iteration, evaluate **afterthought**. The expressions are evaluated as _arithmetic expressions_.

---

`select` **name** `in` **words**; `do` **lists**; `done`

> Create a menu item for each **word**. Each time the user makes a selection from the manu, **name** is assigned the value of the selected **word** and **REPLY** is assigned the **index** number of the selection.

<details>
<summary>Select Example</summary>

```bash
INPUT
#!/usr/bin/env bash

#Variable Array

myName=( "Jarron" "Racelis" "Joe Bob" )

function choose_name {

select choice in "${myName[@]}"; do
    # $REPLY just outputs number correspnding to choice.
    # Example myName="Jarron" is:
    # 1) Jarron
    # Exmaple continue myName="Racelis" etc:
    # 2) Racelis
    echo "$REPLY": You choose ${choice}  
done
}
```

```
OUTPUT

1) Jarron
2) Racelis
3) Joe Bob
#? 1 <---- Enter Input and Below is the Output
1 : You choose Jarron
```

</details>

</details>

#### ***Conditionals:***

Execute **list** of commands only if certain conditions are met.

```bash
#Example
                          if  case
```

<details>

<summary> if and Case Statements</summary>

`if` **list1**; `then` **list2**; `fi`

* Evaluate **list1**, then evaluate **list2** only if **list1** returns a status of **0**.

`if` **list1**; `then` **list2**; `else` **list3**; `fi`

* Evalue **list1**, then evaluate **list2** only if **list1** returns a status of **0**. Otherwise, evaluate **list3**.

`if` **list1**; `then` **list2**; `elif` **list3**; `then` **list4**; `else` **list5**; `fi`

* Evaluate **list1**, then evaluate **list2** only if **list1** returns a status of **0**. Otherwise, evaluate **list3**, then evaluate **list4** only if **list3** return a status of **0**. Otherwise, evaluate **list5**.

---

***Pattern Matching***  

_Pattern matching is used in Bash for the **[[** and `case` keywords, **pathname expansion** and some types of **parameter expansion**_.

* **\*** : Matches any string, including null.  
* **?** : Matches any single character.  
* **[character class]** : Matches any one of the characterse enclosed between **[** and **]**.

* **[^...]** : Matches the complement (any character not in the class)  
* **[x-z]** : Matches the range of characters from **x** to **z**  
* **[[:class:]]** : Matches according to these POSIX classes:  
**alnum alpha assii blank cntrl digit graph lower print punct space**

---

`case` **word** `in`  
`pattern1`  
**list1** ;;  
`pattern2` | `pattern3`)  
**list2**;;  
`esac`

* Match **word** against each **pattern** sequentially. When the first match is found, evaluate the **list** corresponding to that match and stop matching.

* The **|** (pipe) character between two patterns entails a match if either pattern matches **(OR)**.

</details>

#### ***Conditional Tests***

`test`

**[expression]** or `test` **expression**

> Evaluate _conditional expression_ with the `test` builtin.

**[[expression]]**

> Evaluate _conditional expression_ with the **[[** keyword; word splitting <ins>not</ins> preformed. The righthand side of a string comparison ( **==** , **!=** ) is treated as a **pattern when not quoted**, and as a **string when quoted**.

| `test`     |       Definition        |
|---------|------------------------------------------------|
| **[[ -n string ]]**                | **string** is _non-empty_                      
| **[[ -z string ]]**                | **string** is _empty_
| **[[ string1 == string2 ]]**     | **string1** and **string2** are _same_
| **[[ string1 != string2 ]]**      | **string1** and **string2** are _not the same_
| **[[ string =~ regex ]]**         | **string** _matches_ **regular expression**
| **[[ -e file ]]**                | **file** _exists_
| **[[ -f file] ]**                  | **file** is a _regular file_
| **[[ -d file ]]**                | **file** is a _directory_
| **[[ -t fd ]]**                  | **fd** is _open_ and refers to a _terminal_

#### ***Command groups:***

Grouped **list** of commands, sharing any external redirections and whose return value is that of the **list**

```bash
#Example
                      (list) {list;}
```

<details>
<summary>Command Groups</summary>

***Subshell***:

* Evaluate **list** of commands in a ***subshell***, meaning that its environment is distinct from the current shell and its parameters are contained.  
```bash
                         (list)
```
**Group Command**: 

* Evaluate **list** of commands in the ***current shell***, sharing the current shell's environment.
```bash
                         {list;}
```

</details>

---

## ***Section 3: STDIN, STDOUT, STDERROR***

### ***Redirection***

_Controlling the input, output, error, and other streams_

| Operation          |     Description               |
|--------------------|-------------------------------|
| `list > file`| overwrite/create **file** with ***output*** from **list**
| `list >> file` | append/create **file** with ***output*** from **list**
| `list < file`  | feed **file** to **list** as ***input***
| `list1 \| list2` | use ***output*** from **list1** as ***input*** to **list2**

* If not specified, `fd 1` **(STDOUT)** is assumed when redirecting output  
* Alternative file descriptors may be specified by **prepending** `fd number`, e.g `2>file` to redirect `fd 2` **(STDERR)**
* To redirect to a file descriptor, append ***&*** and the fd number, e.g `2>&1` to redirect ***STDERR*** to the current target ***STDOUT***.

### ***Manipulating Output***

There are two commands that I will touch on when it comes to manipulating output on the terminal. 

| Command   | Description  |
|-----------|--------------|
| `echo`    | display a line of text|
| `printf`  | format and print data |

***ANSI***

_Colored Text (ANSI)_

| Color    | Foreground(Text Color) | Background (Text Highlight) |
| :---:|          :---:                              | :---: |
| Black    |    30                  |   40  
| Red      |    31                  |   41                         |
| Green    |    32                  |   42
| Yellow   |    33                  |   43
| Blue     |    34                  |   44
| Magenta  |    35                  |   45
| Cyan     |    36                  |   46
| White    |    37                  |   47

_Syled text (ANSI)_

| Style | Value |
| :---: | :---: |
| No Style | 0 |
| Bold     | 1 |
| Low Intensity | 2 |
| Underline | 4 |
| Blinking  | 5 |
| Reverse   | 7 | 
| Invisible | 8 |

<details>
<summary>ANSI Example</summary>

```bash
#!/usr/bin/bash

# \033 is a escape character (ASCII 27)
# -e allows escape characters
# [1 = Bold Text
# [34 = Font Color Green 
# [40 = Highlight Text Black
# [0m = Resets color and attributes
# Refer to the ANSI table above to adjust for you liking

echo -e "\033[1;34;42mText\033[0m"

OR

printf "\033[1;34mText\033[0m"
```

</details>

---

***Tput***

_Colored Text (tput)_

| Color | setaf(Text Color) | setab(Text Highlight) |
| :---: | :---: | :---: |
| Black | 0 | 0 |
| Red | 1 | 1 |
| Green | 2 | 2 |
| Yellow | 3 | 3 |
| Blue | 4 | 4 |
| Magenta | 5 | 5 |
| Cyan | 6 | 6 |
| White | 7 | 7 |
| Not Used | 8 | 8 |
| Reset to default | 9 | 9 |

_Styled Text (tput)_

| Style | Command |
| :---: | :---: |
| Foreground | tput setaf [0-9]
| Background | tput setab [0-9]
| No Style | tput sgr0
| Bold | tput bold
| Low Intensity | tput dim
| Underline | tput smul
| Blinking | tput blink
| Reverse | tput rev

<details>
<summary>Tput Exmaple</summary>

```bash
#!/usr/bin/env bash

function color_change_tput {

  echo "$(tput setaf 1; tput bold)ERROR: $(tput setaf 7; tput sgr0) INVALID INPUT"

  # ERROR text is red and bolded
  # INVALID INPUT text is white and reset to default

  or

  printf "$(tput setaf 1; tput bold)ERROR:\t $(tput setaf 9; tput sgr0) INVADLID INPUT"

}
```

</details>

## ***Section 4: Parameter Manipulation***

### ***Parameters***

**Postional Parameters:** `$1 $2 $3 $4 $5 $6 $7 $8 $9 ${10}`  

* Parmeters passed to command, encapsulating ***words*** on the command line as ***arguments***.

**Special Parameters:** `$* $@ $# $- $0 $! $? $_`

|***Special Parameters*** | Description   |
|:---: |---------------|
| `$@` | returns all values of argument |
| `$#` | returns total number of arguements |
| `$0` | returns file name of the script |
| `$?` | returns the exit status of last command |
| `$$` | returns the PID (process ID) of the script |
| `shift` | number of arguements are reduced each time as the shift command executes |


* Parameters providing ***information*** about positional parameters, the current shell, and the previous command.

---

#### ***Parameter Expansion: Conditionals***

***"param" = parameter***

|          | **unset** param | param="" | param="**gnu**" |
|----------| :---: | :---: | :---: |
| `${param-default}` | default | - | gnu |
| `${param=default}` | name=default | - | gnu |
| `${param+alternate}` | - | alternate | alternate |
| `${param?error}` | error | - | gnu |

**Treat empty as unset:**

|          | **unset** param | param="" | param="**gnu**" |
| ---------| :---: | :---: | :---: |
| `${param:-default}` | default | default | gnu |
| `${param:=default}` | name=default | name=default | gnu
| `${param:+alternate}` | - | - | alternate |
| `${param:?error}` | error | error | gnu

---

#### ***Parameter Expansion: Substring***

|       |     Output      |
|-------|:---:|
| **Extraction:** | offset of **3**,length of **2** |
| `${param:offset}` | ecar |
| `${param:offset:length}` | ce |
| **Removal from left edge:** | pattern is '***c**' |
| `${param#pattern}` | ecar |
| `${param##pattern}` | ar |
| **Removal from right edge:** | pattern is '**c*** |
| `${param%pattern}` | race |
| `${param%%pattern}` | ra |

> Can use ${param:} for output maniuplation
```bash
PARAM="thought"

${PARAM:3} = "ught" it "offsets" 3 letters from left to right
${PARAM:3:2} = "ug" "ofsets" 3 with a length of 2 characters

# Noticed the * is on the left of the pattern therefore removing everything starting from the pattern and leftwards
${PARAM#*u} = "ght" it removes everything from the first u untill the left

# Noticed the * is on the right of the pattern therefore removing everything starting from the pattern and rightwards
${PARAM%u*} = "tho" it removes everything from the first u untill the right

```

---

#### ***Parameter Expansion: Indirection, Listing, and Length***

|   | param="**parade**";parade="**long**";name=(**gnu not unix**) 
|---|:---:|
| **Indirect expansion:** |
| `${!param}` | long |
| **List names mataching prefix "**pa**": |
| `${!pa*}` or `${!pa@}` | parade param |
| **List keys in array:** |
| `${!name[*]}` or `${!name[@]}` | 0 1 2 |
| **Expand to length:** | |
| `${#param}` | 6 | 

#### *** Parameter Expansion: Pattern Substitution***

| | `param="**racecar**"
|---|---|
|**Substitution:** | `pattern is '**c?**', string is '**T**'` |
| `${param/pattern/string}` | ra**T**car |
| `${param//pattern/string}` | ra**TT**r |
| **Substitute at left edge:** | `pattern is '**r**', string is '**T**`
| `${param/#pattern/string}` | **T**acecar |
| **Substitute at right edge:**| |
| `${param/%pattern/strig}` | raceca**T** |

## ***Appendix***

### ***Table References***

#### ***Bash Operators***

| Comparison Operators  | Description |
|-------|---------------------------------|
| `-eq` | equal to
| `-ne` | not equal to
| `-lt` | less than
| `-le` | less than or equal to
| `-gt` | greater than
| `-ge` | greater than or equal to 

| String Comparison     | Description   |
|---------|-----------------------------|
| `=`     | equal to
| `!=`    | not equal to
| `<`     | less than, in ASCII alphabetical order
| `>`     | greater than, in ASCII alphabeteric order
| `-z`    | checks if the given string operand size is zero
| `-n`    | checks if the given string operand size is non-zero

| Arithmetic Operators | Description    |
|---------|-----------------------------|
| `+`     | addition
| `-`     | subtraction
| `*`     | multiplication
| `/`     | division
| `%`     | modulus (remainer of divison)

| Logical Operators | Description |
|-------------------|-------------|
| `&&`    | logical AND
| `\|\|`    | logical OR
| `!`     | logical NOT

| File Test Operators | Description |
|---------------------|-------------|
| `-e` | checks if a file exists
| `-d` | checks if a directory exists
| `-f` | check if a file is regular file
| `-s` | checks if a file is not empty (non-zero)
| `-r` | checks if a file has read access (owner)
| `-w` | checks if a file has write permission (owner)
| `-x` | checks if a file has execute permission (owner)

#### ***Commands***

| Commands    | Description                          |
|-------------|-------------------------------
| `echo`      | to display output                             
| `printf`    | to print and format output
| `cd`        | to change directories
| `ls`        | to list contents in directory
| `pwd`       | print working directory
| `rm`        | remove file
| `rmdir`     | remove directory
| `mkdir`     | make directory
| `touch`     | to change file timestamps or create an empty file if ti doesn't exist
| `whereis`   | 
| `locate`    |
| `whatis`    |
| `chmod`     | change file mode
| `grep`      | to search for text patterns within files
| `awk`       | used for pattern scanning and processing language
| `sort`      | to sort lines of text files
| `find`      | to find a specific name/file/folder
| `sed`       | a stream editor used to preform basic text ransformations on an input stream (a file or input from a pipeline).
| `paste`     | 
| `cut`       | to remove sections from each line of files
| `pv`        | pipe viewier
| `diff`      |
| `tar`       | to archive or unarchive a file/folder (can also zip with the -z flag)
| `zstd`      | to unzip a .zst file
| `ssh-keygen`| 
| `ssh`       | to connect to a remote machine securely
| `scp`       | to securely copy files between hosts on a network
| `tail`      | to display the last parts if files
| `head`      | to display first part of files
| `curl`      | to transfer data from or to a server using various protocols like HTTP, HTTPS, FTP and more.
| `wget`      | to download files from the web

## References

### ***Links***
- [ ] [Advanced Bash Usage](https://youtube.com/watch?v=uqHjc7hlqd0) by [James Pannacciullia](https://youtube.com/@jamespannacciulli3029)
- [ ] [Advanced Bash Scripting Tutorial](https://youtube.com/watch?v=embhouufDnB4&t=2675s) by [Cybersecurity Shandy](https://youtube.com/@cybersecurityshandy9181)
