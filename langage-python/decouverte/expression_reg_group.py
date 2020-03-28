#!/usr/bin/env python2

import re

# Recherche d'un mot pouvant etre le nom d'un protocole
regex_capital = re.compile(r"\ [A-Z]+\ ")

# Extrait de wikipedia
msg = "9, pour le WoL, Wake-on-LAN, c est-a-dire le demarrage a distance par un cable reseau ethernet. Wake-on-LAN 20/21, pour l echange de fichiers via FTP 22, pour l acces a un shell securise Secure SHell, egalement utilise pour l echange de fichiers securises SFTP 23, pour le port telnet 25, pour l envoi d un courrier electronique via un serveur dedie SMTP 53, pour la resolution de noms de domaine en adresses IP : DNS 67/68, pour DHCP et bootpc 69, pour le TFTP 80, pour la consultation d un serveur HTTP par le biais d un navigateur web 110, pour la recuperation de son courrier electronique via POP 123, pour la synchronisation de l horloge : Network Time Protocol (NTP) 143, pour la recuperation de son courrier electronique via IMAP 389, pour la connexion a un LDAP"

def est_en_capital(phrase):
    return (regex_capital.search(phrase) <> None)

def extraire_protocole(texte):
    return regex_capital.findall(texte)

# Tests : est_en_capital
liste_test = ['a', 'A', 'aBa', 'ZZZ', 'F', '', 'P']
for element in liste_test:
    if est_en_capital(element):
        print element,'est en lettres capitales'
    else:
        print element,'ne satisfait pas la regex'

# Tests : extraire_protocole
list_groupe = extraire_protocole(msg)

for grp in list_groupe:
    print grp
