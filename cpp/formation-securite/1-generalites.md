# Formation C++ sécurisée

> Animateur Guillaume

[slide 5]
Eviter les bogues
- conception rigoureuse
- Tests unitaires (notamment pour les réjouer dans le cadre de la non régression) 

[slide 7, 8]
- 64 bits vs 16 bits (explosion NASA)
- unités de mesure différentes
- prison profiles mal estimés (problème de conception)

[slide 11]
- DDoS : surcharger le serveur rendu inaccessible
- phishing : usurpation d'identité (mails, etc... ex : Real Estate Wealth...)
- ingénierie sociale : soutirer des informations (espion)

[slide 12]
- corrompre / endommager des données
- force brute : tester toutes les combinaisons pour trouver la bonne
- injection de code malveillant : exploiter une faille de sécurité (et récupérer des données sensibles)

[slide 13]
- MITM : Man In The Middle (lecture / modification des données)
- ransomware : demande de rançon pour déchiffrer les données
- **débordement de buffer** exploiter un espace mémoire pour y copier un executable malveillant
- sniffing : (ex findler norvégien sur NISSAN) interception et capture du trafic réseau et prise de contrôle du véhicule

[slide 18]
Le risque se mesure !!

**risque = gravité * menace * valeur**
- gravité : impact maximal (petite/moyenne/grande)
- Menace : probabilité (peu/fortement...)
- valeur : cout de la correction (automatique/manuelle)

Les risques seront donc mesurés avant toute livraison logicielle.

[slide 22]
**CWE** : Common Weakness Enumeration, identifie les failles communes (par la MITRE) des logiciels
- [top 25](https://cwe.mitre.org/top25/archive/2025/2025_kev_list.html)
CSIRT : états, universtés, ... vision davantage personnelle

La **MITRE** est l'unique responsable de la mise à jour de la liste !!
En France on dispose de l'**ANSSI** et de **CERT-FR** 

[slide 24]
**OWASP** (Open Worldwide Application Security Project)

Les 10 règles :

1. utilisateurs isolés => contrôle d'accès cassé
2. mettre le bon niveau de sécurité => cryptographie
3. vigilance saisie utilisateur => injection
4. identification des risques => conception (mauvaise)
5. mot de passe connu de tous : livraison ordinateur (codes erreurs en clair) => configuration (mauvaise)
6. non mise à jour (COTS) => composant obsolète (vulnérabilité)
7. non gestion d'une session (timeout, essai) => identification et authentification (mauvaise, permissive)
8. introduction logiciel => intégrité (station blanche)
9. réactivé / lenteur surveillance sécurité => journalisation (en défaut, mettre des limites)
10. vérifier la validité de la requête (http://localhost:8000/admin) => contrefaçon de requête côté serveur (serveur doit vérifier les requêtes)

[slide 32]
Ce qu'il faut retenir :

- Mettre le bon niveau de sécurité
- Moindre privilège (périmètre des utilisateurs)
- Validation des entrées (tous les entrants d'un logiciel)
- Intégrer la sécurité dès la conception
- Identité et accès (des utilisateurs)
- Surveillance et détection des menaces (logger, etc..)
- Mettre à jour régulièrement
- Sécuriser les flux de communication
- Gestion des erreurs sans révéler le code
- Réaliser des audits de conformité
