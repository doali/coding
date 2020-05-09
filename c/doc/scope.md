# Scope

Portée d'une variable, fonction, type structuré ...définie lors de la déclaration.

## Portée locale

Variable dite locale

- définie entre `{` et `}` (définissant un bloc)
- portée de bloc

> Blocs pouvant être imbriqués \
> Variable intérieure à un bloc, de même nom qu'une variable extérieure au bloc, masque la variable extérieure

## Portée de fonction

Variable visible uniquement dans la fonction

### Exemple

- [goto.c](https://github.com/doali/coding/blob/master/c/coding/var/goto.c)

## Portée globale

_On dit encore, portée de programme_

Variable dite globale

- déclarée en dehors de toute fonction
- visible dans TOUS les fichiers (qui constituent le progamme) (modulo, include .h, extern...)

### Exemple

- [global-scope](https://github.com/doali/coding/blob/master/c/coding/var/global-scope.c)
- [global.c](https://github.com/doali/coding/blob/master/c/coding/var/scope/global.c)
- [global_h.h](https://github.com/doali/coding/blob/master/c/coding/var/scope/global_h.h)
- [global_func.c](https://github.com/doali/coding/blob/master/c/coding/var/scope/global_func.c)


## Portée de fichier

_Translation unit (portée de fichier), introduite par `static`_

### Exemple

- [static_global.c](https://github.com/doali/coding/blob/master/c/coding/var/scope/static_global.c)

## Biblio

- [Tony Zhang](https://www.amazon.fr/Langage-C-Tony-Zhang/dp/2744015180)

