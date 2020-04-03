#!/usr/bin/env ruby

class Utilisateur
  # === attributs
  attr_accessor :prenom
  attr_accessor :amis

  # === methodes
  def nb_amis
    return amis.size
  end

  def est_ami_avec(ami)
    amis.each do |un_ami|
      return true if (un_ami.prenom == ami.prenom)
    end
    return false
  end

  def synthese
    puts prenom + " [" + nb_amis.to_s + "]"
    puts "Amis"
    amis.each do |ami|
      puts "  - " + ami.prenom
    end
  end

  def relation(ami)
    if (est_ami_avec(ami))
      puts "Bien évidemment, " + ami.prenom + " compte pour moi."
    else
      puts ami.prenom + " mon ami ? C'est à dire que ..."
    end
  end

  def relation_lst(amis)
    amis.each do |ami|
      if ami.prenom != prenom
        relation(ami)
      end
    end
  end
end

# === declaration d'une fonction principale qui servira de point d'entree
def main
  linus = Utilisateur.new
  linus.prenom = "Linus"
  linus.amis = []
  
  ken = Utilisateur.new
  ken.prenom = "Ken"
  ken.amis = []

  brian = Utilisateur.new
  brian.prenom = "Brian"
  brian.amis = []

  bill = Utilisateur.new
  bill.prenom = "Bill"
  bill.amis = []

  linus.amis << ken
  linus.amis << brian

  ken.amis << linus
  ken.amis << brian

  brian.amis << linus
  brian.amis << ken

  personnes = [linus, ken, brian, bill]
  personnes.each do |pers|
    pers.synthese
    pers.relation_lst(personnes)
    puts ""
  end


end

# === appel de la main
main
