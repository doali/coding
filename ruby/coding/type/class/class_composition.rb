#!/usr/bin/env ruby

class Panier
  attr_accessor :_legumes # composition

  def initialize
    @_legumes = []
  end

  def ajouter(legume)
    _legumes << legume
  end

  def to_s
    description = "Panier :" + ((_legumes.size == 0) ? "vide" : "")
    _legumes.each do |legume|
      description += "\n"
      description += ("- " + legume.to_s)
    end
    return description
  end
end


class Legume
  attr_accessor :_nom
  attr_accessor :_famille

  def initialize(nom, famille)
    @_nom = nom
    @_famille = famille
  end

  def to_s
    return "Legume :{" + _nom + ":" + _famille + "}"
  end
end


# --------------------------------------------------
legume_tomate = Legume.new("tomate", "fruit")
legume_patate = Legume.new("patate", "racine")
puts legume_tomate
puts legume_patate

puts
panier = Panier.new # methodes d'instance + composition
puts panier

panier.ajouter(legume_tomate)
panier.ajouter(legume_patate)
puts panier
