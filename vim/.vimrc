" Vim Configurations
" To use the follow settings remove the " from the set [option]

" Disable compatibility with vi which can cuase unexpected issues
set nocompatible 
set noerrorbells
set novisualbell
set t_vb=

" Enable type file detection. Vim will be able to try to detect the type of file in use.
filetype on
filetype plugin on
filetype indent on

" --------- To set Default colorscheme --------- "
" colorscheme slate
" syntax on colorscheme slate
" --------- To set My Own colorscheme --------- "
let &t_Co=256
set syntax=1
colorscheme matcha

" Set wildmenu
set wildchar=<Tab> 
set wildmenu
set wildmode=longest:full,full

" Show line numbers
set relativenumber
set number

" ------------------- Fold Settings ------------------- "
set foldenable 
set foldmethod=manual
set foldenable
set foldcolumn=1

" za = open and close a fold
" zf = create a fold
" zd = delete folds under cursor
" zE = delete ALL folds
nnoremap <space> za " Change 
vnoremap <space> zf " Change 
nnoremap <space>d zd " Change folder maping for delete
nnoremap <space>e zE " Change folder maping for deleting all

" ------------ Status Bar Settings ------------ "
let &laststatus=2
set laststatus=2

function! ModeStr()
  let l:mode_map = {
        \ 'n': '    NORMAL    ',
        \ 'i': '    INSERT    ',
        \ 'v': '    VISUAL    ',
		\ 'V': '    VISUAL LINE    ',
        \ "\<C-v>": '    V BLOCK    ',
        \ 'R': '    REPLACE    ',
        \ 'c': '    CMD    ',
        \}
  return get(l:mode_map, mode(), mode())
endfunction

set statusline=%{ModeStr()}
set statusline+=\ %f\ \ \ \ %y

" ------------ Indentation Settings ------------ "
let &tabstop=4
let &shiftwidth = &tabstop 
let &autoindent=1 " Change new lines to inherit the indentation of previous lines

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
