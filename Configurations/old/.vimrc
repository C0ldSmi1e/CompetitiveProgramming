"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" General Setting
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
let mapleader=","        " Define <leader> key
set nocompatible         " Not compatible with original vim
filetype off             " Check the file type
" filetype plugin on       " Load plugins coresponding to file type
set noeb                 " Turn off error message
syntax enable            " Syntax Highlight
syntax on                " Auto Syntax Highlight
set t_Co=256             " Support 256 colors
set cmdheight=1          " Height of command line
set showcmd              " Show the number of selected lines in select mode
set ruler                " Always show position of cursor
set laststatus=2         " Always show status
set number               " Line number
set cursorline           " Highlight current line
set ttimeoutlen=0        " <ESC> delay
set virtualedit=block,onemore   " Allow cursor to be at the end of the line
set mouse=n              " Mouse mode
set autochdir            " Aoto update the current directory
let autosave=1           " Auto save
set relativenumber       " Relative line number
" set guifont=Monaco:h16    " Font and size
set lines=40             " Default wide
set columns=125          " Default height
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" Intent and Code Style
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
set autoindent           " Auto intent
set cindent              " Use C/C++ intent mode
set cinoptions=g0,:0,N-s,(0    " Set the intent mode in C/C++
set smartindent          " Smartly set the intent mode
filetype indent on       " Set the intent mode based on file type
set expandtab            " Make taps become spaces
set tabstop=2            " Set the number of spaces as a tab
set shiftwidth=2         " Set the number of spaces a tab contains
set softtabstop=2        " set the number of spaces to be a tab
set smarttab             " Use tabs at the beginning of line or paragraph
set nowrap               " No wrap
set backspace=2          " Enter will handle indent, eol and start normallly
set sidescroll=10        " Set the number of characters while scrolling to right
set nofoldenable         " No code folding
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" Autocomplete
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
set wildmenu             " Use the builtin command line to autocomplete
set completeopt-=preview " While autocompleting, show a table instead of a window
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" Search Settings
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
set hlsearch            " Highlight the result of searching
set incsearch           " Real time search
set ignorecase          " Case insensitive
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" Window Settings
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
nnoremap <c-j> <c-w>j
nnoremap <c-k> <c-w>k
nnoremap <c-h> <c-w>h
nnoremap <c-l> <c-w>l
nnoremap \\ :only<CR>
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" Backup Settings
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
set nobackup            " No backup
set noswapfile          " No temporary files
set autoread            " If file is modified outside of vim, auto reload
set autowrite           " Auto write
set autowriteall        " Auto write
set confirm             " If file is not saved or is only-read, have to confirm
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" Programming Setting
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" set makeprg=clang++\ %\ -o%<\ -O2\ -Wall\ -Wextra\ -std=c++20\ -Wfloat-equal\ -Wconversion\ -DLOCAL
set makeprg=clang++\ %\ -o%<\ -O2\ -std=c++20\ -Wall\ -Wextra\ -Wfloat-equal\ -DDANIEL_DEBUG_TEMPLATE\ 
" set makeprg=clang++\ %\ -o%<\ -Wall\ -std=c++20
nnoremap <Leader>i :e in <CR>
nnoremap <Leader>r :silent call Cmp()<CR>

" copy to system clipboard
vmap <Leader>c "+y
" copy all
nnoremap <Leader>z gg"+yG

function Set()
  if winnr('$')>1
    wincmd l
    wincmd k
    write
    wincmd t
    only
  endif
  write
endfunc

function Cmp()
  let v:statusmsg=''
  make
  if empty(v:statusmsg)
    !touch in out
    !./%< <in >out
    redraw!
  else
    cwindow
    wincmd t
    redraw!
  endif
  " call Set()
  " let v:statusmsg=''
  " make
  " if empty(v:statusmsg)
  "   !touch in out
  "   !./%< <in >out
  "   belowright 30vsplit in
  "   belowright sview out
  "   wincmd t
  "   redraw!
  " else
  "   cwindow
  "   wincmd t
  "   redraw!
  " endif
endfunc
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" Add information of author in .sh .py .cpp files
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
nnoremap <Leader>a :silent call AuthorInfo()<CR>
function AuthorInfo()
  if expand("%:e") == 'sh' || expand("%:e") == 'py'
    execute "normal ggO"
    call setline(1, "##########################################################################")         
    call append(line("."), " # Author: C0ldSmi1e")
    call append(line(".") + 1, " # Created Time: ".strftime("%Y-%m-%d %r"))
    call append(line(".") + 2, "#########################################################################")         
    call append(line(".") + 3, "")    
  elseif expand("%:e") == 'c' || expand("%:e") == 'cpp' || expand("%:e") == 'h' 
    execute "normal ggO"
    call setline(1, "/**")         
    call append(line("."), " * Author: C0ldSmi1e")
    call append(line(".") + 1, " * Created Time: ".strftime("%m/%d/%Y %r"))         
    call append(line(".") + 2, "**/")
    call append(line(".") + 3, "")
  endif
endfunc
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" Overwrite current .cpp file by template
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
nnoremap <Leader>f :silent call Flash()<CR>
function Flash()
  if expand("%:e") == 'cpp'
    " !cp ../template.cpp %
    !cat ../template.cpp > %
    redraw!
  endif
endfunc
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" Plugins Settings
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
source $HOME/.plugins.vim

" Define an autocommand group
augroup DisableCopilotForCpp
  autocmd!

  " Disable Copilot for .cpp files
  autocmd FileType cpp Copilot disable
augroup END
