#!/usr/bin/env ruby

class Panier
  attr_accessor :_max_legumes
  attr_accessor :_legumes # composition

  def initialize(max_legumes)
    @_max_legumes = max_legumes
    @_legumes = []
  end

  def est_plein
    return (@_legumes.size == @_max_legumes)
  end

  def ajouter(legume)
    @_legumes << legume
  end

  def capacite_restante
    return _max_legumes - _legumes.size
  end

  def remplir(legumes)
    legumes.each do |legume|
      #description
      ajouter(legume) if ! est_plein
    end
  end

  def description
    puts "Legumes:" + _legumes.to_s
    puts "Capacite:[" + capacite_restante.to_s + "/" + _max_legumes.to_s + "]"
  end

end

class Legume
  attr_accessor :_nom

  def initialize(nom)
    @_nom = nom
  end
end

# --------------------------------------------------
LISTE_LEGUME = [
  "tomate",
  "poivron",
  "patate"
]

def legume_au_hasard
  return LISTE_LEGUME[
    rand(LISTE_LEGUME.size) # entre 0 et (LISTE_LEGUME.size - 1)
  ]
end

etale = []
30.times do
  etale << legume_au_hasard
end

puts "Etale :" + etale.to_s

panier = Panier.new(10)
panier.description
panier.remplir(etale)
panier.description
