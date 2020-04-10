# Langage Python
_Un peu autour de ***python***_

# Python et `__main___`
***python, \_\_main\_\_, \_\_doc\_\_, shebang, exec***

_Idiome python utilisé pour indiquer le point d'entrée d'un programme_

-> [`__main__`](doc/main.md)

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

# Expressions régulières
_Expression symbolique permettant de rechercher des motifs_

-> [regex](doc/regex.md)

## Expressions
|Expression|Description|
|----------|-----------|
|.|1 caractère quelconque (table ASCII)|
|[0-9]|0 1 2 3 4 5 6 7 8 9|
|[a-z]|minuscules de a à z|
|[A-Z]|majuscules de A à Z|
|[a-zA-Z]|une minuscule ou une majuscule|
|R|uniquement le caratère R|
|[1-4]|1 2 3 4|
|[ABCD]|soit A, B, C ou D|
|\\|caractère d'échappement|
|.*|aucun ou plusieurs caractères|

---

# Environnement Virtuel et Modules
***freeze, venv, pyvenv***

_Travailler dans un environnement virtuel pour ne pas impacter la configuration globale de la machine_

-> [virtual env](doc/virtualenv.md)

## Sommaire
- En bref
- Créer un ENV
  - Basculer dans un ENV
   - Entrer
   - Quitter
- Modules : export / import dans ENV
  - Export vers fichier
    - Exemple du contenu du fichier
  - Import depuis un fichier

---

## En bref
- `pip3 freeze` : renvoie sur la sortie standard tous les modules présents dans ***l'environnement courant***
- `pip3 freeze > lst_modules` : renvoie dans lst_modules tous les modules présents dans l'environnement courant
- `pip3 install -r lst_modules` : installe tous les modules décrits dans le fichier lst_module
- `python3 -m venv EXAMPLE_ENV` : créé un environnement nommé EXAMPLE_ENV
- `source EXAMPLE_ENV/bin/activate` : permet de basculer ***dans*** l'environnement (prompt modifié)
- `deactivate` : permet de quitter un environnement

---

# Python et pdb
***pdb, cgitb***
_Deboggage et trace en console_
- pdb est le module permettant de débogguer des scripts python
- cgitb est le module permettant d'enrichir les traces dans la console

-> [pdb et cgitb](doc/debog.md)

## Sommaire
- En bref

---

## En bref
- `python3 -m pdb exemple.py` : lance le déboggueur sur le script `exemple.py` qui est exécuté
- ```python
  import cgitb
  cgitb.enable(format='text')
  ```
  import du module cgitb permettant dans ce cas de renvoyer en console au format texte des traces enrichies

---

# Packager
***zipapp, `__init__.py`***

_Packager en fichier executable l'ensemble des fichiers et répertoires d'un programme python._

-> [packaging](doc/packaging.md)

## Sommaire
- En bref
- Motivations
  - Process
    - Data
    - Packager
- Remarques
  - `__main__.py`
  - Lancer directement... `-p $(which python)`
- Autre exemple

---

## En bref

- définir un répertoire global : `mkdir projet`
- rendre visible ce répertoire en ajoutant `__init__.py` dans `projet`
- ajouter un fichier d'entrée (pour le démarrage) `__main__.py` à la racine du répertoire `projet`
- compresser le répertoire global en une archive exécutable
  ```bash
  python3 -m zipapp projet -p /usr/bin/python3
  ```
  > créé le fichier `projet.pyz`
- exécuter

---

# Biblio
- [digital ocean](https://www.digitalocean.com/community/tutorials)
- [PyYAML](https://pypi.org/project/PyYAML/)
- [yaml read the docs](https://yaml.readthedocs.io/en/latest/basicuse.html)
- [yaml zet code](http://zetcode.com/python/yaml/)
- [PyYAML doc](https://pyyaml.org/wiki/PyYAMLDocumentation)# Packager
