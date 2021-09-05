#!/usr/bin/env ruby

def convert_to_ascii msg
  msg_to_lst = msg.split('')
  msg_to_lst.each do |c|
    puts("|#{c.ord.to_s.ljust(3)}|#{c}|")
    # c.ord -> integer
    # <String>.ljust(<integer>[...]) -> new_str
  end
end

def main
  convert_to_ascii ARGV[0]
end

if __FILE__ == $0
  main
end
