# Ruby et le debug

_Présentation des principaux outils pour débogguer en ruby_

## Sommaire
- `raise <method|object|...>`
- `pry`
- `byebug`
- `rdebug`

---

## `raise`

_L'idée et de lever une exception_
- permettre d'interrompre le programme au point souhaité
- permettre d'inspecter un \<object\> (rappel : tout est objet en Ruby)

### Exemple

```ruby
#!/usr/bin/env ruby
  
emails_rx = [
  "xav@lol.com",
  "yo@lol.com",
  "abeille@lol.com"
]

nb_rx_mails = emails_rx.size
orth = (nb_rx_mails > 1) ? "s" : ""

if nb_rx_mails > 0
  puts nb_rx_mails.to_s + " email" + orth + " from :" + emails_rx.to_s
end

emails_rx.each do |email|
  raise email.inspect # <======= astuce pour débogguer en levant une erreur et en inspectant
  if email =~ /^yo/
    puts ":-]"
  elsif email =~ /abeille/
    puts ":-)"
  else
    puts "°_o"
  end
    puts " '--> " + email
end
```

> Ajout de l'instruction (temporaire !!) `raise email.inspect`

## `pry`

- `gem install pry`

### Execution

_L'utilisation repose sur le module `pry` ainsi que l'instruction `binding.pry`_

_Il faut tout d'abord modifier le code source et y inclure le binding sur le module avec `binding.pry`_
_Cela marquera un point d'arrêt lors de l'exécution du programme._

```ruby
#!/usr/bin/env ruby

binding.pry

emails_rx = [
  "xav@lol.com",
  "yo@lol.com",
  "abeille@lol.com"
]

nb_rx_mails = emails_rx.size
orth = (nb_rx_mails > 1) ? "s" : ""

if nb_rx_mails > 0
  puts nb_rx_mails.to_s + " email" + orth + " from :" + emails_rx.to_s
end

emails_rx.each do |email|
  if email =~ /^yo/
    puts ":-]"
  elsif email =~ /abeille/
    puts ":-)"
  else
    puts "°_o"
  end
    puts " '--> " + email
end
```

_Il faut ensuite charger le module soit en ligne de commande_

```bash
ruby -rpry condition-list.rb
```

_soit en ajoutant l'instruction `require 'pry'` dans le fichier source_

```ruby
#!/usr/bin/env ruby

require 'pry'
binding.pry

emails_rx = [
  "xav@lol.com",
  "yo@lol.com",
  "abeille@lol.com"
]

nb_rx_mails = emails_rx.size
orth = (nb_rx_mails > 1) ? "s" : ""

if nb_rx_mails > 0
  puts nb_rx_mails.to_s + " email" + orth + " from :" + emails_rx.to_s
end

emails_rx.each do |email|
  if email =~ /^yo/
    puts ":-]"
  elsif email =~ /abeille/
    puts ":-)"
  else
    puts "°_o"
  end
    puts " '--> " + email
end
```

_et en lançant simplement la commande_

```bash
ruby condition-list.rb
```

Il est également possible de lancer directement `pry`

```bash
pry condition-list.rb
```

### Exemple

## `byebug`

### Installation

- `gem install byebug`

### Exécution

```bash
byebug condition-list.rb 
```

### Exemple

```bash
gitpod /workspace/coding/ruby/coding/control $ byebug condition-list.rb 

[1, 10] in /workspace/coding/ruby/coding/control/condition-list.rb
    1: #!/usr/bin/env ruby
    2: 
=>  3: require 'pry'
    4: binding.pry
    5: 
    6: emails_rx = [
    7:   "xav@lol.com",
    8:   "yo@lol.com",
    9:   "abeille@lol.com"
   10: ]
(byebug) 
```

> ATTENTION, on peut remarquer l'instruction `binding.pry` qui jumpera dedans !!
> Mettre alors en commentaire cette ligne 4 (et par cohérence la ligne 3)
> Sinon, il est toujours possible de l'exécuter... ce qui fait sauter dans `pry`, que l'on peut
> quitter via la commande `quit` et revenir à `byebug`

## `rdebug`

_Très proche dans son utilisation à pdb (python), gdb (C, C++)_

### Installation

- `gem install rdebug`

### Execution

_Execution en mode debug dans une console_

- `ruby -rdebug <executable>.rb`

### Exemple

```ruby
gitpod /workspace/coding/ruby/coding/control $ ruby -rdebug condition-list.rb 
/home/gitpod/.rvm/rubies/ruby-2.6.6/lib/ruby/2.6.0/x86_64-linux/continuation.so: warning
: callcc is obsolete; use Fiber instead
Debug.rb
Emacs support available.

condition-list.rb:4:  "xav@lol.com",
(rdb:1) where
--> #1 condition-list.rb:4
(rdb:1) list
[-1, 8] in condition-list.rb
   1  #!
   2  
   3  emails_rx = [
=> 4    "xav@lol.com",
   5    "yo@lol.com",
   6    "abeille@lol.com"
   7  ]
   8  
(rdb:1) exit
gitpod /workspace/coding/ruby/coding/control $
```

## Biblio
- [rubyguides](https://www.rubyguides.com/2015/07/ruby-debugging/)
- [pry](https://pry.github.io/)
- [byebug](https://github.com/deivid-rodriguez/byebug)
- [rdebug](https://stackoverflow.com/questions/3955688/how-to-debug-ruby-scripts)
- [youtube Jim Weirich](https://www.youtube.com/watch?v=GwgF8GcynV0)