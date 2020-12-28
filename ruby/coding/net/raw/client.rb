#!/usr/bin/env ruby

# --------------------------------------------------------------------------------
# A explorer !!
# https://github.com/todb/packetfu
# --------------------------------------------------------------------------------
# Autre chose aussi
# gem install racket
# --------------------------------------------------------------------------------
# Pour comprendre
# https://medium.com/geckoboard-under-the-hood/how-to-build-a-network-stack-in-ruby-f73aeb1b661b
# https://github.com/geckoboard/RUDP/blob/master/server.rb
# --------------------------------------------------------------------------------
# Utile
# https://gist.github.com/k-sone/8036832
# --------------------------------------------------------------------------------
# select en ruby
# https://ruby-doc.org/core-2.5.0/IO.html

require 'socket'

# --------------------------------------------------------------------------------
# TO CHECK !! (impossible dans le conteneur gitpod... pas root)
# interface = 'lo'         # loopback interface
# interface_index = 0x8933 # SIOCGIFINDEX
# geonet_frame = "\x00\x1f\xc6\x51\x07\x07\x07\x07\x07\x07\x07\x07\x07\x07\xc6\x51\x07\x07\x07\x07\x07\x07\xef\x06\x07\x35\x97\x00\x24\x8c\x7a\xdf\x6f\x08\x00\x45\x00\x00\x3d\xf3\x7f\x40\x00\x40\x11\x30\xc6\x0a\x01\x01\x68\x0a\x01\x01\x01\x99\x80\x00\x35\x00\x29\x16\xa5\x01\x76\x01\x00\x00\xff\x00\x00\x01\x00\x00\x00"

# socket = Socket.new(Socket::AF_PACKET, Socket::SOCK_RAW, Socket::IPPROTO_RAW)
# ifreq = [interface.dup].pack('a32')
# socket.ioctl(interface_index, ifreq)
# socket.bind([Socket::AF_PACKET].pack('s') + [Socket::IPPROTO_RAW].pack('n') + ifreq[16..20] + ("\x00" * 12))

# socket.send(geonet_frame, 0)
# --------------------------------------------------------------------------------
