#!/usr/bin/env ruby

# liste
list_user = ['u_1', 'u_2', 'u_3', 'u_4', 'u_5']

# Afficher le contenu de la liste : #{list_user}
puts "Liste #{list_user}"

# Afficher la string decrivant un objet : <objet>.to_s
puts "Liste " + list_user.to_s

# iteration
list_user.each do |element|
  puts element
end
