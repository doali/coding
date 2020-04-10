#!/usr/bin/env ruby

class MiniFB
  # === attributs
  attr_accessor :_prenom
  attr_accessor :_amis

  # === initialisation
  def initialize(prenom, amis=[])
    self._prenom = prenom
    @_amis = amis
  end

  # === methodes
  def nb_amis
    return _amis.size
  end

  def to_s
    des = (nb_amis  > 1) ? "s" : ""
    info =  "[" + nb_amis.to_s + "] ami" + des + " compte pour " + _prenom
    _amis.each do |ami|
      info += ("\n- " + ami._prenom)
    end
    return info
  end
end

# Instanciation de MiniFB
linus = MiniFB.new("Linus")
larry = MiniFB.new("Larry", [linus])
brian = MiniFB.new("Brian", [linus, larry])

puts linus
puts larry
puts brian
