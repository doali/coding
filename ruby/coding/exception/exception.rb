#!/usr/bin/env ruby

# Simple comment
def read_file(file_name)
  begin
  file = open(file_name, "r")
  
  if file 
    file.each do |line|
      puts line.to_s
    end
  end
  rescue
    file = STDIN
    puts file
  end
end

def main
  read_file(ARGV[0])
end

if __FILE__ == $0
  main
end
