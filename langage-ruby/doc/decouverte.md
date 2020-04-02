# Ruby
_Langage de programmation où tout est ***objet***._

*Prérequis*
- `sudo apt install ruby-full`

---

## Mode interactif
Ruby dispose à l'instar de Python, OCaml, ... d'un mode interactif auquel on accède depuis un terminal en tapant `irb` (Interactive Ruby)

## Structures de données
### Tableaux, Hash
- Tableaux
```ruby
irb(main):045:0> tab = ["a", 1, 2, "d"]
=> ["a", 1, 2, "d"]
irb(main):046:0> tab[0] = 'A'
=> "A"
irb(main):047:0> tab
=> ["A", 1, 2, "d"]
irb(main):048:0> tab[-1] = "D"
=> "D"
irb(main):049:0> tab
=> ["A", 1, 2, "D"]
irb(main):050:0> tab << "E"
=> ["A", 1, 2, "D", "E"]
irb(main):051:0> tab.append('F')
=> ["A", 1, 2, "D", "E", "F"]
irb(main):052:0> tab.reverse
=> ["F", "E", "D", 2, 1, "A"]
irb(main):053:0> 
```

- Hash
```ruby
irb(main):055:0> hash_ex = {alice: 10, bob: "frere", un: 1}
=> {:alice=>10, :bob=>"frere", :un=>1}
irb(main):056:0> hash_ex[:alice]
=> 10
irb(main):057:0> hash_ex[:un]
=> 1
irb(main):058:0> hash_ex[:deux] = 2
=> 2
irb(main):059:0> hash_ex
=> {:alice=>10, :bob=>"frere", :un=>1, :deux=>2}
irb(main):060:0> 
```

## Itérations


## Biblio
- [premiers pas](https://openclassrooms.com/fr/courses/2913686-lancez-vous-dans-la-programmation-avec-ruby/2915056-installez-vos-outils)