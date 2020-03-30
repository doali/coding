#!/usr/bin/env python2

print "---------------------------------------------------------------"
print "Liste, conteneur multi-ensemble"
l_1 = []
l_2 = [1, 2]
l_3 = ["a", 2, "chaine", 1.0]

print l_1
print l_2
print l_3

print "---------------------------------------------------------------"
print "Definition d'une liste via range"
l = range(10)
print l
print "Taille %s" % len(l)

print "---------------------------------------------------------------"
print "Quelques methodes des listes"

l = range(10)
print l

l.append(11)
print l

l_ind_0 = l.__getitem__(0)
print l_ind_0

print l.__getitem__(3)
print l[3]

print "Derniere valeur %s" % (l[-1])
print "Avant derniere valeur %s" % (l[-2])

print "---------------------------------------------------------------"
l = []
l.append(["x", "x * x"])
l.append([0, 0])
l.append([1, 1])


def carre(n):
    return n * n


indices = range(2, 10)
for i in indices:
    l.append([i, carre(i)])

print l
print "Entete %s" % (l[0])

print "---------------------------------------------------------------"
msg = "coucou"
print msg

cpt_lettre = 0
for lettre in msg:
    cpt_lettre += 1
    print cpt_lettre, "->", lettre

print "Taille du message :%s est de %s" % (msg, len(msg))

print "---------------------------------------------------------------"
print "Concatenation"

l_1 = range(5)
l_2 = range(5, 10)

l_1_2 = l_1 + l_2

print l_1
print l_2
print "concatenation de %s et %s pour le resultat suivant %s" % (l_1, l_2, l_1_2)

print "---------------------------------------------------------------"
print "Reverse d'une liste"
l = [1, 2, 3, 4]
print l
l.reverse()
print l

print "---------------------------------------------------------------"
l = range(7)
l.reverse()
print "Tri de la liste", l
l.sort()
print l

print "---------------------------------------------------------------"
val_1 = 3
val_2 = 7
l = range(6)
print "La liste %s contient la valeur %s ? : %s et la valeur %s ? : %s" % (
    l,
    val_1,
    l.__contains__(val_1),
    val_2,
    l.__contains__(val_2),
)


print "---------------------------------------------------------------"
l = range(3) + range(3)
l.append(2)
print "%s contient %s occurrence(s) de la valeur 2" % (l, l.count(2))

print "---------------------------------------------------------------"
l = [1, 2, 2, 3, 4, 2, 3]
val = 2
print "Soit la liste %s contenant %s occurrences de la valeur %s" % (
    l,
    l.count(val),
    val,
)
print "La liste contenant les indices des occurrences de %s" % val
pass
l_occ_val = []
print "est la suivante"
indice = 0
for element in l:
    if element == val:
        l_occ_val.append(indice)
    indice += 1

print l_occ_val
print "Autre facon de faire en utilisant [<indice_debut>:<indice_fin>] sous tableau du tableau initial"
nb_occurence = l.count(val)
pointeur_indice = 0
resultat = []
while nb_occurence > 0:
    tableau_etudie = l[pointeur_indice:]
    indice_occ = tableau_etudie.index(val)
    pointeur_indice += indice_occ
    resultat.append(pointeur_indice)
    pointeur_indice += 1
    nb_occurence -= 1
    print tableau_etudie, resultat

print "Liste des indices", l_occ_val

print "---------------------------------------------------------------"
l = [1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5]
print "Suppression de tous les doublons de la liste", l
print "- la premiere occurrence est conservee"


def aux_supprime_doublon(element, liste):
    if liste == []:
        return []
    if len(liste) == 1:
        if element == liste[0]:
            return []
        else:
            return liste
    if liste[0] == element:
        return aux_supprime_doublon(element, liste[1:])
    else:
        return [liste[0]] + aux_supprime_doublon(element, liste[1:])


print "Fonction auxilliaire suppression de toutes les occurrences d'un element"
for val in l:
    print "supprime", val, "->", aux_supprime_doublon(val, l)


def supprime_doublon(l):
    if l == []:
        return []
    elif len(l) == 1:
        return l
    else:
        return [l[0]] + supprime_doublon(aux_supprime_doublon(l[0], l))


print "La liste formee d'elements uniques est donc :", supprime_doublon(l)

l = []
print "Avec liste :", l, "->", supprime_doublon(l)
l = [1]
print "Avec liste :", l, "->", supprime_doublon(l)
l = [1, 1]
print "Avec liste :", l, "->", supprime_doublon(l)

print
l = [1, 2, 3, 3, 3, 4, 5, 4, 4, 4, 5, 6, 5, 2, 1, 2, 3, 2, 6]
print "Liste initiale", l, "->", supprime_doublon(l)


def supprime_occurrence(e, liste):
    while liste.__contains__(e) and liste.count(e) > 1:
        liste.remove(e)


def supprime_doublon_python(liste):
    tmp_liste = liste[:]
    for element in tmp_liste:
        supprime_occurrence(element, liste)
    return liste


print
l1 = [1, 2, 3, 3, 4, 5, 4, 4, 5, 6, 5, 2, 1, 2, 3, 2, 6, 8, 9, 1, 1, 1, 1, 2]
print "Liste initiale", l1
print "methode avec fonctions/methodes python ->"
print "\t", supprime_doublon_python(l1)
print "si on trie la liste"
l1.sort()
print "\t", l1
l2 = [1, 2, 3, 3, 4, 5, 4, 4, 5, 6, 5, 2, 1, 2, 3, 2, 6, 8, 9, 1, 1, 1, 1, 2]
print "methode recursive ->"
print "\t", supprime_doublon(l2)

print "---------------------------------------------------------------"
