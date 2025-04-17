#!/bin/bash

echo "🚀 Instalando Packer (si no está)..."
git clone --depth 1 https://github.com/wbthomason/packer.nvim \
  ~/.local/share/nvim/site/pack/packer/start/packer.nvim 2>/dev/null || echo "✅ Packer ya estaba instalado."

echo "📁 Creando estructura de configuración..."
mkdir -p ~/.config/nvim/lua

echo "📝 Escribiendo init.lua..."
cat << 'EOF' > ~/.config/nvim/init.lua
require('plugins')

-- Configuración general
vim.o.termguicolors = true
vim.o.number = true
vim.o.relativenumber = true

-- Tema activo (puedes cambiar 'spaceduck' por 'tokyonight-night' o 'duskfox')
vim.cmd[[colorscheme spaceduck]]
EOF

echo "📝 Escribiendo plugins.lua..."
cat << 'EOF' > ~/.config/nvim/lua/plugins.lua
vim.cmd [[packadd packer.nvim]]

return require('packer').startup(function(use)
  use 'wbthomason/packer.nvim'

  -- Temas funcionales estilo synthwave
  use 'folke/tokyonight.nvim'          -- Opción neón
  use 'pineapplegiant/spaceduck'       -- Brillito retro
  use 'EdenEast/nightfox.nvim'         -- Variantes como duskfox

  -- Estética y funcionalidades
  use 'nvim-lualine/lualine.nvim'
  use 'nvim-tree/nvim-web-devicons'
  use {
    'nvim-treesitter/nvim-treesitter',
    run = ':TSUpdate'
  }
end)
EOF

echo "✅ Listo. Abrí Neovim y ejecutá :PackerSync para instalar los plugins."
echo "🎨 Tema actual: spaceduck (puedes cambiarlo en ~/.config/nvim/init.lua)"

