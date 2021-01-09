#!/usr/bin/env ruby

require 'socket'

mysocket = TCPSocket.new('127.0.0.1', 6666)

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
                end
            end
        end

    end
    puts "DEBUG : loop >>"
end
