" Vim Configurations
" To use the follow settings remove the " from the set [option]

" To set colorscheme
colorscheme desert
syntax on colorscheme desert

" Show line numbers
set relativenumber
set number

set tabstop=4 " Change tab to 4 spaces
set shiftwidth=4 " Change shift width to 4 spaces

" Add status bar on the bottom
" set laststatus=2

set autoindent " Change new lines to inherit the indentation of previous lines

" Ps = 0 -> blinking block
" Ps = 1 -> blinking block
" Ps = 2 -> steady block
" Ps = 3 -> blinking underline
" Ps = 4 -> steady underline
" Ps = 5 -> blinking bar
" Ps = 6 -> steady bar
set mouse=a
let &t_EI = "\e[2 q" " Set all settings to blinking block
let &t_SI = "\e[5 q" " Set insert mode to have steady bar
let &t_SR = "\e[3 q" " Set replace mode to have steady underline
