#!/usr/bin/env python2

# Retourne True si pair sinon False
def est_pair(entier):
    return (entier % 2) == 0


# Dictionnaire de donnees multiples
# - str
# - number
# - list
#   - dictionnaire
multi_data = {
    "France": "Paris",
    "Population": 70000000,
    "fonction_est_pair": est_pair,
    "course": ["jambon", "salade", {"vis": 10, "broche": 20}],
}
print multi_data

# Dictionnaire
# - str
mois_nom = [
    "janvier",
    "fevrier",
    "mars",
    "avril",
    "mai",
    "juin",
    "juillet",
    "aout",
    "septembre",
    "octobre",
    "novembre",
    "decembre",
]

# Creation d'un dictionnaire
# Remplissage d'un dictionnaire a partir d'une liste
def creation_dictionnaire_mois():
    dict_mois = {}
    numero = 1
    for element_nom in mois_nom:
        dict_mois[element_nom] = numero
        numero += 1
    return dict_mois


print creation_dictionnaire_mois()

# Suite d'instructions permettant
# - d'effectuer une saisie (raw_input -> str)
# - si la clef n'est pas trouvee dans le dictionnaire
#   alors on quitte la boucle
DICT_MOIS = creation_dictionnaire_mois()
valeur_mois = None
while True:
    mois = raw_input("Nom du mois pour la valeur [sinon taper un nombre]:")
    if DICT_MOIS.has_key(mois):
        print DICT_MOIS[mois]
    else:
        if mois.isdigit():
            if int(mois) in DICT_MOIS.values():
                l_k = DICT_MOIS.keys()
                for curr_key in l_k:
                    if int(mois) == DICT_MOIS[curr_key]:
                        print curr_key
                        break
            else:
                break
        else:
            break

# Appel de la fonction : fonction_est_pair
# definie dans le dictionnaire
f = multi_data.get("fonction_est_pair")
for entier in range(6):
    print entier, "est pair ? :", f(entier)
