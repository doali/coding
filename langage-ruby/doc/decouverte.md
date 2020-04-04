# Ruby
_Langage de programmation où tout est ***objet***._

*Prérequis*
- `sudo apt install ruby-full`

_Exécuter également la commande suivante suite à des problèmes rencontrés sur `18.04.4`_
```bash
sudo gem update --system 3.0.6
```
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
- `<nom_variable>.to_s` : renvoie la chaine de caractères décrivant <nom_variable>
```ruby
irb(main):034:0> puts "Liste : " + l.to_s
Liste : [1, 2, 3, 4, 5, 6]
=> nil
irb(main):035:0> 
```

## Structures de contrôle
- `if [...] elsif [...] else [...] end`
```ruby
val = 15
a = 12

puts "a <- #{a}"

if a == 15
  puts "a est égal à #{val}"
elsif a < 15
  puts "a est inferieur à #{val}"
else 
  puts "a est supérieur à #{val}"
end
```

## POO _(Programmation Orientée Objet)_
_En ***Ruby*** ***tout est objet*** même ce qui d'ordinaire est un _type primitif_ par exemple un entier `10` dans d'autres langages._
- `<objet>.class` : renvoie le type de l'objet
```ruby
irb(main):015:0> "une string".class
=> String
irb(main):016:0> 10.class
=> Integer
irb(main):017:0> 1.0.class
=> Float
irb(main):018:0> [1, 0, "coucou", 3.14, 'L'].class
=> Array
irb(main):019:0> {clef:'valeur', mois_str:'avril', mois_num:4}.class
=> Hash
irb(main):020:0> 
```

- `class <MaClasse> [...] end` : déclaration et définition d'une classe
- `mon_instance = <MaClasse>.new` : instanciation de la classe
```ruby
irb(main):020:0> class MaClasse
irb(main):021:1> end
=> nil
irb(main):022:0> mon_instance = MaClasse.new
=> #<MaClasse:0x000055ef3bab8f08>
irb(main):023:0> mon_instance.class
=> MaClasse
irb(main):024:0> 
```
- `attr_accessor :<nom_attribut>` : attention `:<nom_attribut>` forme un seul mot !! (pas d'espace entre `:` et `<nom_attribut>`)
```ruby
# Définition d'une classe
class Utilisateur
  attr_accessor :prenom
  attr_accessor :nom
  attr_accessor :oeuvres
end

# Utilisation
ym = Utilisateur.new
ym.prenom ='Yukihiro'
ym.nom ='Matsumoto'
ym.oeuvres = ['ruby']

puts ym.prenom + " " + ym.nom + ", créateur de : " + ym.oeuvres.to_s
```

- `def <nom_methode>[(arg, ...)] [...] end` : declaration et définition d'une methode
- `<nom_instance>.<nom_methode>[(arg, ...)]` : pour l'appel de ladite methode
```ruby
class MaClass
  attr_accessor :attr_1
  attr_accessor :attr_2

  def ma_methode(arg)
    # instructions...
    puts arg.class
  end 
end

# Instanciation
instance_1 = MaClass.new

# Acces attributs
instance_1.attr_1 = "premier attribut"
instance_1.attr_2 = 2 

# Appel methode
instance_1.ma_methode(instance_1.attr_1)

# Informations
puts instance_1.class
puts instance_1.attr_1.class
```
- `def initialize[(arg1, arg2=<valeur_par_defaut>, ...)]` : initialisation des attributs de la classe
  - appelée dès lors qu'on invoque `<MaClasse>.new[(arg1, arg2, ...)]`
```ruby
class MiniFB
  # === attributs
  attr_accessor :prenom
  attr_accessor :amis

  # === initialisation
  def initialize(prenom, amis=[])
    self.prenom = prenom
    @amis = amis
  end 
# ...
end

# Creation des personnes
linus = MiniFB.new("Linus")
ken = MiniFB.new("Ken")
brian = MiniFB.new("Brian")
larry = MiniFB.new("Larry", [ken, linus, brian])
bill = MiniFB.new("Bill")
```
- `class <ClassFils> < <ClassPere> [...] end` : définie une relation d'héritage où `<ClassFils>` dérive de `<ClassPere>`
- redéfinition d'une méthode de sa classe parente en reprenant la signature de celle-ci dans ses classes filles
- `super` : appel une methode dans la classe parente de meme nom que celle contenant l'appel super
  ```ruby
  def methode_ex
    super
  end
  ```
  > `super` invoquée dans `methode_ex` appellera la methode de même nom `methode_ex` de la classe parente
  - `super()` : pour appeler la méthode parente sans argument
  - `super(arg1, arg2, ...)` : pour appeler la méthode parente avec des arguments
  - on peut récupérer la valeur de retour de `super`
```ruby
class ClassParent
  attr_accessor :nom

  def initialize(nom)
    @nom = nom
  end

  def description
    puts "Je suis le père"
    return nom + ":" + "#{self.class}"
  end
end

class ClassFils < ClassParent
  def description
    info = super
    puts "le fils"
    return info
  end
end

a = ClassParent.new("A")
puts a.description

b = ClassFils.new("B")
puts b.description
```
```bash
Je suis le père
A:ClassParent
Je suis le père
le fils
B:ClassFils
```

## Astuces
### Afficher sur une ligne
```ruby
# Afficher sans passer à la ligne
# str : une chaine de caractères
# * : prend en compte tous les arguments suivant <str> de l'appelant
def print_and_flush(str = "", *)
  print str 
  $stdout.flush
end
```
```ruby
# Exemples
def saut_de_ligne
  puts " # saut_de_ligne"
end

print_and_flush

print_and_flush "mot_1"
saut_de_ligne

print_and_flush "mot_1" "mot_2"
saut_de_ligne


print_and_flush "mot_1"  " " "mot_2"
saut_de_ligne

print_and_flush "mot_1" + " " + "mot_2"
saut_de_ligne

print_and_flush ("mot_1" + " " + "mot_2")
saut_de_ligne
```
produit le résultat suivant
```bash
mot_1 # saut_de_ligne
mot_1mot_2 # saut_de_ligne
mot_1 mot_2 # saut_de_ligne
mot_1 mot_2 # saut_de_ligne
mot_1 mot_2 # saut_de_ligne
```

## Biblio
- [premiers pas](https://openclassrooms.com/fr/courses/2913686-lancez-vous-dans-la-programmation-avec-ruby/2915056-installez-vos-outils)
- [problem gem](https://github.com/rubygems/rubygems/issues/3068)
- [guide ruby](https://www.rubyguides.com/2018/09/ruby-super-keyword/)