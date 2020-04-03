#!/usr/bin/env ruby

# Definition d'une map / hash map / table d'association ...
hash_ex = {alice: 10, bob: "frere", un: 1}

# Autre definition
hash_ex = {'alice' => 10, 'bob' => 'frere', 'un' => 1}

# Acces
hash_ex[:alice]
hash_ex[:un]

# Modification
hash_ex[:deux] = 2

# Affichage avec conversion en string
puts hash_ex.to_s

# Affichage du contenu
puts "#{hash_ex}"

