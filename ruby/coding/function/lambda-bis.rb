#!/usr/bin/env ruby

# Génération d'une liste de n éléments
# - commence à zéro
def gen_lst n
  return [] if n == 0
  return (gen_lst n - 1) << (n - 1)
end

f = -> (a) { -> (b) { a + b } } # lambda
f_10 = f.call 10 # currification et capture de 10
puts (f_10.call 4)

l = gen_lst 4 # génération d'une liste [0, 1, 2, 3]

# Utilisation de each
l.each { |e| puts f_10.call e }

# Utilisation de map
res = l.map { |e| f_10. call e }
puts res

# Déclaration / défintion / capture
c_10 = (-> (a) { -> (b) { a + b } }).call 10
puts c_10.call 4
