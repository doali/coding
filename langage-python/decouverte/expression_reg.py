#!/usr/bin/env python2

import re

# ----------------------------------------------------------------------
# Est numero de telephone
print "Regex sur des numeros de telephone"
regex_tel = re.compile(r"0([67]){1}([0-9]){8}")
liste_nbre = ['1234567890', '1', '', '0410223568', '0611224587', '062545789565785954', '0755668813', '0856478521']

def est_numero(nombre):
    return (len(nombre) == 10) and (regex_tel.search(nombre) != None)

def verifie_liste_numero(liste_nombre):
    rapport = {}
    for element in liste_nombre:
        resultat = est_numero(element)
        rapport[element] = resultat
        print 'Verifie :',element,'->',resultat
    return rapport

print "Liste de numeros a verifier",liste_nbre
print "Dico resultat"
verifie_liste_numero(liste_nbre)

print
rapport_dico = verifie_liste_numero(liste_nbre)
numero_valides = []
for clef, valeur in rapport_dico.items():
    if valeur:
        numero_valides.append(clef)

print "Liste depuis le Dico",numero_valides

# ----------------------------------------------------------------------
# Definition d'une expressions regulire
element_adn = re.compile(r"[ACGT]+")
element_adn_bis = re.compile(r"([ACGT]+)(G)(C)")

def existe_regex(phrase):
    return (element_adn.search(phrase) <> None)

liste_phrase = ['SSDFRE', 'SQFQSDF', 'SDFGTR', 'SDFQGEZR', 'ZRAT']
for phrase in liste_phrase:
    if existe_regex(phrase):
        print 'A ou bien C ou bien G ou bien T est present dans la phranse',phrase
    else:
        print 'motif non trouve dans',phrase

# Recherche d'une regex dans une phrase
print "Recherche d'une regex dans une phrase"
phrase = "On peut trouver dans un brin les acides suivants ATGC. Mais aussi TTG par exemple."
print
print "Phrase utilisee comme ressource",'\n\t->',phrase

def recherche_adn(phrase):
    if existe_regex(phrase):
        print phrase,'OK'
    else:
        print phrase,'KO'

def recherche_adn_groupe(phrase, regex_touse):
    lst_str_grp = regex_touse.findall(phrase)
    print lst_str_grp
    for grp in lst_str_grp:
        print grp,'<-',phrase

recherche_adn(phrase)
print element_adn.search(phrase).group(0)
print "-------"
recherche_adn_groupe(phrase, element_adn)
print element_adn.search(phrase).group(0)
print
recherche_adn_groupe(phrase, element_adn_bis)
print element_adn_bis.search(phrase).group(0)
print element_adn_bis.search(phrase).group(1)
print element_adn_bis.search(phrase).group(2)
print element_adn_bis.search(phrase).group(3)
print "...il faut ensuite passer a la correspondance suivante !!"

print "debut"
liste_motif = element_adn_bis.findall(phrase)
print liste_motif
print "debut"
liste_motif = element_adn.findall(phrase)
print liste_motif

# Substitution
print
print "Substitution"
phrase_connexion = "Mot de passe=12345678 pour la connexion au serveur est obsolete, il faut utiliser passe=12sDEFs6 !!"
reg_ex = re.compile(r"passe=.{8}")

print phrase_connexion

liste_token_trouve = reg_ex.findall(phrase_connexion)
for token in liste_token_trouve:
    print token,'a ete trouve'

phrase_secrete = reg_ex.sub('passe=<secret>', phrase_connexion)
print phrase_secrete

