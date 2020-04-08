#!/usr/bin/env ruby

# operateur .. => les bornes sont prises en compte => DEB .. FIN
range_deb_fin_inclus = (1 .. 10).to_a
print range_deb_fin_inclus

puts

# operateur ... => la borne de fin n'est pas prise en compte => DEB .. precedent(FIN)
range_deb_fin_exlue = (1 ... 10).to_a
puts "#{range_deb_fin_exlue}"
