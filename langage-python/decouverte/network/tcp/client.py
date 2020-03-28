#!/usr/bin/env python3
import socket

PARAMS = ('127.0.0.1', 8808)
BUFFER_SIZE = 1024

def run_client():
    # with permet de fermer correctement la socket (...equivallent d'un finally...)
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as sTCP:
        sTCP.connect(PARAMS) # demande de connexion à la socket server
        sTCP.send(b"TS\n") # émission d'OCTETS (avec un \n car le server-enhanced utilise readline)
        data = sTCP.recv(BUFFER_SIZE) # réception d'OCTETS

        print("\tDonnée récupérée du serveur : %s" % data.decode()) # conversion des OCTETS


if __name__ == "__main__":
    run_client()
