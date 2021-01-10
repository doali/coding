#!/usr/bin/env ruby

require "mini_magick"

image = MiniMagick::Image.open("data/input.png")
image.path #=> "data/ruby.png"
image.resize "100x100"
image.format "png"
image.write "output.png"

# Installation 
# $> gem install mini_magick -v 4.5.1
# Utilisation 
# https://github.com/minimagick/minimagick
