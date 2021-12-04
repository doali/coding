#!/usr/bin/env python3
# --------------------------------------------------------------------------------
# Repris du site
# https://courspython.com/interfaces.html
# --------------------------------------------------------------------------------

# importations à faire pour la réalisation d'une interface graphique
import sys
from PyQt5.QtWidgets import QApplication, QWidget, QPushButton, QVBoxLayout, QLabel

# Première étape : création d'une application Qt avec QApplication
#    afin d'avoir un fonctionnement correct avec IDLE ou Spyder
#    on vérifie s'il existe déjà une instance de QApplication
app = QApplication.instance() 
if not app: # sinon on crée une instance de QApplication
    app = QApplication(sys.argv)

# création d'une fenêtre avec QWidget dont on place la référence dans fen
fen = QWidget()

button = QPushButton("coucou")
label = QLabel("label titi")

layout = QVBoxLayout()
layout.addWidget(button)
layout.addWidget(label)
fen.setLayout(layout)

# la fenêtre est rendue visible
fen.show()

# exécution de l'application, l'exécution permet de gérer les événements
app.exec_()
