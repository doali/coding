# Data alignment

```
Alignement mémoire
- la mémoire (RAM) est organisée à l'octet (plus petite quantité adressable)
- la taille d'un mot (mémoire) est donc de 8 bits,
- la mémoire est adressée via un pointeur de 8 octets (si architecute 64 bits)
  pouvant adresser des zones de 1 octet. (soit 2^64 adresses possibles)
- la largeur des registres est de 64 bits (pour les nombres entiers)
- le bus d'adressage est de 64 bits
- le bus de données est de 64 bits
- le processeur peut envoyer 64 bits, 8 octets en mémoire simultanément
- la taille d'un mot (processeur : word size) est de 64 bits
- le processeur peut traiter un mot de 64 bits simultanément

Dans une structure
- membres rangés de façon contigüe en mémoire

Il faut éviter de positionner des membres
à cheval sur deux emplacements mémoire !!

- sinon, un accés supplémentaire en mémoire sera réalisé
- par ailleurs, le compilateur ajoute des paddings pour aligner
  les variables.
  - ce qui augmente l'espace occupé en mémoire par
    la structure et qui pourrait-être évité.
```

## Biblio

- [geeksforgeeks](https://www.geeksforgeeks.org/data-structure-alignment/)
- [makeholik](http://makerholik.com/embedded-system/data-structure-alignment/)
- [getconf](https://unix.stackexchange.com/questions/18024/how-to-get-information-about-word-address-size-address-bus-size-data-bus-size)
- [wikibooks](https://fr.wikibooks.org/wiki/Fonctionnement_d%27un_ordinateur/Le_mod%C3%A8le_m%C3%A9moire_:_alignement_et_boutisme)
- [zestede savoir](https://zestedesavoir.com/tutoriels/755/le-langage-c-1/1043_aggregats-memoire-et-fichiers/4279_structures/#5-12830_un-peu-de-memoire)
- [wikipedia](https://fr.wikipedia.org/wiki/Alignement_en_m%C3%A9moire)
