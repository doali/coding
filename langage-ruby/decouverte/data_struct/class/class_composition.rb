#!/usr/bin/env ruby

class Panier
  attr_accessor :_nom
  attr_accessor :_max_legumes
  attr_accessor :_legumes # composition

  def initialize(nom, max_legumes)
    @_nom = nom
    @_max_legumes = max_legumes
    @_legumes = []
  end

  def est_plein
    return _legumes.size == _max_legumes
  end

  def ajouter(legume)
    _legumes << legume if ! est_plein
  end

  def remplir(legumes)
    legumes.each do |legume|
      ajouter(legume)
    end
  end

  def description
    puts "Panier de " + _nom
    puts "Contenu :"
    _legumes.each do |legume|
      puts "- " + legume.to_s
    end
    puts "Total :[" + _legumes.size.to_s + "/" + _max_legumes.to_s + "]"
  end
end


class Legume
  attr_accessor :_nom

  def initialize(nom)
    @_nom = nom
  end

  def to_s
    return _nom
  end
end


class Etale
  # attribut static
  @@LISTE_LEGUME = [
    "tomate",
    "poivron",
    "patate"
  ]

  # methode static
  def self.cree_etale(quantite)
    etale = []
    quantite.times do
      etale << Legume.new(legume_au_hasard)
    end
    return etale
  end

  # methode static
  def self.legume_au_hasard
    return @@LISTE_LEGUME[
      rand(@@LISTE_LEGUME.size) # entre 0 et (LISTE_LEGUME.size - 1)
    ]
  end

  # methode static
  def self.desription(etale)
    puts "Etale:"
    etale.each do |legume|
      puts "- " + legume.to_s
    end
  end
end

# --------------------------------------------------
# Instanciations....
etale = Etale.cree_etale(10) # utilisation de methodes static
Etale.desription(etale)      # utilisation de methodes static

puts "---"
panier = Panier.new("Georges", 7) # methodes d'instance + composition
panier.description

puts "---"
panier.remplir(etale)
panier.description
