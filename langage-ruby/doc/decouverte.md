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

- Hash _(Map, tableau associatif, table de hashage...)_
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
- itérer sur une liste : `<ma_liste>.each do |elmt_de_liste| ... end`
```ruby
# liste
list_user = ['u_1', 'u_2', 'u_3', 'u_4', 'u_5']

# iteration sur la liste
list_user.each do |element|
  puts element
end
```
```ruby
# hash
p_1 = {nom:'n_1', prenom: 'p_1'}
p_2 = {nom:'n_2', prenom: 'p_2'}
p_3 = {nom:'n_3', prenom: 'p_3'}
p_4 = {nom:'n_4', prenom: 'p_4'}
p_5 = {nom:'n_5', prenom: 'p_5'}

annuaire = [p_1, p_2, p_3, p_4, p_5]

# iteration sur liste contenant des hash
annuaire.each do |pers|
  puts pers[:nom] + " --> " + pers[:prenom]
end
```
- itérer sur des valeurs entières
```ruby
# iteration
5.times do |i| 
  puts i
end
```

## Affichage
```ruby
irb(main):027:0> l
=> [1, 2, 3, 4, 5, 6]
irb(main):028:0> puts l
1
2
3
4
5
6
=> nil
irb(main):029:0> 
```
Pour afficher le contenu d'une liste et d'une chaine de caractères on peut procéder des façons suivantes
### Accéder au contenu : `#{...}`
- `#{<nom_variable>}` : accède au contenu de <nom_variable>
```ruby
irb(main):031:0> puts "Liste : #{l}"
Liste : [1, 2, 3, 4, 5, 6]
=> nil
irb(main):032:0> 
```
### Concatener : `+` _(et récupérer la string d'un objet avec `<...>.to_s`)_
- `<nom_variable>.to_s` : renvoie la chaine de caractères décrivant <nom_nom_variable>
```ruby
irb(main):034:0> puts "Liste : " + l.to_s
Liste : [1, 2, 3, 4, 5, 6]
=> nil
irb(main):035:0> 
```

## Structures de contrôle


## Biblio
- [premiers pas](https://openclassrooms.com/fr/courses/2913686-lancez-vous-dans-la-programmation-avec-ruby/2915056-installez-vos-outils)