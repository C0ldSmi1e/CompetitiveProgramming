"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" Plugins Setting
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
set nocompatible              " be iMproved, required
filetype off                  " required

" set the runtime path to include Vundle and initialize
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin('~/.vim/bundle')
" alternatively, pass a path where Vundle should install plugins
"call vundle#begin('~/some/path/here')

" let Vundle manage Vundle, required
Plugin 'VundleVim/Vundle.vim'

Plugin 'SirVer/ultisnips'
Plugin 'luochen1990/rainbow'
Plugin 'jiangmiao/auto-pairs'
Plugin 'godlygeek/tabular'
Plugin 'preservim/vim-markdown'
Plugin 'iamcco/markdown-preview.nvim'
Plugin 'searleser97/cpbooster.vim'
Plugin 'preservim/nerdtree'
Plugin 'JamshedVesuna/vim-markdown-preview'
Plugin 'github/copilot.vim'
Plugin 'dense-analysis/ale'
Plugin 'djoshea/vim-autoread'

call vundle#end()            " required
filetype plugin indent on    " required
" To ignore plugin indent changes, instead use:
"filetype plugin on
"
" Brief help
" :PluginList       - lists configured plugins
" :PluginInstall    - installs plugins; append `!` to update or just :PluginUpdate
" :PluginSearch foo - searches for foo; append `!` to refresh local cache
" :PluginClean      - confirms removal of unused plugins; append `!` to auto-approve removal
"
" see :h vundle for more details or wiki for FAQ
" Put your non-Plugin stuff after this line

" rainbow setting
let g:rainbow_active=0

" vim-markdown setting
set conceallevel=2
" let g:vim_markdown_conceal=0
let g:tex_conceal=""
let g:vim_markdown_math=1
let g:vim_markdown_folding_disabled=1
let g:vim_markdown_conceal_code_blocks=1

" UltiSnaips setting
let g:UltiSnipsSnippetDirectories=["mysnippets"]
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

let vim_markdown_preview_browser='Google Chrome'

" Ale setting
let g:ale_linters = {
 \ 'javascript': ['eslint'],
 \ 'typescript': ['eslint'],
 \ 'javascriptreact': ['eslint'],
 \ 'typescriptreact': ['eslint'],
 \}
let g:ale_fix_on_save = 1
let g:ale_linters_explicit = 1
let g:ale_fixers = {
 \ 'javascript': ['prettier', 'eslint'],
 \ 'typescript': ['prettier', 'eslint'],
 \ 'javascriptreact': ['prettier', 'eslint'],
 \ 'typescriptreact': ['prettier', 'eslint'],
 \}
