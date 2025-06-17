# Module

Tue Jun 17 11:10:02 AM CEST 2025

Les fichiers sont issus de tests concernant la création d'un module pour par la suite créer un module evalpdf_parse_genere dans le cadre d'un projet

> La subtilité à retenir est l'arborescence et les noms des répertoires !!
> Il faut respecter une certaine structure pour pouvoir créer un module

Les commandes à garder en mémoire sont
- `python -m build` dans le répertoire où se trouve le fichier `setup.py`
- `pip install dist/mon_module.whl` dans a priori un environnement virtuel !!

> Il est important de disposer d'une connexion (et donc de configurer le proxy si nécessaire)

```bash
(evalpdf_venv) edf@localhost ~/Edf/evalpdf-webapp |9571e33 dev-optimisation-niveau-n-prod| $ pip show evalpdf_parse_genere
Name: evalpdf_parse_genere
Version: 0.2.1
Summary: 
Home-page: 
Author: 
Author-email: 
License: 
Location: /tmp/evalpdf_venv/lib/python3.9/site-packages
Requires: requests, jinja2, pandas, paramiko, defusedxml, openpyxl, lxml
Required-by: 
```
