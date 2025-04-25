# Linux && Bash Scripting

## Table of Contents

* [Purpose](#purpose)
* [Chapter 1](#chapter-1)
  * _Scripting Basics_
  * _Variables_
## Purpose
Bash `scripting` is a great way to automate tasks within linux to make navigating through information easy. It is fully customizable to satisfy the specific needs of the user. This project is a great way to utilize the command line and get use to many linux commands.

## Prerequisites
* Command line [downloand linux here](https://ubuntu.com/desktop/wsl)

### Chapter 1 
---
_Scripting Basics_

The _shebang_ or `#!/bin/bash` is the first shell script that has to be included to be able to intreprete the specific programing that is being utilized.

> [!CAUTION]
> Without the _shebang_ the code will not run properly


```bash
#Examples

#!/bin/bash
#!/usr/bin/env bash
#!/usr/bin/env python
#!/usr/bin/env c
#!/usr/bin/env c++

# Notation
#!/usr/bin/env [programing language]

or

#!/bin/bash [generally the case]
```

<details>

<summary>Commands Cheat Sheet</summary>

| Commands | Description           |
|----------|-----------
| echo     | to display output                             
| cd       | to change directories
| ls       | to list contents in directory
| chmod    |
| grep     |
| awk      |
| sort     |
| find     |
| 

</details>

---

_Variables_

Variables could be initiated with the variable name equal to the contents. 

```
# EXAMPLE

VARIABLE_NAME="contents"
FIRST_NAME="Jarron"
LAST_NAME="RACELIS"
COLOR="BLUE"
WORK_DIRECTORY="/jracelis/bash-learnings/READMD.md"
```

> [!NOTE]
> **Best practice**   
> Variable names in all CAPS  
> Variable spaces used underscores _  
> Variable "contents" enclosed with quotation

To call the variables within the script use the dollar sign `$` +  `{VARIABLE_NAME}` the variable name 

```
# Variables

FAV_COLOR="blue"
WORK_DIRECTORY="/jracelis/bash-learnings/READMD.md"

# Command Line
echo "My favorite color is ${FAV_COLOR}"
cd ${WORK_DIRECTORY}

```
> [!NOTE]
> **Best Practice**  
> Enclose contents in `${BRACKETS}` 