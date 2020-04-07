# Python et `__main___`
***python, \_\_main\_\_, \_\_doc\_\_, shebang, exec***

_Idiome python utilisé pour indiquer le point d'entrée d'un programme_

<- [home](../README.md)

## Sommaire
- En bref
- Problématique
  - Exemple
- En pratique
- Bonnes pratiques
- Autre exemple
- Biblio

---

## En bref

```python
# Entry point of the script
if __name__ == '__main__':
    pass
```

---

## Problématique
Python
- ne dispose pas d'une méthode, fonction `main()` comme les autres langages : qui pourrait alors nous fournir un point d'entrée à l'exécution du programme
- permet d'importer des modules : qui peuvent s'exécuter potentiellement indépendamment... mais on voudrait les utiliser comme une "lib" dans notre programme principal et non pas qu'ils s'exécutent **lors** de leur **import** !!

_En conséquence, lors de l'exécution d'un script, tout le script est exécuté à partir de la ligne qui suit le shebang. Pas de point d'entrée particulier... et lors d'un import d'un autre script, c'est la même chose... il faut donc trouver un moyen de **contrôler** le **point d'entrée** d'exécution._

### Exemple
```python
#!/usr/bin/env python
# lapin.py

def langue():
    print('le lapin')

langue()
```
`./lapin.py`
> le lapin
```python
#!/usr/bin/env python3
# faune.py

import lapin

def parle_ici():
    lapin.langue()

parle_ici()
```
`./faune.py`
> le lapin
>
> le lapin

***Problème*** lors de l'exécution de `./faune.py` nous avons obtenu deux fois le même message _le lapin_.
- car l'instruction `import lapin` (voire cela comme un copier / coller) a entrainé l'exécution de la fonction `langue()` du script `lapin.py`.
- On serait tenté de modifier `lapin.py` en commentant la ligne comme suit `#langue()` mais ce serait altérer le comportement du fichier...

***Solution***
```python
#!/usr/bin/env python
# lapin.py

def langue():
    print('le lapin')

if __name__ == '__main__':
    langue()
```

***Explication***
- on utilise la valeur de `__name__`
  - variable automatiquement créée
  - toujours disponible partout (dans tous les scripts...)
  - contient ***le nom du module*** (ou fichier) lorsqu'on fait un import _(dans notre script courant)_
  - contient la valeur `__main__` dans le script courant _(celui qu'on exécute)_

Par conséquent si le test `__name__` == `'__main__'` est :
- vrai : le programme en cours d'exécution est le programme principal
- faux : il s'agit d'un module importé et `__name__` contient le nom du module (fichier, script, ...)

## En pratique
***Toujours ajouter***
```python
# Entry point of the script
if __name__ == '__main__':
    pass
```
- si l'on sait que notre script sera ***exécuté*** directement ou bien utilisé comme lib.

## Bonnes pratiques
- `#!/usr/bin/env python` : utilise le premier interprêteur _python_ trouvé dans la variable PATH
  - (`python` ou `python2` ou `python3` peuvent-être indiqués)
- `"""Commentaire"""` : respecter le standard PEP en ajoutant des commentaires
- `if __name__ == '__main__'` : indique le point d'entrée du programme
```python
#!/usr/bin/env python3
"""
Good habit
- __doc__ to document
- __main__ to specify entry point
"""
print(__doc__)

def main():
    """Let us say that this is our main method"""
    print(main.__doc__)

# Entry point of the script
if __name__ == '__main__':
    main()
```
## Autre exemple
_En affichant la valeur de la variable `__name__`._

```bash
host  /tmp  cat lapin.py
```

```python
#!/usr/bin/env python
# lapin.py

def langue():
    print('lapin.py : __name__',__name__)
    print('le lapin')

if __name__ == '__main__':
    langue()
```

```bash
host  /tmp  ./lapin.py
```

```python
('lapin.py : __name__', '__main__')
le lapin
```

```bash
host  /tmp  cat faune.py
```
```python
#!/usr/bin/env python3
# faune.py

import lapin

def parle_ici():
    lapin.langue()

print('faune.py : __name__',__name__)
parle_ici()
```

```bash
host  /tmp  ./faune.py
```

```python
faune.py : __name__ __main__
lapin.py : __name__ lapin
le lapin
```

# Biblio
- [`if __name__ == __main__:`](http://sametmax.com/pourquoi-if-__name__-__main__-en-python/)
- [PEP 257](https://www.python.org/dev/peps/pep-0257/)
- [shebang -> `#!` et `env`](https://stackoverflow.com/questions/2429511/why-do-people-write-the-usr-bin-env-python-shebang-on-the-first-line-of-a-pyt)
- [exec, kernel](https://stackoverflow.com/questions/2429511/why-do-people-write-the-usr-bin-env-python-shebang-on-the-first-line-of-a-pyt)
