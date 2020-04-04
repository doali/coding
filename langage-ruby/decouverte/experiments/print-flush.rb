#!/usr/bin/env ruby

# Afficher sans passer à la ligne
# str : une chaine de caractères
# * : prend en compte tous les arguments suivant <str> de l'appelant
def print_and_flush(str = "", *)
  print str
  $stdout.flush
end

# Exemples
def saut_de_ligne
  puts " # saut_de_ligne"
end

print_and_flush

print_and_flush "mot_1"
saut_de_ligne

print_and_flush "mot_1" "mot_2"
saut_de_ligne


print_and_flush "mot_1"  " " "mot_2"
saut_de_ligne

print_and_flush "mot_1" + " " + "mot_2"
saut_de_ligne

print_and_flush ("mot_1" + " " + "mot_2")
saut_de_ligne
