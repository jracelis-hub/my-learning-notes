" Author: Jarron Racelis
" Maintainer: jarron.racelis@gmail.com

" See :help highlight
" Do :hi to see all settings

" ------------------------------- Notes ------------------------------ "
" let a: = function-argument
" let b: = buffer-variables
" let g: = global-variables
" let l: = local-variables
" let s: = script-variables
" let t: = tabpage-variables
" let v: = vim-variables
" let w: = window-variables

" To clear out any format
hi clear
syntax reset

" Name of the color file
let g:colors_name="matcha" 

set background=dark

" ---------------------------- Help Guide ---------------------------- "
" ctermbg background color
" ctermfg text color
" cterm style of text
" hi = highlight
" syn = syntax
" link = same settings as Name 
" -------------------------------------------------------------------- "

"  Type              Text            Background      Style
" ------------------------- Mode Settings --------------------------- "
hi Normal            ctermfg=108     ctermbg=235     cterm=none
hi Conceal           ctermfg=none    ctermbg=none    cterm=none 
hi ColorColumn       ctermfg=none    ctermbg=none    cterm=none 
hi Question          ctermfg=none    ctermbg=none    cterm=none 
hi LineNr            ctermfg=66      ctermbg=none    cterm=none

hi Visual            ctermfg=0       ctermbg=150     cterm=none
hi VisualNOS         ctermfg=none    ctermbg=none    cterm=none
hi MatchParen        ctermfg=none    ctermbg=none    cterm=none

" ----------------------- General Settings --------------------------- "
hi Error             ctermfg=9       ctermbg=none    cterm=none
hi Removed           ctermfg=9       ctermbg=none    cterm=none

" ------------------------ Cursor Settings --------------------------- "
hi Cursor            ctermfg=none    ctermbg=none    cterm=none " Only works for Gui Version
hi CursorLine        ctermfg=none    ctermbg=none    cterm=none
hi CursorLineSign    ctermfg=none    ctermbg=none    cterm=none
hi CursorLineFold    ctermfg=none    ctermbg=none    cterm=none
hi CursorColumn      ctermfg=none    ctermbg=none    cterm=none
hi CursorLineNr      ctermfg=none    ctermbg=none    cterm=none

hi VertSplit         ctermfg=0       ctermbg=150     cterm=none
hi EndOfBuffer       ctermfg=65      ctermbg=65      cterm=none
"hi StatusLine       ctermfg=none    ctermbg=none    cterm=none
hi StatusLineNC      ctermfg=0       ctermbg=0       cterm=none  
hi! link             StatusLine      VertSplit             
hi! link             StatusLineTerm  VertSplit             
"hi StatusLineTerm   ctermfg=none    ctermbg=none    cterm=none
hi! link             StatusLineTermNC StatusLineNC    
"hi StatusLineTermNC ctermfg=none    ctermbg=none    cterm=none

" -------------------- Settings Under Status Bar ------------------- "
hi Title             ctermfg=none    ctermbg=none    cterm=none
hi ModeMsg           ctermfg=150     ctermbg=none    cterm=none " Shows insert mode ... etc
hi! link             MoreMsg         ModeMsg
"hi MoreMsg           ctermfg=none    ctermbg=none    cterm=none
hi ErrorMsg          ctermfg=none    ctermbg=none    cterm=none

" ----------------------------- Search ----------------------------- "
hi Directory         ctermfg=none    ctermbg=none    cterm=none
hi Search            ctermfg=none    ctermbg=none    cterm=none
hi IncSearch         ctermfg=none    ctermbg=none    cterm=none

" ------------------------ Spelling Settings ----------------------- "
hi SpellBad          ctermfg=none    ctermbg=none    cterm=none
hi SpellCap          ctermfg=none    ctermbg=none    cterm=none
hi SpellRare         ctermfg=none    ctermbg=none    cterm=none
hi SpellLocal        ctermfg=none    ctermbg=none    cterm=none

" ------------------------ WildMenu Settings ----------------------- "
hi WildMenu          ctermfg=0       ctermbg=108     cterm=none

" ------------------------- Diff Settings -------------------------- "
hi DiffAdd           ctermfg=none    ctermbg=none    cterm=none
hi DiffChange        ctermfg=none    ctermbg=none    cterm=none
hi DiffDelete        ctermfg=none    ctermbg=none    cterm=none
hi DiffText          ctermfg=none    ctermbg=none    cterm=none

" ---------------------------- Tab Line ---------------------------- "
hi TabLine           ctermfg=none    ctermbg=none    cterm=none
hi TabLineFill       ctermfg=none    ctermbg=none    cterm=none
hi TabLineSel        ctermfg=none    ctermbg=none    cterm=none

" ------------------------- Pmenu Settings ------------------------- "
hi Pmenu             ctermfg=none    ctermbg=none    cterm=none
hi PmenuSbar         ctermfg=none    ctermbg=none    cterm=none
hi PmenuSel          ctermfg=none    ctermbg=none    cterm=none
hi PmenuThumb        ctermfg=none    ctermbg=none    cterm=none

" -------------------------- Fold Settings ------------------------- "
hi Folded            ctermfg=none    ctermbg=none    cterm=none
hi FoldColumn        ctermfg=none    ctermbg=none    cterm=none
hi SignColumn        ctermfg=none    ctermbg=none    cterm=none

" ---------------------- Data Type Settings ------------------------ "
hi Constant          ctermfg=225     ctermbg=none    cterm=none
hi String            ctermfg=225     ctermbg=none    cterm=none 
hi Character         ctermfg=225     ctermbg=none    cterm=none
hi Special           ctermfg=61      ctermbg=none    cterm=none

hi Number            ctermfg=75      ctermbg=none    cterm=none
hi! link             Float           Number          
hi! link             Boolean         Number          
"hi Float            ctermfg=none    ctermbg=none    cterm=none
"hi Boolean          ctermfg=none    ctermbg=none    cterm=none

hi Comment           ctermfg=66      ctermbg=none    cterm=italic

hi Function          ctermfg=215     ctermbg=none    cterm=none
hi! link             Identifier      Function        
hi! link             Conditional     Function        
hi! link             Statement       Function                            
"hi Identifier       ctermfg=none    ctermbg=none    cterm=none
"hi Statement        ctermfg=none    ctermbg=none    cterm=none
"hi Conditional      ctermfg=none    ctermbg=none    cterm=none

" ---------------------------- C Language ---------------------------- "
hi PreProc           ctermfg=7       ctermbg=none    cterm=none 
hi! link             Include         Preproc                    
hi! link             Macro           Preproc
hi! link             Define          Preproc             
hi! link             PreCondit       Preproc
"hi Include          ctermfg=none    ctermbg=none    cterm=none
"hi Macro            ctermfg=none    ctermbg=none    cterm=none
"hi Define           ctermfg=none    ctermbg=none    cterm=none
"hi PreCondit        ctermfg=none    ctermbg=none    cterm=none

hi Type              ctermfg=75      ctermbg=none    cterm=none "void, int, float, double 
hi StorageClass      ctermfg=80      ctermbg=none    cterm=none "const, volatile, static
hi! link             Typedef         Type            
"hi Typedef           ctermfg=none    ctermbg=none    cterm=none
hi! link             Structure       Type            
"hi Structure        ctermfg=none    ctermbg=none    cterm=none

" ---------------------------- Done ---------------------------- "

