#!/usr/bin/env ruby

# Définition d'une classe
# - RespecterCetteCasse
# - sinon ruby ne prend pas en compte
class MaClass
  attr_accessor :attr_1
  attr_accessor :attr_2
end

# Utilisation
instance_1 = MaClass.new
instance_1.attr_1 = "premier attribut"
instance_1.attr_2 = 2

puts instance_1.attr_1
puts instance_1.attr_2

instance_2 = MaClass.new
instance_2.attr_1 = "premier attribut"
instance_2.attr_2 = 2

puts instance_2.attr_1
puts instance_2.attr_2

# Informations
puts instance_1.class
puts instance_2.class

puts instance_1.attr_1.class
puts instance_1.attr_2.class

