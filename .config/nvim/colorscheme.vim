" onedark
if (empty($TMUX))
  if (has("nvim"))
    "For Neovim 0.1.3 and 0.1.4 < https://github.com/neovim/neovim/pull/2198 >
    let $NVIM_TUI_ENABLE_TRUE_COLOR=1
  endif
  if (has("termguicolors"))
    set termguicolors
  endif
endif



" gruvbox
set background=dark
let g:gruvbox_contrast_dark = 'hard'
colorscheme gruvbox



let g:airline_theme='dark'