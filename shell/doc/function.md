# Fonction

## Recuperer une _valeur de retour_

- en bash, les fonctions retournent uniquement un status
> que l'on peut observer via `${?}`
- pour simuler un retour, on renvoie sur la sortie standard
- que l'on capte ensuite lors de l'appel de la fonction

```bash
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
```

## Biblio

- [linux journal](https://www.linuxjournal.com/content/return-values-bash-functions)
