# Expressions régulières
_Expression symbolique permettant de rechercher des motifs_

<- [home](../README.md)

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

## Quantificateurs
|Quantificateur|Description|
|--------------|-----------|
|+|au moins une fois|
|*|aucune ou plusieurs fois (zéro ou plus)|
|?|au plus une fois|

## Positionnement
|Positionnement|Description|
|--------------|-----------|
|^|début du mot|
|$|fin du mot|

---

# Python
## Expressions
|Expression|Description|
|----------|-----------|
|\d|un chiffre|
|\w|un chiffre ou bien une lettre ou bien un _|
|\s|un (espace, tabulation, ...) _dépend de l'OS_|
|\D|tout sauf un chiffre|
|\W|tout sauf : un chiffre ou bien une lettre ou bien un _|
|\S|tout sauf un (espace, tabulation, ...)|
|\w+|un ou plusieurs caractères alphanumériques|
|\s*|aucun ou plusieurs espaces|
|\d?|au plus un chiffre|
|[ACGT]|A ou bien C ou bien G ou bien T|
|[^ACGT]|tout sauf : un A ou bien un C ou bine un G ou bien un T|
|{2,4}|répétition entre 2 et 4 fois|
|{14}|exactement 14 fois|
|{15,}|au moins 15 fois|
|{,47}|au plus 47 fois|
|([a-z]\d)?|au plus une fois : une lettre minuscule de l'alphabet ou bien un chiffre|

### Module `re`
Pour utiliser les expressions régulières : importer le module re : `import re`

## Important
_Pour s'assurer que python n'interprête par les caractères spéciaux, il faut indiquer que l'on définit une chaine au format brut (raw)_

```python
un_regex = re.compile(r"[ACGT]+")
```

## Groupe
_Un groupe est défini par des `()`_

Les parenthèses peuvent jouer deux rôles, celui de grouper des symboles
`(g)@(G)` expression qui définit des groupes.
- Les groupes sont numérotés en commençant à partir de `0` par ordre d'apparence :
  - g est donc du groupe 0,
  - G du goupe 1
 - Deux groupes ont été définis contenant respectivement les caractères g et G
 - On peut donc avec une seule regex définir plusieurs groupes

### Exemple
#### Un seul groupe
```python
element_adn = re.compile(r"[ACGT]+")
phrase = "On peut trouver dans un brin les acides suivants ATGC. Mais aussi TTG par exemple."
print element_adn.search(phrase).group(0)
```
> ATGC

_Tous les mots qui correspondent à l'expression régulière `r"[ACGT]+"` dans la `phrase` peuvent-être trouvés et placés au moyen de `[...].findall(<phrase>)` dans une liste comme suit :_

```python
element_adn = re.compile(r"[ACGT]+")
phrase = "On peut trouver dans un brin les acides suivants ATGC. Mais aussi TTG par exemple."
liste_motif = element_adn.findall(phrase)
print liste_motif
```
> ['ATGC', 'TTG']

#### Trois groupes
```python
element_adn_bis = re.compile(r"([ACGT]+)(G)(C)")
phrase = "On peut trouver dans un brin les acides suivants ATGC. Mais aussi TTG par exemple."
print element_adn_bis.search(phrase).group(0)
print element_adn_bis.search(phrase).group(1)
print element_adn_bis.search(phrase).group(2)
print element_adn_bis.search(phrase).group(3)
```
> ATGC
>
> AT
>
> G
>
> C

_On s'est arrêté ici au premier motif qui correspondait à notre expression régulière. Utilisons alors `[...].findall(<src_de_la_recherche>)` pour trouver tous les motifs acceptés._

```python
element_adn_bis = re.compile(r"([ACGT]+)(G)(C)")
phrase = "On peut trouver dans un brin les acides suivants ATGC. Mais aussi TTG par exemple."
liste_motif = element_adn_bis.findall(phrase)
print liste_motif
```
> [('AT', 'G', 'C')]

***Remarque***
- la méthode `join` permet de joindre les composantes d'un tuple.
```python
t = ('a', 'bc', 'd')
fusion = ''.join(t)
print fusion
```
> abcd
