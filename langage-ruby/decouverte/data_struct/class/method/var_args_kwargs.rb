#!/usr/bin/env ruby

# Arguments variables
# *args : quantite variable d'arguments transmis à l'appele (sous forme d'une liste)
# **kwargs : quantite variable d'arguments transmis à l'appelé (sous forme d'une hash-map)
# Ordre à respecter
# required -> optional -> variable -> keyword -> keyword_variable
# arg : définit un argument classique (mon_argument, {ma_clef:ma_valeur}, ...)
# kwarg : définit un keyword argument (ma_clef:ma_valeur, autre_clef: {key: val}, ...)

# --------------------------------------------------
def ex_l(*args)
  puts "#{args}" # puts args.to_s # puts *args.to_s
  puts args # puts *args
end

ex_l('a', 'b', 'c', 1, 2, 3)
puts "------------------------------"

# --------------------------------------------------
def ex_hash(**kwargs)
  puts "#{kwargs}" # puts kwargs # puts **kwargs # puts kwargs.to_s # puts *kwargs.to_s
  puts *kwargs
end

ex_hash(clef_a:'a', clef_b:'b', lettre:'c', un:1, deux:2)
puts "------------------------------"

# --------------------------------------------------
def testing(a, b = 1, *c, d: 1, **x)
  puts a
  puts b
  puts c # liste
  puts d
  puts x # hash map
end

testing({un:1, deux:2}, 'a', 'b', 'c', 'd', 'e', d: 2, x: 1, lol:{mon_hash:{hein:1, deux:2}})
puts "------------------------------"
