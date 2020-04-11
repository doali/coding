# Python et pdb
***pdb, cgitb***
_Deboggage et trace en console_
- pdb est le module permettant de débogguer des scripts python
- cgitb est le module permettant d'enrichir les traces dans la console

<- [home](../README.md)

## Sommaire
- En bref
- pdb
  - Exemple
- cgitb

---

## En bref
- `python3 -m pdb exemple.py` : lance le déboggueur sur le script `exemple.py` qui est exécuté
- ```python
  import cgitb
  cgitb.enable(format='text')
  ```
  import du module cgitb permettant dans ce cas de renvoyer en console au format texte des traces enrichies

---

## pdb
_Déboggueur en console avec prompt de python_.

> Il existe également d'autres déboggueurs tels que : pdb-clone, pudb, ipdb, ...

### Exemple

_Admettons que nous ayons le script suivant `division_zero.py`_

```python
     1	#!/usr/bin/env python3
     2	"""Python script"""
     3
     4	def div(a, b):
     5	    """Division"""
     6	    return a / b
     7
     8	if __name__ == '__main__':
     9	    """Entry point"""
    10	    div(10, 0)
```
- lançons le déboggueur : `python3 -m pdb division_zero.py`
- on obtient l'invite de commande
  ```bash
    > /tmp/division_zero.py(2)<module>()
    -> """Python script"""
    (Pdb)
  ```
  > avec le pointeur positionné sur la première ligne suivant le `shebang` `#!`
- plaçons un breakpoint au niveau de la fonction `div`
  - soit en indiquant la ligne `b 4`
  - soit en utilisant le nom `b div`
  ```bash
    (Pdb) b div
    Breakpoint 1 at /tmp/division_zero.py:4
    (Pdb)
  ```
- observons le code `ll` ou bien `l`
  ```bash
  (Pdb) ll
  1  	#!/usr/bin/env python3
  2  ->	"""Python script"""
  3
  4 B	def div(a, b):
  5  	    """Division"""
  6  	    return a / b
  7
  8  	if __name__ == '__main__':
  9  	    """Entry point"""
  10  	    div(10, 0)
  (Pdb)
  ```
  > `B` indique notre breakpoint
- pour avoir un peu d'aide il suffit de taper : `help`
  ```bash
  (pdb) help
  ```
- pour se rendre directement au point d'arrêt : `c`
  ```bash
  (pdb) c
  ```
- pour exécuter une instruction : `n`
- pour afficher le contenu d'une variable ma_variable : `print(ma_variable)`
- ...

## cgitb
_Module permettant d'obtenir une trace détaillée des erreurs en console_

### Exemple
_Reprenons le script précédent `division_zero.py`_

- ajoutons les traces
  ```python
  import cgitb
  cgitb.enable(format='text')
  ```
- ce qui donne le code suivant
    ```python
        1	#!/usr/bin/env python3
        2	"""Python script"""
        3
        4	import cgitb
        5	cgitb.enable(format='text')
        6
        7	def div(a, b):
        8	    """Division"""
        9	    return a/b
        10
        11	if __name__ == '__main__':
        12	    """Entry point"""
        13	    print(__doc__)
        14
        15	    div(10, 0)
        16
    ```
- son exécution renvoie une multitude d'informations concernant l'erreur survenue lors de son lancement suite à la division par zéro
  - `./division_zero_trace.py`
    ```bash
    Python script
    ZeroDivisionError
    Python 3.6.9: /usr/bin/python3
    Sun Feb 16 16:26:41 2020

    A problem occurred in a Python script.  Here is the sequence of
    function calls leading up to the error, in the order they occurred.

    /tmp/division_zero_trace.py in <module>()
    12     """Entry point"""
    13     print(__doc__)
    14
    15     div(10, 0)
    16
    div = <function div>

    /tmp/division_zero_trace.py in div(a=10, b=0)
        7 def div(a, b):
        8     """Division"""
        9     return a/b
    10
    11 if __name__ == '__main__':
    a = 10
    b = 0
    ZeroDivisionError: division by zero
    [...]
    ```
