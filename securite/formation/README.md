# Ateliers secure coding C C++

## Quelques environnement en ligne
* [gitpod.io](https://www.gitpod.io/)
* [compiler explorer](https://godbolt.org/)
* [OnlineGDB](https://www.onlinegdb.com/online_c_compiler)


## Désactivation de ASLR
### Address Space Layout Randomization
Certains ateliers nécessitent de désactiver le mécanisme d'ASLR

#### Sous Linux : désactivation du mécanisme ASLR
* `sudo sysctl kernel.randomize_va_space=0`   
    * Liste des valeurs possibles
        * 0 : ASLR désactivé
        * 1 : conservative randomisation
        * 2 : full randomisation

#### Par les options de compilation GCC
`gcc -ggdb -no-pie -fno-pie source.c -o main`


## Utiliser la ligne de commande pour injecter des données
Par utilisation de la substitution de commande et un script
### substitution de commande
`echo $("commande")`
* exemple `echo $("ls")` provoque l'exécution de la commande `ls`

### utilser python
* l'option `-c` permet de passer une commande python en tant que chaîne de caractères
* `python -c 'print 2+2'`
#### ajouter une adresse dans la chaîne de caractère générée par python
une fois l'adresse trouvée, par exemple : **0x4011de** l'envoi de l'adresse octet par octet est effectué dans le sens inverse
* car little endian pour Intel
* il faut injecter les octets `0xde`, `0x11`, `0x40`, `0x00`

#### python 2
* `echo $(python2 -c 'print 2+2')` affichera 4
* `echo $(python2 -c 'print "a" * 10')` affichera 10 caractères "a"
* `echo $(python2 -c 'print "a" * 10 + "\xde\x11\x40\x00"')` affichera 10 caractères "a" suivi des 4 octets

#### python 3
`print()` utilise UTF8 sur deux octets, il faut utiliser `sys.stdout.buffer.write()` en précisant le code format **b**
* `echo $(python3 -c "import sys; sys.stdout.buffer.write(b'a' * 10 + b'\xde\x11\x40\x00')")` 

### le tout ensemble
* `./main $(python -c "print('A'*10)")`  
permet d'envoyer la chaîne de caractères générée par python vers l'entrée standard de notre programme 

## Atelier 'Etude de la pile'
### Objectif
Connaître le focntionnement de la pile

### Todo
A l'aide du fichier `stack.c` étudiez la pile
* avant l'appel de la méthode `add(int,int)`
* à l'intérieur de la méthode `add(int,int)`
* avant l'appel de la fonction `printf`
Remarquez
* le passage de paramètres
* l'évolution des registres `ESP` et `EBP`
* comment est mise en place l'adresse de retour
    * `call` place le contenu du registre `IP` sur la pile
    * `ret` dépile le contenu de la pile et met à jour le registre `IP`

### Quelques commandes `gdb`
voir le fichier GDB `cheatsheet.pdf`
* `break` : place un point d'arrêt
    * `break add`
    * `break stack.c:14`
    * `break *0x400573`
* vues
    * `tui enable` / `tui disable` pour afficher la console
    * `layout src` : affiche les sources
    * `layout asm` : affiche l'assembleur
    * `layout regs` : affiche les registres
    * `focus` : donne le focus à un layout particulier (src, cmd, asm, ...)
* examiner la mémoire
    * `x/8wx $esp`
        * affiche 8 words au format hexa depuis l'adresse contenu dans ESP
* pas à pas
    * `s` : pas à pas profond dans les sources
    * `n` : pas à pas de surface dans les sources
    * `si` : pas à pas profond dans l'assembleur
    * `ni` : pas à pas de surface dans l'assembleur

## Atelier 'ASLR'
### Objectif
Vérifier le comportement du mécanimse ASLR
### Todo
Reprenez le fichier `stack.c` et ajouter l'affichage de l'adresse de la fonction `add(int,int)`  
Vérifiez que l'adresse varie d'une exécution à l'autre.  
Désactivez l'ASLR et vérifez que l'adresse ne varie plus.

## Atelier 'SSP'
### Objectif
Vérifier le comportement du mécanimse SSP
### Todo
Avec le fichier `ssp.c`  
Utilisez l'option `-fno-stack-protector` et `-fstack-protector` pour désactiver et activer la détection débordement de buffer.

## Atelier 'CWE 131'
### Todo
Exécutez le code en passant différentes valeurs
* positive, 0, -1 , -10  

Trouvez une parade simple pour éviter le core dump.

## Atelier 'CWE 190'
### Todo
Etudiez le code du fichier `cwe_190.c`.Sur une plateforme 32 bits à partir de quelle valeur donnée au programme atteint-on une BoF (buffer overflow).

## Atelier 'CWE 120' 
### Objectif
Faire exécuter une fonction par injection de son adresse par la ligne de commande

## Todo
Faire exécuter la fonction `_got_root()`

## Atelier 'BigInteger'
### Objectif
Découvrir la librairie boost cpp_int

### Todo
Installer boost
* `sudo apt-get install libboost-all-dev`
* Vérifiez que l'exemple `bigint.cpp` compile et s'exécute
* Implémentez une fonction qui calcule la factorielle d'un nombre entier très grand en utilisant `cpp_int`

## Atelier 'inline'
### Objectif
* Comprendre la différence entre les fonctions inline et les macros
### Todo
Avec le code `macro.cpp`
* vérifiez que le code compile et s'exécute
    * on doit obtenir 25
* remplacez la valeur 5 par `i++`
* que ce passe-t-il ?
* remplacez la macro par une fonction inline

## Atelier 'Smart pointers'
### unique_ptr
* avec le fichier `smart-pointers-tests.cpp`
* Utilisez un `std::unique_ptr` pour gérer une instance de `Person`
### shared_ptr
* Modifiez l'exercice précédent pour utiliser un `std::shared_ptr` à la place d'un `std::unique_ptr` 
* Partagez l'instance de `Person` entre deux `std::shared_ptr`
### weak_ptr
* Dans un nouveau fichier
    * Créez une classe `Node` pour représenter un noeud d'une liste chaînée circulaire
    * Utilisez `std::weak_ptr` pour éviter les cycles de références entre les nœuds

## Atelier 'chiffrement'
### Objectif
Utiliser la gestion de mémoire par OpenSSL
### Todo
* Si nécessaire installez OpenSSL
* Complétez le fichier `chiffrement/secure_string.cpp`
* Si nécessaire compilez avec la l'option de linkage
    * `g++ exemple.cpp -o exemple -lssl -lcrypto`
### Remarques
* La mémoire allouée par `OPENSSL_secure_malloc` est placée dans une zone non paginée : la mémoire ne sera pas déplacée sur le disque
* `OPENSSL_secure_free` efface la mémoire, les données sensible ne restent pas en mémoire après leur utilisation




