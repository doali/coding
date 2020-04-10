#!/usr/bin/env python3
import socket

PARAMS = ('127.0.0.1', 8809)
BUFFER_SIZE = 1024

def run_client():
    # with permet de fermer correctement la socket (...equivallent d'un finally...)
    with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as sUDP:
        # pas de notion de connexion, on envoie directement 
        sUDP.sendto(b'client', PARAMS) # on indique le destinaire !!
        data, _ = sUDP.recvfrom(BUFFER_SIZE) # réception d'OCTETS 
        print("Réponse du serveur : %s" % data.decode())


if __name__ == "__main__":
    run_client()