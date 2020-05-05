#!/usr/bin/env ruby

# DO NOT FORGET `./` 
require './mon-module.rb' # loading our module here
#require './mon-module' # works as well

##
# class MaClass
class Maclass
  include OneModule # including our module here
  attr_accessor :name

  # Constructor
  def initialize(name)
    @name = name
  end

  # Description
  def to_s
    return "Name: #{name}"
  end
end

##
# Main function
def main
  mc_1 = Maclass.new("mc_1")
  mc_2 = Maclass.new("mc_2")

  l = [] << mc_1 << mc_2

  l.each do |element|
    puts element
  end

  mc_1.do_something() # using our module here
end

# Main
#-------------------------------------------------------------------------------
if __FILE__ == $0
  main
end
