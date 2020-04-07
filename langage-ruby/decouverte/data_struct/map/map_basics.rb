#!/usr/bin/env ruby

# Definition d'une map / hash map / table d'association ...
hash_ex = {alice: 10, bob: "frere", un: 1}
puts hash_ex

# Acces
hash_ex[:alice]
hash_ex[:un]

# Modification
hash_ex[:deux] = 2

# Affichage avec conversion en string
puts hash_ex.to_s

# Affichage du contenu
puts "#{hash_ex}"

# Methodes
puts ".keys"
puts hash_ex.keys

puts ".values"
puts hash_ex.values

puts ".fecth"
puts hash_ex.fetch(:deux)

# Autre definition
puts
h_1 = { 1 => "eins", 2 => "zwei", 3 => "drei" } # nombre comme clefs
puts h_1[1]

h_2 = { :one => "eins", :two => "zwei", :three => "drei" } # symboles comme clefs
puts h_2[:three]

h_3 = { "weights" => ["pound", "kilogram"], "lengths" => ["meter", "mile"] } # chaines de caracters comme clefs
puts "#{h_3['lengths']}"

h_4 = { :de => { :one => "eins", :two => "zwei", :three => "drei" } } # imbrication
puts h_4[:de]

l = [h_1, h_2, h_3, h_4]

puts
l.each do |element|
  puts element
end
