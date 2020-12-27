#!/usr/bin/env ruby

Thread.new { 3.times { puts "titi" } }.join

t_1 = Thread.new { puts "t_1"; sleep(10); puts "t_1" }

loop do 
    puts "loop"
    sleep(0.5)
    break if !t_1.alive?
end

t_2 = Thread.new do
    puts "t_2"
    sleep(5)
end

t_2.join
puts "t_2 has finished"