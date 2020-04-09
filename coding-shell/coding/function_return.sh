#!/usr/bin/env bash

set -o nounset

# Bonne pratique
# - definir des variables locales
# - renvoyer sur la sortie standard le resultat a exploiter
function my_func()
{
    local  myresult="some value"
    echo "$myresult" # on renvoie sur la sortie standard
}

result=$(my_func) # on capture dans la variable le resultat  
echo $result
