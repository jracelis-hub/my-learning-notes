# Vim Knowledge

## Table of Contents

* [Introduction](#introduction)
	* [Terminal Manipulation](#terminal-manipulation)
* [Normal Mode](#normal-mode)
	* [Navigate Through Text](#how-to-navigate-through-vim)
    * [Window Manipulation](#window-manipulation)
    * [Delete, Copy, Paste, Cut](#delete-copy-paste-cut)
* [Insert Mode](#insert-mode)
* [Setup Configuration](#setup-config)
* [Functions](#functions)
* [Cheatsheets](#cheatsheets)

## Introduction

What is VIM

Vim or (Vi IMproved) is a power text editor which is an improved version of Vi (Visual Editor).

To exit out of vim

* `:q` - to quit window with any changes made
* `:q!` - to force quit window without saving changes
* `:wq` - to save modifications made to buffer and quit
* `:w` - to save any modifications made to buffer
* `ZZ` - to save modifications made to buffer and quit

To get help

* `:help` or `:h` - to get help for vim
* `:help command` - to get help for a specific command
* `F1` - to get help for vim
* `ctrl + ]` - jump to hyper links 
* `crtl + T` - jump to back orginal tag 
* `crtl + O' - jumps to older posiion

* `:help index` - to get complete index of all Vim commands
* `crtl + G` - shows a help command on the bottom of the screen

To search for words:

- `/` - to search for words forwards 
- `?` - to search for words backwards

Use `n` to jump to next occurance of the searched word
```vim
"
"
"         ------
This is a |word|
          ------
/word
" click n
         ------
The next |word|
         ------
```

### Terminal Manipulation

When using `vim` and any file, it will open up something called a buffer. With that buffer the visual representation of the buffer is called the window.

Multiple buffers can be opened up at once such as:
```vim
vim ~/.bashrc ~/.vimrc
:ls
  1 %a   ".vimrc"                       line 1
  2      ".bashrc"                      line 0
```

There is also something called tabs which opens up another tab, that has its own buffers and windows. To open up a new tab.
```vim
:tabnew file_name
```
And to switch inbetween tab just:
- `gT` or `:tabn` - switch to next tab
- `gt` `:tabp` - switch to previous tab

To switch inbetween buffers use `Ctrl + ^`

To open up another window use 

When you use `:` that is calling a command within ***vim***.
```vim
:ls
" This will show what buffers you have open
```

When you used `:!` then you are calling a command within the terminal.
```vim
:!ls
" This will list current direction in the terminal
```


* To open up a terminal while in vim do
	* `:ter` This will open up a terminal in a screen above.
* To split screen up vertically
	* `vsplit`
	* shortcut `vsp`
* To split screen up horizontally
	* `split`
	* shortcut `sp`

## Normal Mode

### Navigate Through Text 

* `h` - To move cursor left
* `l` - To move cursor right
* `j` - To move cursor down
* `k` - To move cursor up
* `0` - To jump to beginning of the line
* `^` - To jump to beginning of the line (non-whitespace)
* `$` - To jump to end of the line `$`
* `w` - To jump to beginning of word going right
* `b` - To jump to beginning of word going left
* `e` - To jump to end of word going right
* `ge` - To jump to end of word going left 
* `fk` - To move cursor to any specific `k`(character) going right
* `Fk` - To move cursor to any specific `k`(character) going left
* `%` - To move cursor to matching `(`, `{`, `[` this will also move find one of these characters on the same line

#### Window Manipulation

* `G` - To jump cursor to the end of the window
* `gg` - To jump cursor to the beginning of the window
* `H` - To move cursor to the high of the window
* `M` - To move cursor to the middle of the window
* `L` - To move cursor to the low of the window
* `ctrl + e` - To move cursor down one line 
* `crtl + y` - To move cursor up one line 

> [!TIP] 
> You can use the navigation keys `w` `b` `e` with other commands like `d` (deletion) `c` cutting

### Delete, Copy, Paste, Cut

_Delete_

* `dd` to delete a line
* `ndd` to delete _n_ below lines
* `dw` to delete one word after the cursor
* `dnw` to delete n words after the cursor
* `di$` to delete in `c`haracter 
* `d$` to delete from start of the cursor to end of the line
* `d0` to delete from one space back from the cursor to the beginning of the line
* `d%` to delete to the to the end of the first occurence of `)` `}` or `]`

> [!WARNING]
> If the cursor is not at the beginning of the word it will only delete from the letter of the cursor

_Copy (Yank)_

* `yy` to copy a line
* `nyy` to copy n lines below
* `yw` to copy a word from cursor to end of a word
* `ynw` to copy n words from cursor
* `y$` to copy every after the cursor to end of the line
* `y0` to copy from one space back from cursor to the beginning of the line

_Paste_

* `p` to paste after cursor but if you use `dd` then `p` it will paste below the line
* `P` to paste before cursor but if you use `dd` then `P` it will paste above the line
* `np` to paste the same items n times

_Cut + (into Insert mode)_

* `cc` to cut a line and go into `insert` mode
* `cw` to cut a word and go into `insert` mode
* `cic` to cut `i`n a `c`haracter and go into `insert` mode
* `C` to cut a line and go into `insert` mode

<details>
    <table>
        <thead>
            <tr>
                <th align="center" colspan="2">Delete</th>	
                <th align="center" colspan="2">Copy (Yank)</th>	
                <th align="center" colspan="2">Paste</th>	
                <th align="center" colspan="2">Cut</th>
            </tr>
        </thead>
        <tbody>
            <tr>
                <td align="center" >Command</td>
                <td align="center" >Description</td>
                <td align="center" >Command</td>
                <td align="center" >Description</td>
                <td align="center" >Command</td>
                <td align="center" >Description</td>
                <td align="center" >Command</td>
                <td align="center" >Description</td>
            </tr>
            <tr>
                <td align="center" >`dd`</td>
                <td>to delete a line</td>
                <td align="center" >`yy`</td>
                <td>to copy a line</td>
                <td align="center" >`p`</td>
                <td>to paste below a line or after the cursor</td>
                <td align="center" >`cc`</td>
                <td>to delete a line and go into insert mode</td>
            </tr>
            <tr>
                <td align="center" >`ndd`</td>
                <td>to delete n lines</td>
                <td align="center" >`nyy`</td>
                <td>to copy n lines</td>
                <td align="center" >`np`</td>
                <td>to paste the same item n times</td>
                <td align="center" >`ncc`</td>
                <td>to delete n lines and go into insert mode</td>
            </tr>
            <tr>
                <td align="center" >`ndd`</td>
                <td>to delete n lines</td>
                <td align="center" >`nyy`</td>
                <td>to copy n lines</td>
                <td align="center" >`np`</td>
                <td>to paste the same item n times</td>
                <td align="center" >`cc`</td>
                <td>to delete n lines and go into insert mode</td>
            </tr>
        </tbody>
    </table>
</details>

### Other Commands

* `x` - To delete characters on the cursor
* `X` - To delete characters behind the cursor
* `J` - To join line below the cursor line
* `~` - To switch case for a character
* `u` - To undo the last edit
* `U` - To undo the last changes made on the last line that was edited
* `ctrl+r` - To reverse the undo

## Insert Mode

* `i` - to enter insert mode placing cursor before the character
* `I` - to enter insert mode in the beginning of the line
* `a` - to enter insert mode placing cursor after the character
* `A` - to enter insert mode in the end of the line
* `o` - to enter insert mode below the current line
* `O` - to enter insert mode above the current line

## Setup Configuration

In your `$HOME` or `~` directory make a file called `vimrc`

```bash
cd $HOME
vim vimrc
```

Specific Configuration Table

|Purpose| Description|
|:---:|:------|
| `set number` | to add line numbers on your vim console |
| `set relativenumber` | to show relative line numbers |
| `set autoindent` | to place the same indentations on the new line, as is present on the previous line |
| `set shiftwidt=number` | indent size of shift width |
| `set tabstop=number` | tab size |
| `set mouse=a` | allows mouse movements |

| Cursor Change | Description |
|:---:|:---| 
| Ps = 0 | blinking block |
| Ps = 1 | blinking block |
| Ps = 2 | steady block |
| Ps = 3 | blinking underline |
| Ps = 4 | steady underline |
| Ps = 5 | blinking bar |
| Ps = 6 | steady bar |
| `let &t_EI` | "\e[2 q" " Set all settings to blinking block |
| `let &t_SI` | "\e[5 q" " Set insert mode to have steady bar |
| `let &t_SR` | "\e[3 q" " Set replace mode to have steady underline |

> [!NOTE]
> To add comments use `"` before the new line 

## Function 

To creating a function in vim it starts with `function` and ends with `endfunction`
```vim
function Name()
	code
endfunction
```

To call a function use `call` then the function name.
```vim
call Name()
```

To declare a variable you use `let`
```vim
let number = 5
```

To see a variable from vimrc use `&variable` name
```
echo &tabstop
```

## Syntax

See `/usr/share/vim/vim91/syntax/` to see specific syntax format.


Each syntax file should include `set syntax clear`

> [!NOTE]
> To see current defined syntax use `:syntax`

Each to avoid case sensitivity use the following: `set syntax case ignore`

Syntax Keywords

---

To define a `syntax keyword` follow the specific format
```vim
syntax keyword {group} {keyword}
" Example
syntax keyword cType int long char
"             {group} {keywords}
```

Syntax Matches

---

To define a `syntax match` follow the specific format
```vim
syntax match {group} 
```

## Cheatsheets

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
| `nj` | moves cursor down (multi-line text)
| `nk` | moves cursor up (multi-line text)
| `H` | moves cursor to top of screen |
| `M` | moves cursor to middle of screen |
| `L` | moves cursor to bottom screen |
| `gg` | go to the first line of the document |
| `G` | go to the last line of the document |
| `w` | jump forwards to the start of a word |
| `W` | jumps forwards to the start of a word (words can contain punctuation) |
| `e` | jumps forwards to the end of a word |
| `E` | jumps fowards to the end of a word (words can contain punctuation) |
| `b` | jumps backwards to the start of a word |
| `B` | jumps backwards to the start of a word (words can contain punctuation) |
| `0` | jumps to the start of the line |
| `^` | jumps to the srat of the line (non blank spaces) |
| `$` | jumps to end of the line |
| `%` | jumps between matching `{` , `(` , `[` |
