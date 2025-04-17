#!/bin/bash

echo "🚀 Instalando Packer (gestor de plugins)..."
git clone --depth 1 https://github.com/wbthomason/packer.nvim \
  ~/.local/share/nvim/site/pack/packer/start/packer.nvim

echo "📁 Creando estructura de configuración..."
mkdir -p ~/.config/nvim/lua

echo "📝 Escribiendo init.lua..."
cat << 'EOF' > ~/.config/nvim/init.lua
require('plugins')

-- Colores y estética
vim.cmd[[colorscheme synthwave84]]

-- Config general
vim.o.number = true
vim.o.relativenumber = true
vim.o.termguicolors = true
EOF

echo "📝 Escribiendo plugins.lua..."
cat << 'EOF' > ~/.config/nvim/lua/plugins.lua
-- Carga automática de Packer
vim.cmd [[packadd packer.nvim]]

return require('packer').startup(function(use)
  use 'wbthomason/packer.nvim'

  -- Tema Synthwave84
  use 'tani/dark.nvim' -- base synthwave-like
  use {
    'folke/tokyonight.nvim',
    config = function()
      vim.cmd[[colorscheme tokyonight-night]]
    end
  }
  use {
    'pineapplegiant/spaceduck',
    config = function()
      vim.cmd[[colorscheme spaceduck]]
    end
  }
  use {
    'tobi-wan-kenobi/synthwave84.nvim',
    config = function()
      require('synthwave84').setup({
        glow = {
          enabled = true,
        }
      })
      vim.cmd[[colorscheme synthwave84]]
    end
  }

  use 'nvim-lualine/lualine.nvim'
  use 'nvim-tree/nvim-web-devicons'
  use {
    'nvim-treesitter/nvim-treesitter',
    run = ':TSUpdate'
  }
end)
EOF

echo "✅ Listo. Abrí Neovim y ejecutá :PackerSync para instalar los plugins."

