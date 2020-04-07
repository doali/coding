#!/usr/bin/env ruby

# --------------------------------------------------
# Code horrible a eviter !!
# --------------------------------------------------

# --------------------------------------------------
# Variable globale
$voyelles = [
  'a',
  'e',
  'i',
  'o',
  'u',
  'y',
]

# --------------------------------------------------
# Fonction globale
def init_dico(dico)
  $voyelles.each do |element|
    dico[element] = 0
  end
end

# --------------------------------------------------
# Fonction globale
def enumerate_voyelles(mot)
  print "Mot:"
  puts mot

  # --------------------------------------------------
  # Initialisation
  dico  = {}
  init_dico(dico)

  # --------------------------------------------------
  # Initialisation du dico
  mot.split('').each do |lettre|
    if $voyelles.include? lettre
      dico[lettre] = dico[lettre] + 1
    end
  end

  # --------------------------------------------------
  # Occurrences des voyelles
  puts "Occurrences"
  dico.keys.each do |clef|
    info = clef.to_s + " : " + dico[clef].to_s
    puts info if (dico[clef] > 0)
  end

  # --------------------------------------------------
  # Total des voyelles rencontrées
  total = 0
  dico.keys.each do |clef|
    total += dico[clef]
  end

  puts "Total:" + total.to_s
end

# --------------------------------------------------
# Entry point
ARGV.each do |mot|
  enumerate_voyelles(mot)
  puts
end
