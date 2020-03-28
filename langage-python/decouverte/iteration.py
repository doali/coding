#!/usr/bin/env python

print '---------------------------------------------------------------'
l_personne = ['Pierre', 'Paul', 'Jacques']
#l_personne = ['Pierre']

total_personne = 0

for pers_courante in l_personne:
    print pers_courante,'est dans la liste'
    total_personne = total_personne + 1

orth_personne = 'personne'
if total_personne > 1:
    orth_personne += 's'

print
print 'Au total, on compte',total_personne,orth_personne

print '---------------------------------------------------------------'
print 'Exemple d\'une boucle avec la fonction range'
for i in range(10):
    print i

print '---------------------------------------------------------------'
print 'Realisation de 3 iterations puis sortie via break'
for i in range(100):
    print i
    if i == 2:
        print 'sortie de la boucle sur la valeur',i
        break

print '---------------------------------------------------------------'
print 'Le mot clef continue permet de reprendre une iteration au debut'
print 'Afficher uniquement les nombres pairs sur [0,10]'
for i in range(10):
    if i % 2 != 0:
        continue
    print 'Code atteint uniquement si le nombre est pair :',i

print '---------------------------------------------------------------'
print 'Le mot clef pass est une instruction permettant de passer'
for i in range(5):
    pass
    print 'apres l\'instruction pass'

