# Python
_Les fondamentaux : langage de programmation interprété._

- Première version du langage en 1991 créée par ***Guido van Rossum***.
- Python Software Foundation : création en 2001

## installation
_Installé par déafut sous linux._
- `python --version` : dans un terminal renvoie la version

> Compatibilité ascendante cassée lors du passage de versions *2.X* en *3.X*

## Interpréteur
_Python est un langage interprété qui traduit évalue au fur et à mesure les instructions lue via son interpréteur._

- Accès dans la console en lançant `python[X]`
```bash
blackpc@blackpc-pc:~$ python3
Python 3.6.9 (default, Nov  7 2019, 10:44:02) 
[GCC 8.3.0] on linux
Type "help", "copyright", "credits" or "license" for more information.
>>> 
```

## Structures de données
### Les types
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