#!/usr/bin/env ruby

lst_ville = [
  'Paris',
  'Annecy',
  'Stockholm',
  'Reykjavik',
  'LeCaire',
  'Istanbul',
  'Moscou'
]

puts 'Liste de villes à visiter'
lst_ville.each do |element|
  puts '-' + element
end

lst_voyage = [
  {ville:"Paris", duree:1},
  {ville:"Annecy", duree:2},
  {ville:"Stockholm", duree:4},
  {ville:"Reykjavik", duree:4},
  {ville:"LeCaire", duree:4},
  {ville:"Istanbul", duree:4},
  {ville:"Moscou", duree:4}
]

puts 
puts 'Recapitulation des voyages'
lst_voyage.each do |element|
  orth = (element[:duree] > 1) ? "s" : ""
  puts "Visite à " + element[:ville] + ", sejour de " + element[:duree].to_s + " jour" + orth
end


puts
puts 'Faisabilité des voyages'
lst_voyage.each do |element|
  orth = (element[:duree] > 1) ? "s" : ""
  if element[:duree] < 4
    puts "Visite à " + element[:ville] + ", sejour de #{element[:duree]} jour" + orth
  end
end
