" set makeprg=g++\ %\ -o%<\ -Wall\ -std=c++14\ -DLOCAL\ -g
set makeprg=g++\ %\ -o%<\ -O2\ -Wall\ -Wextra\ -std=c++17\ -Wfloat-equal\ -Wconversion\ -Wlogical-op\ -DLOCAL

nnoremap <F9> :silent call Cmp()<CR>
inoremap <F9> <Esc>:silent call Cmp()<CR>

nnoremap <F7> :call Py()<CR>
inoremap <F7> <Esc>:call Py()<CR>

nnoremap <F10> :e in <CR>
inoremap <F10> <Esc>:e in <CR>

nnoremap \\ :only<CR>
nnoremap [n :bn<CR>
nnoremap [p :bp<CR>
nnoremap <M-=> :vertical resize +10<CR>
nnoremap <M--> :vertical resize -10<CR>

nnoremap <c-A> gg"+yG

function Py()
    write
    !python3 %
endfunc

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

function Run()
    call Set()
    " !(time ./%< <%<.in >%<.out)2>>%<.out
    " !touch %<.in %<.out
    " !(./%< <%<.in >%<.out)2>>%<.out
    " belowright vsplit %<.in
    " belowright sview %<.out
    !touch in out
    !(./%< <in >out)2>>out
    belowright vsplit in
    belowright sview out
    wincmd t
    redraw!
endfunc

function Cmp()
    call Set()
    let v:statusmsg=''
    make
    if empty(v:statusmsg)
        call Run()
    else
        cwindow
        winc t
        redraw!
    endif
endfunc

nnoremap <F2> :silent call AutherInfo()<CR>
inoremap <F2> <Esc>:silent call AutherInfo()<CR>
nnoremap <leader><leader>f :silent call Flash()<CR>
function Flash()
    if expand("%:e") == 'cpp'
        !cat /home/daniel/Algorithm/Practice/template.cpp > %
    endif
endfunc

function AutherInfo()
    if expand("%:e") == 'sh' || expand("%:e") == 'py'
        execute "normal ggO"
        call setline(1, "##########################################################################")         
        call append(line("."), " # Author: Daniel")
        call append(line(".") + 1, " # Created Time: ".strftime("%Y-%m-%d %H:%M:%S"))
        call append(line(".") + 2, "#########################################################################")         
        call append(line(".") + 3, "")    
    elseif expand("%:e") == 'c' || expand("%:e") == 'cpp' || expand("%:e") == 'h' 
        execute "normal ggO"
        call setline(1, "/**")         
        call append(line("."), " * Author: Daniel")
        call append(line(".") + 1, " * Created Time: ".strftime("%Y-%m-%d %H:%M:%S"))         
        call append(line(".") + 2, "**/")
        call append(line(".") + 3, "")
    endif
endfunc
