#!/usr/bin/env python2

# Retourne True si pair sinon False
def est_pair(entier):
    return (entier % 2) == 0


multi_data = {"fonction_est_pair": est_pair}


# Appel de la fonction : fonction_est_pair
# definie dans le dictionnaire
f = multi_data.get("fonction_est_pair")
for entier in range(6):
    print entier, "est pair ? :", f(entier)
