#!/usr/bin/python

class MaClasse :
     essai = "ok"
     def affiche(self):
             print self.essai

objet = MaClasse()
objet.affiche()

objet2 = MaClasse()
objet2.affiche()

objet2.essai = "wow"
objet2.affiche()

objet.affiche()

print objet2.essai

MaClasse.essai = "test"
objet.affiche()

objet2.affiche()
