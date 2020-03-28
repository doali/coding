#!/usr/bin/env python3
import socket

SOCKET_CONF = ('127.0.0.1', 8808)
BUFFER_SIZE = 1024

def run_server():
    # with permet de fermer correctement la socket (...equivallent d'un finally...)
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as sTCP:
        sTCP.bind(SOCKET_CONF) # liaison avec notre adresse locale et notre port de service
        sTCP.listen(1) # mise en écoute de nouvelles connexions

        # méthode bloquante sur une demande de connexion (d'un client)
        # - retourne :
        #   - une nouvelle socket representant la connexion
        #   - et l'adresse du connecte (host_addr, port)
        conn, addr = sTCP.accept() 
        print("Connexion acceptee: %s" % str(addr))

        # with permet de fermer correctement l'objet conn
        with conn:
            while True:
                data = conn.recv(BUFFER_SIZE) # réception des OCTETS
                if not data:
                    break
                conn.send(b"Coucou " + data.strip() + b".\n") # émission d'OCTETS

if __name__ == "__main__":
    run_server()
