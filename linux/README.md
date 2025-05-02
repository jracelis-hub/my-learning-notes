# Linux && Bash Scripting

## Table of Contents

* [Purpose](#purpose)
* [Chapter 1](#chapter-1)
  * _Scripting Basics_
  * _Variables_
  * _ifstatements_

## Purpose
Bash `scripting` is a great way to automate tasks within ***linux*** to make navigating through information easy. It is fully customizable to satisfy the specific needs of the ***user***. This project is a great way to utilize the command line and get use to many linux commands.

## Prerequisites

* Command line [downloand linux here](https://ubuntu.com/desktop/wsl)

### Chapter 1 

---
_Scripting Basics_

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

<details>
<summary>Bash Operators</summary>

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

</details>


<details>
<summary>Commands Cheat Sheet</summary>

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



</details>

---

_Variables_

* Variables could be initiated with the variable name equal to the contents. 
* Must begin with a letter or an underscore
* Any character excepter the first can be a number
* No spaces between the variable the = sign

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

> [!TIP]
> _Best practice_   
> * Variable names in all CAPS  
> * Variable spaces used underscores _  
> * Variable "contents" enclosed with quotation
> * Enclose contents in `${BRACKETS}` 

---

_if statements_

* if the following statement passes the given statement then it will preform the script within the if statement
* To close if statement is requires `fi`

NOTATION

```bash
#!/bin/bash

FAV_COLOR="blue"

if [ ${FAV_COLOR} = "blue" ]; then
  echo "BLUE IS MY FAVORITE COLOR"
fi
```

Adding the `else` statement to the if statement if the following statement is not true then preform what is in the else statement.

```bash
#!/bin/bash

FAV_COLOR="blue"

if [ ${FAV_COLOR} = "blue" ]; then
  echo "BLUE IS MY FAVORITE COLOR"
else
  echo "THIS ISN'T MY FAVORITE COLOR"
fi
```

### Advanced Bash Concepts
---

_Return Status_

```bash
Success: Command should return a status of 0.

Failure: Command should return a non-zero status.

> Return values can range from 0 to 255
> The return value of the last command to have executed is captured in the speical parameter $?
```

_Definitions_

- **word** : sequence of ***characters*** considered to be a single unit.
- **list** : sequence of ***commands*** or ***pipelines***
- **name** : a ***word*** consisting only a alphanumberic characters and underscores. can <ins>not</ins> begin with a numeric character.
- **parameter** : an ***entity*** that stores ***values***. a variable is a parameter denoted by a **name**; there are also _positional_ and _special_ parameters.

_Compound Commands_

Iteration:

Continuously loop over **list** of commands delineated by the keywords of `do` and `done`.

```bash
#Example
                    while until for select
```

<details>
<summary>While and Until Loops</summary>

---
While and Unit Loops  
_(Typically) iterate based on an external resource_ 

`while` **list1**; `do` **list2**; `done`

> execute **list1**l if **success**, execute **list2** and repeat.  
> continue unit **list1** returns a **non-zero** status _(fails)_.

---

`unitil` **list1**; `do` **lists2**; `done`

> execute **list1**; if **failure**, execute **lists2** and repeat.  
> continue unit **list1** returns a status of **0** _(succeeds)_.

---

For and Select Loops
_Iterate baed on commad line arguements_

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
#!/usr/bin/env bash

#Variable Array

myName=( "Jarron" "Racelis" "Hayeon" )

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

OUTPUT

1) Jarron
2) Racelis
3) Hayeon
#? 1 <---- Enter Input and Below is the Output
1 : You choose Jarron

```

</details>

---

`test`

**[expression]** or `test` **expression**

> Evaluate _conditional expression_ with the `test` builtin.

**[[expression]]**

> Evaluate _conditional expression_ with the **[[** keyword; word splitting <ins>not</ins> preformed. The righthand side of a string comparison ( **==** , **!=** ) is treated as a **pattern when not quoted**, and as a **string when quoted**.

| `test`                           | Definition                                     |
|----------------------------------|------------------------------------------------|
| **[[-n string]]**                | **string** is _non-empty_                      
| **[[-z string]]**                | **string** is _empty_
| **[[ string1 == string2 ]]**     | **string1** and **string2** are _same_
| **[[ string1 != string2 ]]**      | **string1** and **string2** are _not the same_
| **[[ string =~ regex ]]**         | **string** _matches_ **regular expression**
| **[[ -e file ]]**                | **file** _exists_
| **[[ -f file] ]**                  | **file** is a _regular file_
| **[[ -d file ]]**                | **file** is a _directory_
| **[[ -t fd ]]**                  | **fd** is _open_ and refers to a _terminal_

</details>

---
Conditionals:

Execute **list** of commands only if certain conditions are met.

```bash
#Example
                          if  case
```

<details>

<summary> if and Case Statements</summary>

`if` **list1**; `then` **list2**; `fi`

* Evaluate **list1**, then evaluate **list2** only if **list1** returns a status of **0**

`if` **list1**; `then` **list2**; `else` **list3**; `fi`

* Evalue **list1**, then evaluate **list2** only if **list1** returns a status of **0**. Otherwise, evaluate **list3**.

`if` **list1**; `then` **list2**; `elif` **list3**; `then` **list4**; `else` **list5**; `fi`

* Evaluate **list1**, then evaluate **list2** only if **list1** returns a status of **0**. Otherwise, evaluate **list3**, then evaluate **list4** only if **list3** return a status of **0**. Otherwise, evaluate **list5**.

---

Pattern Matching
_Pattern matching is used in Bash for the **[[** and `case` keywords, **pathname expansion** and some types of **parameter expansion**_

* **\*** : Maches any string, including null.  
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

Command groups:

Grouped **list** of commands, sharing any external redirections and whose return value is that of the **list**

```bash
#Example
                      (list)  {list;}
```

<details>
<summary>Command Groups</summary>

**Subshell**:

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

_Redirection_

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

_Help Commands_

- `type`: determined type of command, list contets of aliases and functions.
- `help` : display usagage information about bash bultins and keywords
- `apropos` : search man pages
- `man` : system manual
- `info` : advanced manual system primarily used for GNU programs.

***Links***
- [ ] [Advanced Bash Usage](https://youtube.com/watch?v=uqHjc7hlqd0) by [James Pannacciullia](https://youtube.com/@jamespannacciulli3029)
- [ ]