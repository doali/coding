# Packager
***zipapp, `__init__.py`***

_Packager en fichier executable l'ensemble des fichiers et répertoires d'un programme python._

<- [home](../README.md)

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

## Motivations
_Fournir un seul fichier exécutable._

### Process
#### Data
- considérons la hiérarchie suivante : `tree projet`
    ```bash
    projet
    ├── __init__.py
    ├── lib.py
    └── __main__.py

    0 directories, 3 files
    ```
- `cat __ini__.py`
  > fichier vide
- `cat lib.py`
    ```bash
    #!/usr/bin/env python3
    """Script"""

    def affiche():
        """Affiche un message"""
        print('Execution de la fonction affiche')
    ```
- `cat __main_.py`
    ```bash
    #!/usr/bin/env python3

    import lib

    lib.affiche()
    ```
#### Packager
- compresser le répertoire global `projet` en une archive exécutable
  ```bash
  python3 -m zipapp projet
  ```
  > créé le fichier `projet.pyz`
- exécuter : `python3 projet.pyz`

## Remarques
### `__main__.py`
_on peut s'affranchir de l'existence du fichier __main__.py en faisant_
```bash
python3 -m zipapp projet -m "lib:affiche"
```
- et exécuter : `python3 projet.pyz`
- ***Ou bien encore avec exécution directe***
  - ou bien en archivant comme ceci : `python3 -m zipapp projet -m "lib:affiche" -p /usr/bin/python3`
  - et exécuter directement : `./projet.pyz`

### Lancer directement... `-p $(which python)`
_on peut lancer ***directement*** le script en indiquant où se trouve python via l'option `-p` suivie du path de python_

- ```bash
  python3 -m zipapp projet -p /usr/bin/python3
  ```
- ou encore de cette façon `python3 -m zipapp projet -p $(which python)`"

## Autre exemple
- `tree projet`
    ```bash
    projet
    ├── lib.py
    └── __main__.py

    0 directories, 2 files
    ```
- `cat lib.py`
    ```bash
    def affiche():
        print('Fonction affiche dans lib')
    ```
- `cat __main__.py`
    ```bash
    import lib

    lib.affiche()
    ```
- `python3 -m zipapp projet -p /usr/bin/python3`
  > Crée l'archive : `projet.pyz`
- `./projet.pyz`
  > Fonction affiche dans lib
