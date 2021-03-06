#!/usr/bin/env ruby

# Définition d'une classe
class Utilisateur
  attr_accessor :prenom
  attr_accessor :nom
  attr_accessor :oeuvres

  def description
    puts prenom + " " + nom + ", créateur de : " + oeuvres.to_s
  end
end

# Utilisation
ym = Utilisateur.new
ym.prenom ='Yukihiro'
ym.nom ='Matsumoto'
ym.oeuvres = ['ruby']

lw = Utilisateur.new
lw.prenom ='Larry'
lw.nom ='Wall'
lw.oeuvres = ['perl'].to_s

dr = Utilisateur.new
dr.prenom ='Dennis '
dr.nom ='Ritchie'
dr.oeuvres = ['C'].to_s

kt = Utilisateur.new
kt.prenom ='Ken '
kt.nom ='Thompson'
kt.oeuvres = ['Unix', 'C'].to_s

bk = Utilisateur.new
bk.prenom ='Brian '
bk.nom ='Kernighan'
bk.oeuvres = ['Unix', 'C'].to_s

lt = Utilisateur.new
lt.prenom ='Linus '
lt.nom ='Torvalds'
lt.oeuvres = ['Linux'].to_s

dc = Utilisateur.new
dc.prenom ='Douglas '
dc.nom ='Crockford'
dc.oeuvres = ['javascript','JSon'].to_s

bd = Utilisateur.new
bd.prenom ='Brendan '
bd.nom ='Eich'
bd.oeuvres = ['javascript'].to_s

informaticiens = [ym, lw, dr, kt, bk, lt, dc, bd]
informaticiens.each do |personne|
  personne.description
end

