if has("syntax")
  syntax on
endif

autocmd BufNewFile *.cpp 0r ~/.vim/template/cppconfig.cpp

set     ai!             "设置自动缩进
set     tabstop=4       "设置TAB为4格
set     shiftwidth=4    "设定 << 和 >> 命令移动时的宽度为 4
set     softtabstop=4   "使得按退格键时可以一次删掉 4 个空格
set     autoindent      "设置自动缩进
set     smarttab        "在行和段开始处使用制表符
set     nu              "显示行号
set     mouse=a         "激活鼠标
set     cursorline      "突出显示该行
color   desert          "设置颜色主题为DESERT
set     ruler           "设置显示行号
set     autoread        "设置自动读取文件
set     autowrite       "在切换buffer时自动保存当前文件
set     incsearch       "输入搜索内容时就显示搜索结果
set     hlsearch        "搜索时高亮显示被找到的文本
set     showcmd         "命令模式下，在底部显示，当前键入的指令
set     showmatch       "插入括号时，短暂地跳转到匹配的对应括号
set     matchtime=1     "短暂跳转到匹配括号的时间
set     smartindent     "开启新行时使用智能自动缩进

set     nobackup        "覆盖文件时不备份
set     nocompatible    "去掉有关vi一致性模式，避免以前版本的bug和局限
set     autochdir       "自动切换当前目录为当前文件所在的目录
set     hidden          "允许在有未保存的修改时切换缓冲区，此时的修改由 vim 负责保存
set     guioptions-=T   "隐藏工具栏
set     guioptions-=m   "隐藏菜单栏
set     noerrorbells    "不让vim发出讨厌的滴滴声 
set     t_Co=256        "启用256色
set     undofile        "保留撤销历史
set     history=1000    "Vim 需要记住多少次历史操作
filetype plugin on      "根据文件类型加载对应的插件
filetype indent on      "开启文件类型检查，并且载入与该类型对应的缩进规则

map <F5> <Esc>:w<CR> :!gedit % <CR>
imap <F5> <Esc>:w<CR> :!gedit % <CR>   "按F5使用gedit打开

map <F6> <Esc>:w<CR> :!code % <CR>
imap <F6> <Esc>:w<CR> :!code % <CR>   "按F6使用code打开(需安装VScode)

map <F9> <Esc>:w<CR> :!g++ % -g -Wall -Wextra -o %<  && ./%< <CR>   
imap <F9> <Esc>:w<CR> :!g++ % -g -Wall -Wextra -o %<  && ./%< <CR>   "按F9编译运行

func! YankToClipboard()
    exec "w"
    exec "!cat % |xsel --clipboard"
endfunc

map <F8> :call YankToClipboard() <CR>
imap <F8> :call YankToClipboard() <CR> "按F8将整个文件的内容拷贝到剪贴版内(需安装xsel)

if filereadable("/etc/vim/vimrc.local")
  source /etc/vim/vimrc.local
endif