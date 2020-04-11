# Python
_Les fondamentaux : langage de programmation interprété._

- Première version du langage en 1991 créée par ***Guido van Rossum***.
- Python Software Foundation : création en 2001

## installation
_Installé par défaut sous linux._
- `python --version` : dans un terminal renvoie la version

> Compatibilité ascendante cassée lors du passage de versions *2.X* en *3.X*

## Interpréteur
_Python est un langage interprété qui traduit évalue au fur et à mesure les instructions lues via son interpréteur._

- Accès dans la console en lançant `python[X]`

```bash
blackpc@blackpc-pc:~$ python3
Python 3.6.9 (default, Nov  7 2019, 10:44:02) 
[GCC 8.3.0] on linux
Type "help", "copyright", "credits" or "license" for more information.
>>> 
```

## Commentaires
- `#` : introduit une ligne de commentaires

## Structures de données

### Les types
- `None` : valeur vide
- `True, False`

```python
>>> True
True
>>> type(True)
<class 'bool'>
>>> False
False
>>> type(False)
<class 'bool'>
>>> None
>>> type(None)
<class 'NoneType'>
>>> 
```

- `type(<nom_variable|nom_type>)>` : renvoie le type

```python
>>> class MaClasse:
...     pass
... 
>> l_type = [0, 1.0, 'c', 'str', (1, 2, 'a', {'clef': 3.14}), [1, 2], {'clef': 10}]
>>> l_type
[0, 1.0, 'c', 'str', (1, 2, 'a', {'clef': 3.14}), [1, 2], {'clef': 10}]
>>> inst_MaClasse = MaClasse()
>>> l_type.append(inst_MaClasse)
>>> l_type
[0, 1.0, 'c', 'str', (1, 2, 'a', {'clef': 3.14}), [1, 2], {'clef': 10}, <__main__.MaClasse instance at 0x7fb70c6d5370>]
>>> def affiche(liste):
...     for element in liste:
...             print("{} <- {}".format(element, type(element)))
... 
>>> 
```

ce qui nous permet de vérifier les types présents suivants

```python
>>> affiche(l_type)
0 <- <type 'int'>
1.0 <- <type 'float'>
c <- <type 'str'>
str <- <type 'str'>
(1, 2, 'a', {'clef': 3.14}) <- <type 'tuple'>
[1, 2] <- <type 'list'>
{'clef': 10} <- <type 'dict'>
<__main__.MaClasse instance at 0x7fb70c6d5370> <- <type 'instance'>
>>> 
```

...ajout concernant les `class`

```python
>>> class MaClass:
...     pass
... 
>>> inst_MaClass = MaClass
>>> inst_2_MaClass = MaClass()
>>> type(MaClass)
<class 'type'>
>>> type(inst_MaClass)
<class 'type'>
>>> type(inst_2_MaClass)
<class '__main__.MaClass'>
>>> 
```

## Opérateurs

### Comparaisons
- `<, >, <=, >=, ==, !=`

### Logiques
- `and, or, not`

### Binaires
- `<<, >>, &, ^, |, ~` 
  - `^` : xor
  - `~` : complémentaire (not)

## Structures de contrôles
- `if [(]<condition>[)]: [...] [elif <condition>:] [...] [else:]` : si, alors si, ..., sinon

```python
a = 1 
if a > 10: 
    print('a > 10')
elif a == 10: 
    print('a == 10')
else:
    print('a < 10')
```

## Itérations
- `while <condition>: [...]`
```python
#!/usr/bin/env python3

import time

timer = 0.8
nb_cycle = 5

print("debut timer de + " + str(timer) + " seconde")

cpt = 0
while cpt < nb_cycle:
    cpt += 1
    print(cpt)
    time.sleep(timer)

print("fin timer")
```
- `for <element> in <sequence>: [...]`
```python
#!/usr/bin/env python3

import sys

# Python3 => utilisation de list
l = list(range(10))

for element in l:
    sys.stdout.write(element.__str__())
    sys.stdout.flush()
```
### Rupture et reprise 
- `break` : sortie de boucle immédiate
- `continue` : reprise immédiate au début de la boucle

## Fonctions
- `def <nom_fonction>([arg1, arg2=<valeur_defaut>, ...]): [...]` : les `()` sont obligatoires
> (!) la signature d'une fonction est réduite à nom \
> Du coup, si deux fonctions portent le même nom, c'est la définition de la dernière qui sera prise en compte !

```python
>>> def f():
...     pass
... 
>>> f
<function f at 0x7fcaa4e3abf8>
>>> f()
>>> 
```
- ordre des arguments libres lors de l'appel ***si*** présence de valeurs par défaut de définies
```python
#!/usr/bin/env python3

def f_val_defaut(a, b=2, c=3):
    print(a, b, c)

f_val_defaut(1, c=4, b=0)
```
- qui renvoie
```bash
1 0 4
```

## Astuces
- permuter des va>leurs : `<var_a>, <var_b> = <var_b>, <var_a>`

```python
>>> a, b = 1, 2
>>> a
1
>>> b
2
>>> a, b = b, a
>>> a
2
>>> b
1
>>> 
```

## Documenter
_Utilisation des ***docstring*** introduites par `"""`...`"""`_

Exemple d'un fichier comportant des commentaires ***docstring***
```python
#!/usr/bin/env python
"""
Good habit
- __doc__ to document
- __main__ to specify entry point
"""
print(__doc__)

def create_complex(real=0.0, imag=0.0):
    """Form a complex number.

    Keyword arguments:
    real -- the real part (default 0.0)
    imag -- the imaginary part (default 0.0)
    
    """
    return [real, imag]


def main():
    """Let us say that this is our main method"""
    print(main.__doc__)
    l = create_complex(1, 2)
    print(l)

# Entry point of the script
if __name__ == '__main__':
    main()
```
- on peut obtenir l'aide sur tout notre module `main` en tapant `help(main)` depuis l'interpreteur (lancé dans le même répertoire contenant notre module défini par `main.py`)
```python
Python 3.6.9 (default, Nov  7 2019, 10:44:02) 
[GCC 8.3.0] on linux
Type "help", "copyright", "credits" or "license" for more information.
>>> import main

Good habit
- __doc__ to document
- __main__ to specify entry point

>>> help(main)

>>> 
```
- qui produit le résultat suivant
```bash
Help on module main:

NAME
    main

DESCRIPTION
    Good habit
    - __doc__ to document
    - __main__ to specify entry point

FUNCTIONS
    create_complex(real=0.0, imag=0.0)
        Form a complex number.
        
        Keyword arguments:
        real -- the real part (default 0.0)
        imag -- the imaginary part (default 0.0)
    
    main()
        Let us say that this is our main method

FILE
    /home/blackpc/git-github/computing/langage-python/decouverte/docstring/main.py
```
- de même 
```python
Python 3.6.9 (default, Nov  7 2019, 10:44:02) 
[GCC 8.3.0] on linux
Type "help", "copyright", "credits" or "license" for more information.
>>> import main

Good habit
- __doc__ to document
- __main__ to specify entry point

>>> help(main.create_complex)

>>> 
```
- produit le résultat
```bash
create_complex(real=0.0, imag=0.0)
    Form a complex number.
    
    Keyword arguments:
    real -- the real part (default 0.0)
    imag -- the imaginary part (default 0.0)
(END)
```

## Biblio
- [Pierre Giraud](https://www.pierre-giraud.com/python-apprendre-programmer-cours/introduction/)
