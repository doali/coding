#!/usr/bin/env bash

# ------------------------------------------------------------------------------
# Preparation de l'environnement pour utiliser
#- flask
#- emettre des requetes 
# ------------------------------------------------------------------------------

# list des modules installés 
# au niveau global
#pip3 freeze

# création d'un environnement virtuel python
# nommé FLASK
python3 -m venv FLASK

# Activation de l'environnement FLASK
source FLASK/bin/activate

# Installation des modules pour
# - flask
pip3 install flask
pip3 install requests

# liste des modules installés
# dans l'environnement virtuel
#pip3 freeze

# Sauvegarde
#pip3 freeze >requirements_flask

# Chargement, installation de modules
# depuis un fichier d'export
#pip3 -r requirements_flask
