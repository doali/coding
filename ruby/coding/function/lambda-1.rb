#!/usr/bin/env ruby

f = -> (a) { -> (b) { a + b } }

a = 20
b = 1

puts "f(#{a}, #{b})=#{(f.call a).call b}"
