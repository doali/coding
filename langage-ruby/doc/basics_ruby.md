# Ruby
_Langage de programmation ***interprété*** où tout est ***objet***._

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

### Survol des types
```ruby
irb(main):001:0> class MaClass
irb(main):002:1> end
=> nil
irb(main):003:0> inst_MaClass = MaClass.new
=> #<MaClass:0x0000561d7b081d00>
irb(main):004:0> l_type = [1, 1.0, 'c', "chaine", [1, 2, 'k'], {clef: 'valeur', :autre_clef => 10}, MaClass, inst_MaClass]
=> [1, 1.0, "c", "chaine", [1, 2, "k"], {:clef=>"valeur", :autre_clef=>10}, MaClass, #<MaClass:0x0000561d7b081d00>]
irb(main):005:0> l_type.each do |element|
irb(main):006:1* puts element.to_s + " <- " + element.class.to_s
irb(main):007:1> end
1 <- Integer
1.0 <- Float
c <- String
chaine <- String
[1, 2, "k"] <- Array
{:clef=>"valeur", :autre_clef=>10} <- Hash
MaClass <- Class
#<MaClass:0x0000561d7b081d00> <- MaClass
=> [1, 1.0, "c", "chaine", [1, 2, "k"], {:clef=>"valeur", :autre_clef=>10}, MaClass, #<MaClass:0x0000561d7b081d00>]
irb(main):008:0> 
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
### Classes
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
#### Attributs
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
#### Méthodes
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
#### Initialisation : _constructeur_
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
#### Héritage
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
### Composition
- `attr_attr_accessor :<nom_composant>` : `<nom_composant>` est une reference vers l'objet pour lequel on définit une relation de composition
```ruby
class Panier
  attr_accessor :_legumes # composition

  def initialize
    @_legumes = []
  end 

  def ajouter(legume)
    _legumes << legume
  end 

  def to_s
    description = "Panier :" + ((_legumes.size == 0) ? "vide" : "") 
    _legumes.each do |legume|
      description += "\n"
      description += ("- " + legume.to_s)
    end 
    return description
  end 
end


class Legume
  attr_accessor :_nom
  attr_accessor :_famille

  def initialize(nom, famille)
    @_nom = nom 
    @_famille = famille
  end 

  def to_s
    return "Legume :{" + _nom + ":" + _famille + "}" 
  end 
end


# --------------------------------------------------
legume_tomate = Legume.new("tomate", "fruit")
legume_patate = Legume.new("patate", "racine")
puts legume_tomate
puts legume_patate

puts
panier = Panier.new # methodes d'instance + composition
puts panier

panier.ajouter(legume_tomate)
panier.ajouter(legume_patate)
puts panier
```
qui produit le résultat suivant
```bash
Legume :{tomate:fruit}
Legume :{patate:racine}

Panier :vide
Panier :
- Legume :{tomate:fruit}
- Legume :{patate:racine}
```



## Arguments variables
- `*args` : quantite variable d'arguments transmis à l'appelé (sous forme d'une liste)
- `**kwargs` : quantite variable d'arguments présentés comme une succession de hash map
```ruby
# Arguments variables
# *args : quantite variable d'arguments transmis à l'appele (sous forme d'une liste)
# **kwargs : quantite variable d'arguments transmis à l'appelé (sous forme d'une hash-map)
# Ordre à respecter
# required -> optional -> variable -> keyword -> keyword_variable
# arg : définit un argument classique (mon_argument, {ma_clef:ma_valeur}, ...)
# kwarg : définit un keyword argument (ma_clef:ma_valeur, autre_clef: {key: val}, ...)

# --------------------------------------------------
def ex_l(*args)
  puts "#{args}" # puts args.to_s # puts *args.to_s
  puts args # puts *args
end

ex_l('a', 'b', 'c', 1, 2, 3)
puts "------------------------------"

# --------------------------------------------------
def ex_hash(**kwargs)
  puts "#{kwargs}" # puts kwargs # puts **kwargs # puts kwargs.to_s # puts *kwargs.to_s
  puts *kwargs
end

ex_hash(clef_a:'a', clef_b:'b', lettre:'c', un:1, deux:2)
puts "------------------------------"

# --------------------------------------------------
def testing(a, b = 1, *c, d: 1, **x)
  puts a
  puts b
  puts c # liste
  puts d
  puts x # hash map
end

testing({un:1, deux:2}, 'a', 'b', 'c', 'd', 'e', d: 2, x: 1, lol:{mon_hash:{hein:1, deux:2}})
puts "------------------------------"
```
qui produit le résultat suivant
```bash
["a", "b", "c", 1, 2, 3]
a
b
c
1
2
3
------------------------------
{:clef_a=>"a", :clef_b=>"b", :lettre=>"c", :un=>1, :deux=>2}
clef_a
a
clef_b
b
lettre
c
un
1
deux
2
------------------------------
{:un=>1, :deux=>2}
a
b
c
d
e
2
{:x=>1, :lol=>{:mon_hash=>{:hein=>1, :deux=>2}}}
------------------------------
```

## Astuces
### Afficher sur une ligne
```ruby
# Afficher sans passer à la ligne
# str : une chaine de caractères
# * : prend en compte tous les arguments suivant <str> de l'appelant
def print_and_flush(*liste_des_arguments)
  print *liste_des_arguments
  $stdout.flush
end
```
```ruby
# ---------------------------------------------------------------------
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

print_and_flush("mot_1" + " " + "mot_2")
saut_de_ligne

print_and_flush("mot_1", "mot_2", "mot_3")
saut_de_ligne

print_and_flush("mot_1")
saut_de_ligne

print_and_flush()
saut_de_ligne

```
produit le résultat suivant
```bash
mot_1 # saut_de_ligne
mot_1mot_2 # saut_de_ligne
mot_1 mot_2 # saut_de_ligne
mot_1 mot_2 # saut_de_ligne
mot_1 mot_2 # saut_de_ligne
mot_1mot_2mot_3 # saut_de_ligne
mot_1 # saut_de_ligne
 # saut_de_ligne
```

## Conventions de nommage
|Local|	Global|	Instance|	Class|	Class|Names|
|-----|	------|	--------|	-----|	-----|-----|
|name|	$debug|	@name|	@@total|	PI|
|fishAndChips|	$CUSTOMER|	@point_1|	@@symtab|	FeetPerMile|
|x_axis|	$_|	@X|	@@N|	String|
|thx1138|	$plan9|	@_|	@@x_pos|	MyClass|
|_26|	$Global|	@plan9|	@@SINGLE|	Jazz_Song|

## Biblio
- [premiers pas](https://openclassrooms.com/fr/courses/2913686-lancez-vous-dans-la-programmation-avec-ruby/2915056-installez-vos-outils)
- [problem gem](https://github.com/rubygems/rubygems/issues/3068)
- [guide ruby](https://www.rubyguides.com/2018/09/ruby-super-keyword/)
- [ruby doc](https://ruby-doc.com/docs/ProgrammingRuby/html/intro.html)