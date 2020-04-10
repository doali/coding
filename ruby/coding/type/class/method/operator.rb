#!/usr/bin/env ruby

class MaClass
  attr_accessor :nom

  def initialize(nom)
    @nom = nom
  end

  def ==(ref_instance)
    nom == ref_instance.nom
  end
end

# --------------------------------------------------
obj_a = MaClass.new('objA')
obj_b = MaClass.new('objB')

puts "Redéfinition de l'opérateur =="
puts "pour que les objets soient considérés comme identiques sur la comparaison de leurs noms"

puts
puts "nom obj_a:" + obj_a.nom + "\t" + obj_a.to_s
puts "nom obj_b:" + obj_b.nom + "\t" + obj_b.to_s

puts
puts "identiques ? " + (obj_a == obj_b).to_s

puts
puts "modification de l'attribut nom pour qu'ils aient les mêmes valeurs"
obj_b.nom = 'objA'
puts "obj_b.nom = 'objA'"

puts
puts "nom obj_a:" + obj_a.nom + "\t" + obj_a.to_s
puts "nom obj_b:" + obj_b.nom + "\t" + obj_b.to_s

puts "identiques ? " + (obj_a == obj_b).to_s

