#!/usr/bin/env ruby

# Définition d'une classe
# - RespecterCetteCasse
# - sinon ruby ne prend pas en compte
class MaClass
  attr_accessor :attr_1
  attr_accessor :attr_2

  def ma_simple_methode
    # instructions
    puts 'ma_simple_methode'
  end

  def ma_methode(arg)
    # instructions...
    puts arg.class
  end
end

# Instanciation
instance_1 = MaClass.new

# Acces attributs
instance_1.attr_1 = "premier attribut"
instance_1.attr_2 = 2

# Appel methode
instance_1.ma_methode(instance_1.attr_1)
instance_1.ma_simple_methode

# Informations
puts instance_1.class
puts instance_1.attr_1.class
