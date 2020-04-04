#!/usr/binenv ruby

class ClassParent
  attr_accessor :nom

  def initialize(nom)
    @nom = nom
  end

  def description
    puts "Je suis le père"
    return nom + ":" + "#{self.class}"
  end
end

class ClassFils < ClassParent
  def description
    info = super
    puts "le fils"
    return info
  end
end

a = ClassParent.new("A")
puts a.description

b = ClassFils.new("B")
puts b.description
