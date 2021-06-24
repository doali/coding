#!/usr/bin/bash

## HTTP example ---
# HTTP Server
gcc -o mini_http_server mini_http_server.c mongoose.c

# HTTP Client
#curl -X GET http://localhost:8000

## TCP example ---
# TCP Server (@IP:localhost, port:1234)
gcc -o mini_tcp_server mini_tcp_server.c mongoose.c
#./mini_tcp_server

# TCP Client
gcc -o client_tcp client_tcp.c
#./client_tcp

# mongoose ---
#https://cesanta.com/docs/#introduction
#https://github.com/cesanta/mongoose/blob/master/mongoose.h
#https://github.com/cesanta/mongoose/blob/master/mongoose.c

# client TCP ---
#https://www.geeksforgeeks.org/tcp-server-client-implementation-in-c/
