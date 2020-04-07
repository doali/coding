#!/usr/bin/env ruby

def closure(a)
  return -> (x) { a ** x }
end

f_10 = closure(10)

10.times do |i|
  res = f_10.call(i)
  puts(res)
end
