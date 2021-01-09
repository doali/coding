#!/usr/bin/env ruby

require 'socket'

mysocket = UDPSocket.new
#mysocket.bind('192.168.1.87', 6666)
mysocket.bind('192.168.1.87', 6666)

th = Thread.new do
    while true
        puts "DEBUG : loop <<"
        ready = IO.select([mysocket])
        readable = ready[0]

        readable.each do |socket|
            if socket == mysocket
                buf = mysocket.recv_nonblock(1024)
                if buf.length == 0
                    puts "The server connection is dead. Exiting."
                    exit
                else
                    puts "Received a message"
                    puts "#{buf.unpack("C*")}"
                    puts "#{buf}"
                end
            end
        end

    end
    puts "DEBUG : loop >>"
end

status = th.status
puts "status #{status}"

cpt = 0
Thread.new {
  loop do
    sleep 1
    cpt += 1
    puts cpt
  end
}


sleep(120)

# Liens utiles
# --------------------------------------------------------------------------------
# https://dzone.com/articles/tcpdump-learning-how-read-udp
# https://dzone.com/articles/tcpdump-learning-how-read-udp
# https://help.ubidots.com/en/articles/937233-sending-tcp-udp-packets-using-netcat
# https://leejava.wordpress.com/2009/08/24/udp-client-and-server-in-ruby/
# https://stackoverflow.com/questions/6165735/understanding-io-select-when-reading-socket-in-ruby
