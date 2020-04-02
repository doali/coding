#!/usr/bin/env ruby

# liste
list_user = ['u_1', 'u_2', 'u_3', 'u_4', 'u_5']

# iteration sur la liste
list_user.each do |element|
  puts element
end

# hash
p_1 = {nom:'n_1', prenom: 'p_1'}
p_2 = {nom:'n_2', prenom: 'p_2'}
p_3 = {nom:'n_3', prenom: 'p_3'}
p_4 = {nom:'n_4', prenom: 'p_4'}
p_5 = {nom:'n_5', prenom: 'p_5'}

annuaire = [p_1, p_2, p_3, p_4, p_5]

# iteration sur liste contenant des hash
annuaire.each do |pers|
  puts pers[:nom] + " --> " + pers[:prenom]
end

# iteration
5.times do |i|
  puts i
end
