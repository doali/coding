# Securité en c++

Pile mémoire, on lit du bas vers le haut.

==================
stack
------------------
heap
==================
bss:variables non initialisées
------------------
data:variables initialisées
==================
text:le code
==================

[slide 36]
`std::allocator` : allocation statique (c++ moderne)

[slide 39]
compilateur -> linker -> startup code (initialisation des variables à zéro etc...)

[slide 41]
`constexpr` : indique que la variable est connue à la compilation
`std::vector` : son contenu est sur le tas !!

[slide 43, 44]
RAII : Resource Acquisition Is Initialization

[slide 49]
**ESP** : stack pointer
**EBP** : base pointer

[slide 53]
La librarie **alloca** (non standardisée) serait un peu commme les smartpointers pour libérer automatiquement la mémoire en c.

```c
{
int * ptr = alloca(size * sizeof(int));
} // <= ici, la libération sera automatique grace à l'allocation d'alloca car on sort de la portée.
```

[slide 55]
Traitement des erreurs 

**Préconisations**
- dans un même process, plutôt renvoyer un code retour, (aspect déterministe)
- dans l'autre cas, si plusieurs process (threads), plutôt utiliser les exception. (aspect non déterministe, runtime)

[slide 59]
**Unique pointer**
- pas de copie
- unique propriétaire
- on peut uniquement le transférer via le déplacement `std::move` 

```c++
std::unique_ptr<X> pX 
// Qui dit template, dit connu à la compilation !
```

**Shared pointer**
- dispose d'un compteur
- incrémentation du compteur dès qu'il est partagé
- destruction si le compteur est à zéro

La valeur du compteur est visualisable par `use_count()`

Remarque `enable_shared_ptr` : renvoyer un pointeur
> Met à jour le compteur de référence !!
> Sert uniquement dans ce cas là
> Autrement, on aurait eu un problème de comptage des références.

**Weak pointer**
- construit à partir d'un shared pointer

> Sert uniquement à une chose, briser les cycles.
> Car autrement, on aurait des fuites mémoires.
> Du coup, on utilise le weak pointer pour indiquer : "ne regarde pas ton compteur !! (Appelle ton destructeur)"

[slide 69]
Concurrence

- `std::atomic` : Synchronize une mémoire entre différents threads pour une valeur triviale : int, bool,  etc.. mais pas pour les classes !!
- `std::mutex` : Si les valeurs ne sont pas triviales : les classes ! (attention deadlock possible !!)
- `std::lock_guard` : Utilise les mutex mais garantit la libération via RAII du unlock !!

- `std::promise`: Communication entre **deux** threads de façon non bloquante
- `std::future`

- `std::condition_variable` : Synchronize plusieurs threads (si plus de 2 par exemples)
- `shared_mutex` : Pour partager les données 

- `std::thread` : Plutôt à utiliser dans le cadre bas niveau (si les threads ont **des priorités différentes**)
- `std::async` : Utilise en interne directement std::promise et std::future et les threads ont tous les même priorités.

[slide 73]
- mot clef est à utiliser dans le header 
- dépassé en c++ moderne (car les compilateurs sont suffisamment intelligents)

[slide 76]
- dynamic_cast<>, dynamic_pointer_cast<> : au runtime
- static_cast<>, static_pointer_cast<> : à la compilation (simple copie => on peut pointer sur un mauvaise attribut)
- const_cast<> : retirer un const
- reinterpret_cast<> : compilation

[slide 78]
enum MonEnum : à la c et donc avec une portée globale !
enum class MonEnum : à utiliser car mieux pour la portée

## En résumé

- Valider les entrants
- Tenir compte de tous les warnings
- Reduire au maximum les privilèges
- Conception et politique de développement sécurisée dès le départ

car le c++ 
- permet un accès direct à la mémoire
- peut entraîner un dépassement de buffer
- permet de manipuler des objets du fait d'une mauvaise utilisation des cast
- permet un dépassement d'entier si le type est mal choisi
- permet de gérer manuellement la mémoire et implique la libération de la mémoire allouée
- entraine un comportement indéfini dans cas de la double libération

== PAUSE DEJ ==
