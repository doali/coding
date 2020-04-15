#!/usr/bin/env python

CLEF=3
MAX_ESSAI = 10

print 'Essayez de trouver le nombre cache'

resultat = 0
nb_essai = 0

while resultat != CLEF and nb_essai < MAX_ESSAI:
    resultat = int(raw_input('>'))
    nb_essai = nb_essai + 1

if resultat == CLEF:
    print('Bravo')
else:
    print('Vous pouvez toujours rejouer !')

