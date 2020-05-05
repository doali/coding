#!/usr/bin/env ruby

module OneModule
  def do_something
    puts "do something"
  end
end

if __FILE__ == $0
  include OneModule
  do_something()
end
