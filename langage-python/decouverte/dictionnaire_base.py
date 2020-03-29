#!/usr/bin/env python2

PROTOCOLES = ['ssh', 'tftp', 'telnet', 'ftp', 'http', 'https','snmp','ntp']
print PROTOCOLES

# Creation d'un dictionnaire explicite
PROTOCOLE_PORT = {'ssh':22,'tftp':69,'telnet':23,'ftp':21,'http':80,'https':443}
print PROTOCOLE_PORT

# Creation d'un dictionnaire vide
DICO_VIDE = {}
print DICO_VIDE

# Ajout d'une clef
DICO_VIDE['clef_1'] = 1
print DICO_VIDE

# Affichage d'une valeur etant donnee une clef
print DICO_VIDE['clef_1']
print DICO_VIDE.get('clef_1')

# Teste l'existence d'une clef
print DICO_VIDE.has_key('clef_1')
print DICO_VIDE.has_key('clef_2')
if (not DICO_VIDE.has_key('clef_2')):
    DICO_VIDE['clef_2'] = 2

# Suppression d'une clef
nom_clef = 'clef_1'
if DICO_VIDE.has_key(nom_clef):
    print 'Valeur de',nom_clef,'est :',DICO_VIDE.get(nom_clef)
    nouvelle_valeur = 'clef_nouvelle'
    print 'Remplacement de la valeur :',DICO_VIDE[nom_clef],' par :',nouvelle_valeur
    DICO_VIDE[nom_clef] = nouvelle_valeur
    print 'Valeur de',nom_clef,'est :',DICO_VIDE.get(nom_clef)
    print 'Suppression de la clef :',nom_clef,' et de sa valeur :',DICO_VIDE[nom_clef]
    print DICO_VIDE
    print 'Apres suppression'
    del DICO_VIDE[nom_clef]
    print DICO_VIDE

# Suppression complete d'un dictionnaire
print 'Etat du dictionnaire',DICO_VIDE
DICO_VIDE.clear()
print 'Suppression complete du dictionnaire',DICO_VIDE

# Affichage dictionnaire
print PROTOCOLE_PORT

liste_items = PROTOCOLE_PORT.items()
print liste_items

liste_keys = PROTOCOLE_PORT.keys()
print liste_keys

liste_values = PROTOCOLE_PORT.values()
print liste_values

# Iterer sur un dictionnaire
for clef in PROTOCOLE_PORT.iterkeys():
    #print type(clef)
    print clef

for value in PROTOCOLE_PORT.itervalues():
    #print type(value)
    print value

for item in PROTOCOLE_PORT.items():
    #print type(item)
    print item

# Autre iteration
for clef in PROTOCOLE_PORT.keys():
    #print type(clef)
    print clef

for value in PROTOCOLE_PORT.values():
    #print type(value)
    print value

# Autre parcours
for key, value in PROTOCOLE_PORT.items():
    #print type(item)
    print key, value

# Commande help(...)
#help(list)
#help(dict)
#help(tuple)
