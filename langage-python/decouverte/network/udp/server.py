#!/usr/bin/env python3
import socket

PARAMS = ('127.0.0.1', 8809)
BUFFER_SIZE = 1024

def run_server():
    # with permet de fermer correctement la socket (...equivallent d'un finally...)
    with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as sUDP:
        sUDP.bind(PARAMS) # liaison avec notre adresse locale et notre port de service

        # Plus de notion de connexion => on lit directement ce que l'on reçoit (pas de listen ni de accept)
        while True:
            data, addr = sUDP.recvfrom(BUFFER_SIZE) # réception d'OCTETS

            if not data:
                break

            print("Message de :", data.decode(), " contenant :", addr)
            sUDP.sendto(b'Serveur -> ' + data, addr) # émission d'OCTETS on précise le destinataire !!


if __name__ == "__main__":
    run_server()