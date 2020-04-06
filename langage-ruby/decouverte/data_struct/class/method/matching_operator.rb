#!/usr/bin/env ruby

# =~ <= matching operator : renvoie un index ou nill
puts "3oranges" =~ /[0-9]/
puts "3ora4nges" =~ /[0-9]/
puts "oranges" =~ /[0-9]/ # renvoie nil
puts "ora4nges" =~ /[0-9]/

# !~ <= matching operator : renvoie true ou false
puts "oranges" !~ /[0-9]/ # renvoie true
puts "ora4nges" !~ /[0-9]/ # renvoie false
