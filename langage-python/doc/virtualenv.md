# Environnement Virtuel et Modules
***freeze, venv, pyvenv***

_Travailler dans un environnement virtuel pour ne pas impacter la configuration globale de la machine_

<- [home](../README.md)

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

## Créer un ENV
```bash
python3 -m venv EXAMPLE_ENV
```
> Créé un répertoire EXAMPLE_ENV contenant tout un environnement autonome

### Basculer dans un ENV
#### Entrer
```bash
source EXAMPLE_ENV/bin/activate
```

> Active l'environnement (ce qui peut avoir pour effet de changer le prompt)
#### Quitter
```bash
deactivate
```

## Modules : export / import dans ENV
_On souhaite importer une liste de modules que l'on a exportés d'un autre environnement_

### Export vers fichier
```bash
pip3 freeze > module_contextuel
```
> Exporte tous les modules versionnés vers le fichier `module_contextuel`

#### Exemple du contenu du fichier
```bash
cat module_contextuel
```
```
Jinja2==2.11.1
libvirt-python==6.0.0
MarkupSafe==1.1.1
pkg-resources==0.0.0
pycdlib==1.9.0
PyYAML==5.3
```

### Import depuis un fichier
```bash
pip3 install -r module_contextuel
```
> Installe tous les modules versionnés spécifiés dans le fichier module_contextuel
