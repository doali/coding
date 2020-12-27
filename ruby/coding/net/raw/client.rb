#!/usr/bin/env ruby

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

# --------------------------------------------------------------------------------
# TO CHECK !! (impossible dans le conteneur gitpod... pas root)
# begin
#     rsock = Socket.open(Socket::PF_INET, Socket::SOCK_RAW, Socket::IPPROTO_RAW)
# rescue Errno::EPERM
#     $stderr.puts "Must run #{$0} as root."
#     exit!
# end

# begin
#     ssock = Socket.open(Socket::PF_INET, Socket::SOCK_RAW, Socket::IPPROTO_RAW)
#     unless ssock.getsockopt(Socket::SOL_IP, Socket::IP_HDRINCL)
#         puts "IP_HDRINCL is supposed to be the default for IPPROTO_RAW!"
#         puts "setting IP_HDRINCL anyway"
#         ssock.setsockopt(Socket::SOL_IP, Socket::IP_HDRINCL, true)
#     end
# rescue Errno::EPERM
#     $stderr.puts "Must run #{$0} as root."
#     exit!
# end

# Thread.new do
#     loop do
#         data, sender = rsock.recvfrom(8192)
#         port, host = Socket.unpack_sockaddr_in(sender)
#         out = "-" * 80, "packet received from #{host}:#{port}:", IP.new(data).inspect_detailed, "-" * 80
#         puts out
#         $stdout.flush
#     end
# end

# addr = Socket.pack_sockaddr_in(1024, "localhost")
# 3.times do |i|
#     ip = IP.new do |b|
#         # ip_v and ip_hl are set for us by IP class
#         b.ip_tos = 0
#         b.ip_id = i+1
#         b.ip_off = 0
#         b.ip_ttl = 64
#         b.ip_p = Socket::IPPROTO_RAW
#         b.ip_src = "127.0.0.1"
#         b.ip_dst = "127.0.0.1"
#         b.body = "just another IP hacker"
#         b.ip_len = b.length
#         b.ip_sum = 0 # linux will calculate this for us (QNX won’t?)
#     end

#     out = "-" * 80, "packet sent:", ip.inspect_detailed, "-" * 80
#     puts out
#     $stdout.flush
#     ssock.send(ip, 0, addr)
#     sleep 1
# end
# --------------------------------------------------------------------------------