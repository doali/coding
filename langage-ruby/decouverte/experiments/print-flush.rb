#!/usr/bin/env ruby

# =====================================================================
# Afficher sans passer à la ligne
# =====================================================================

# ---------------------------------------------------------------------
# str : une chaine de caractères
# * : prend en compte tous les arguments suivant <str> de l'appelant
def print_and_flush(*liste_des_arguments)
  print *liste_des_arguments
  $stdout.flush
end


# ---------------------------------------------------------------------
def affiche(*liste_des_arguments)
  res = liste_des_arguments.join('')
  puts res
end


# ---------------------------------------------------------------------
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

print_and_flush("mot_1" + " " + "mot_2")
saut_de_ligne

print_and_flush("mot_1", "mot_2", "mot_3")
saut_de_ligne

print_and_flush("mot_1")
saut_de_ligne

print_and_flush()
saut_de_ligne

affiche(1, 2, 6, "h", "jkljl", 'r')
affiche(4594, 456, 'jkl', 456)
