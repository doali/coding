#!/usr/bin/env ruby

class Animal
  attr_accessor :nom

  def initialize(nom)
    @nom = nom
  end

  def parle
    print_and_flush nom
  end
end

class Chien < Animal
  def parle
    super
    print_and_flush " arf"
    puts
  end
end

class Chat < Animal
  def parle
    super
    print_and_flush " miaou"
    puts
  end
end

def print_and_flush(*liste_des_arguments)
  print *liste_des_arguments
  $stdout.flush
end

def main
  # Instanciation
  chien = Chien.new("idefix")
  chat = Chat.new("kitty")

  chien.parle()
  chat.parle()
end

# === Fonction principale
# Trick as in python if __name__ == "__main__"
if __FILE__ == $0
  main
end
