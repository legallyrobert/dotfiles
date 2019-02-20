noh
set nocompatible
filetype indent plugin on
set autoread
syntax on
set title

set hidden
set wildmenu
set showmode
set showcmd
set hlsearch

set ignorecase
set smartcase
set backspace=indent,eol,start
set autoindent
set ruler
set showmatch
set cmdheight=1
set laststatus=2
set confirm
set visualbell
set scrolloff=6

set number relativenumber
augroup numbertoggle
    autocmd!
    autocmd BufEnter,FocusGained,InsertLeave * set relativenumber
    autocmd BufLeave,FocusLost,InsertEnter * set norelativenumber
augroup END

set cursorline
hi CursorLine term=bold cterm=bold ctermbg=NONE

set shiftwidth=4
set softtabstop=4
set expandtab

set statusline=%1*\ file\ %3*\ %f\ %4*\ 
set statusline+=%=\ 
set statusline+=%3*\ %l\ of\ %L\ %2*\ line\ 

colorscheme paramount

hi user1 ctermbg=3 ctermfg=0
hi user2 ctermbg=3 ctermfg=0
hi user3 ctermbg=11 ctermfg=NONE
hi user4 ctermbg=NONE ctermfg=NONE
hi group1 ctermbg=NONE ctermfg=0

hi statusline ctermbg=0 ctermfg=NONE
hi statuslinenc ctermbg=0 ctermfg=0

highlight Normal guibg=NONE ctermbg=NONE

highlight NonText ctermfg=255

""" Word replacements e.g. Theta -> θ
iabbrev Theta <C-k>Wθ
iabbrev theta <C-k>Wθ
iabbrev Omega <C-k>WΩ
iabbrev omega <C-k>Wω

""" automatically compile markdown on save

autocmd BufWritePost *.md !pandoc % -s -o %:r.pdf


""" Plugins (junegunn/vim-plug)
call plug#begin()
    Plug 'godlygeek/tabular'
    Plug 'plasticboy/vim-markdown'
call plug#end()

""" Vim-Markdown
let g:vim_markdown_folding_disabled = 1
