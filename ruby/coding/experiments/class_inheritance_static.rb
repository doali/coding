#!/usr/bin/env ruby
# --------------------------------------------------------------------------------
# Same (almost) program in python
# https://github.com/doali/coding/tree/master/python/coding/experiments/class_inheritance_static.py
# --------------------------------------------------------------------------------
class Coucou
  attr_accessor :last

  def initialize(first, last)
    @first = first
    self.last = last
  end

  def to_s
    "Coucou #{@first} #{self.last}"
  end

  def doS
    puts "#{@first} does something"
  end
end

class Titi < Coucou
  def to_s
    "Titi"
  end

  def doS
    puts "I, #{@first} do not do anything special"
  end

  def self.titi
    puts "titi"
  end
end

if __FILE__ == $0
  c = Coucou.new("first", "last")
  puts c

  tt = Titi.new("r", "r")
  puts tt
  puts "==================="
  k = Titi.new("a", "a")
  Titi.titi
  puts k
  puts "==================="

  t = Titi.new("titi", "kk")
  puts t

  [c, t].each do |e|
    e.doS
  end
end
