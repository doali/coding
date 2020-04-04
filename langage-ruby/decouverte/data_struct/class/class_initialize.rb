#!/usr/bin/env ruby

class MiniFB
  # === attributs
  attr_accessor :prenom
  attr_accessor :amis

  # === initialisation
  def initialize(prenom, amis=[])
    self.prenom = prenom
    @amis = amis
  end

  # === methodes
  def nb_amis
    return amis.size
  end

  def to_s
    super
    des = (nb_amis  > 1) ? "s" : ""
    return "[" + nb_amis.to_s + "] ami" + des + " compte pour " + prenom
  end
end

# Instanciation de MiniFB
linus = MiniFB.new("Linus")
larry = MiniFB.new("Larry", [linus])
brian = MiniFB.new("Brian", [linus, larry])

puts linus
puts larry
puts brian
