# Linux && Bash Scripting

## Table of Contents

* [***Terminology***](#terminology)
  * [_What is Bash?_](#what-is-bash)
  * [_Definitions_](#definitions)
* [***Purpose***](#purpose)
* [***Prerequisites***](#prerequisites)
* [***Section 1: Introduction***](#section-1-introduction)
  * [_Scripting Basics_](#scripting-basics)
  * [_Variables_](#variables)
  * [_Help Commands_](#-help-commands)
* [***Section 2: Advanced Bash Concepts***](#section-2-advanced-bash-concepts)
  * [_Return Status_](#return-status)
  * [Compund Commands](#compound-commands)
    * [_Looping Contructs_ ***(While, Until, For, Select)***](#looping-constructs)
    * [Conditional Constructs ***(If, Case, Test)***](#condition-constructs)
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

### ***What is BASH?***
Bash is the shell, or command language interpreter, for the GNU ***(GNU's Not Unix)***. While Bash stands for ***Bourne-Again Shell***

### ***Definitions***

- **word** : sequence of ***characters*** considered to be a single unit.
- **list** : sequence of ***commands*** or ***pipelines***
- **name** : a ***word*** consisting only a alphanumberic characters and underscores. can <ins>not</ins> begin with a numeric character.
- **parameter** : an ***entity*** that stores ***values***. a variable is a parameter denoted by a **name**; there are also _positional_ and _special_ parameters.
- **POSIX**: _portable operating system interface_ a family of open system standards based on Unix.

## ***Purpose***
Bash `scripting` is a great way to automate tasks within a ***GNU*** operating system to make navigating through information easy. It is fully customizable to satisfy the specific needs of the ***user***. This project is a great way to utilize the command line and get use to many linux commands.

## ***Prerequisites***

* Command line [downloand linux here](https://ubuntu.com/desktop/wsl)

## ***Section 1: Introduction***

### ***Scripting Basics***

The _shebang_ or `#!/bin/bash or #!/usr/bin/env bash` is the first shell script that has to be included to be able to intreprete the specific programing that is being utilized.

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

### ***Help Commands***  

> [!Note]
> For more information use the following commands to go more indepth into the concepts

- `type`: determined type of command, list contets of aliases and functions.
- `help` : display usagage information about bash bultins and keywords
- `apropos` : search man pages
- `man` : system manual
- `info` : advanced manual system primarily used for GNU programs.


## ***Section 2: Advanced Bash Concepts***

### ***Return Status***

```bash
Success: Command should return a status of 0.

Failure: Command should return a non-zero status.

> Return values can range from 0 to 255
> The return value of the last command to have executed is captured in the special parameter $?
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
| `-s` | checks ifa file is not empty

#### ***Commands***

| Commands    | Description                          |
|-------------|-------------------------------
| `echo`      | to display output                             
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