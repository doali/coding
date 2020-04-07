#!/usr/bin/env ruby

# liste
list_user = ['u_1', 'u_2', 'u_3', 'u_4', 'u_5']

# iteration sur la liste
list_user.each do |element|
  puts element
end

puts list_user.to_s

# premier element
puts list_user[0]

# dernier element
puts list_user[-1]

list_ex = ["a", 1, 2, "d"]
puts list_ex.to_s

list_ex[0] = 'A'
puts list_ex.to_s

list_ex[-1] = "D"
puts list_ex.to_s

list_ex << "E"
puts list_ex.to_s

list_ex.append('F')
puts list_ex.to_s

list_ex.reverse
puts list_ex.to_s
