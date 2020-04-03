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
  if email == "yo@lol.com"
    puts ":-]"
  elsif email == "abeille@lol.com"
    puts ":-)"
  else
    puts "°_o"
  end
    puts " '--> " + email
end

