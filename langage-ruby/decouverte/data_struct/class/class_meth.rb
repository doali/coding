#!/usr/bin/env ruby

# Définition d'une classe
# - RespecterCetteCasse
# - sinon ruby ne prend pas en compte
class MaClass
  attr_accessor :attr_1
  attr_accessor :attr_2

  def ma_methode
    puts "declarations..."
  end
end

# Instanciation
instance_1 = MaClass.new

# Acces attributs
instance_1.attr_1 = "premier attribut"
instance_1.attr_2 = 2

# Appel methode
instance_1.ma_methode

# Informations
puts instance_1.class
puts instance_1.attr_1.class
