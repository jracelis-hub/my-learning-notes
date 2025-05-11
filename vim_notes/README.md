# VIM Notes

## ***Table of Contents***

* [_Introduction_](#introduction)
* [_Tables_](#tables)


## ***Introduction***

***What is VIM***

Vim or (Vi IMproved) is a power text editor which is an improved version of Vi (Visual Editor).

* When you use `:` that is calling a command within ***vim***.
* When you used `:!` then you are calling a command within the terminal.

Example
```
vim file.txt
:!ls
# This will list the files within current directory as if you did it on the command line
```

## ***Tables***

Good to know hotkeys for Vim

| Insert Mode | Description |
|:---:|:---------------|
| `i` | to go into insert mode at the location of your cursor |
| `I` | insert at the begginng of the line |
| `a` | insert (append) after the cursor |
| `A` | insert (append) at the end of the line |
| `o` | append (open) a new line below the current line |
| `O` | append (open) a new line above the current line |
| `crtl` + `h` | delete character before the cursor during insert mode |
| `crtl` + `w` | delete word before the cursor during insert mode |
| `crtl` + `j` | add a line break at the cursor position during insert mode |
| `crtl` + `t` | indent (move right) line on shiftwidth during insert mode |
| `crtl` + `d` | de-indent (move left) line one shiftwidth during insert mode |
| `esc` or `crtl` + `c` | exit insert mode |

| Cursor Movement | Description |
| :---: |:---------------------|
| `h` | move cursor left |
| `j` | move cursor down |
| `k` | move cursor up |
| `l` | move cursor right |
| `gj` | moves cursor down (multi-line text)
| `gk` | moves cursor up (multi-line text)
| `H` | move to top of screen |
| `M` | move to middle of screen |
| `L` | move to bottom screen |
| `gg` | go to the first line of the document |
| `G` | go to the last line of the document |
| `w` | jump forwards to the start of a word |
| `W` | jumps forwards to the start of a word (words can contain punctuation) |
| `e` | jumps forwards to the end of a word |
| `E` | jumps fowards to the end of a word (words can contain punctuation |
| `b` | jumps backwards to the start of a word |
| `B` | jump backwards to the start of a word (words can contain punctuation) |
| `0` | jump to the start of the line |
| `$` | jump to end of the line |
| 


### ***How to Setup Config***

In your `$HOME` or `~` directory make a file called `vimrc`

```bash
cd $HOME
vim vimrc
```

Specific Configuration Table

|Purpose| Description|
|:---:|:------|
| `set number` | to add line numbers on your vim console |
| `set shiftwidt=number` | indent size of shift width |
| `set tabstop=number` | tab size |

> [!NOTE]
> To add comments use `"` before the newline 
