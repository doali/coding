#!/usr/bin/env ruby

# https://www.rubyguides.com/2018/09/ruby-conversion-methods/
# to_a, to_s, to_i ...

def f(x)
  return -> (y) { x + y }
end

f_10 = f(10)

l = (1..10).to_a

l.each do |element|
  puts "#{element}:f_10(#{element})=#{f_10.call(element)}"
end
