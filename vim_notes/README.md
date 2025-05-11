# Vim Knowledge

## ***Table of Contents***

* [_Introduction_](#introduction)
* [_How To_](#how-to)
	* [_Navigate Through Vim_](#how-to-navigate-through-vim)
	* [_Setup Config_](#how-to-setup-config)
* [_Cheatsheets_](#cheatsheets)


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

## ***HOW To***

### ***How to Navigate Through VIM***

* To jump to a specific line use `:n` where n is the line number shown on the left.
* To jump to the end of the page `G`
* To jump to the beginning of the page `gg`
* To jump to beginning of the line `0`
* To jump to end of the line `$`
* To jump to beginning of word going right `w`
* To jump to beginning of word going back `b`

> [!TIP] 
> You can use the navigation keys `w` `b` `e` with other commands like `d` (deletion) `c` copying

### ***How to Delete, Copy, and Paste***

_Delete_

* To delete a line `dd` 
	* Add n before `dd` to delete n of lines below `ndd`
* To delete a word at cursor `dw`

_Copy_

* To copy a line `yy`
	* Add n before `yy` to copy n of lines below `nyy`
* To copy a word at cursor `yw`

_Paste_

* To paste a line below cursor `p`
* To paste a line above cursor `P`
	* To paste copied info n times `np`

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
> To add comments use `"` before the new line 

## ***Cheatsheets***

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
