#!/usr/bin/env python3
import socketserver

SOCKET_SERVICE = ('127.0.0.1', 8808)

class TCPHandler(socketserver.StreamRequestHandler):
    '''
    Handler d'un socket server gérant :
    - creation de la socket service,
    - bind
    - listen
    - accept
    '''
    def handle(self):
        '''
        - lecture du message du client
        - ecriture dans le flux a destination du client
        '''
        data = self.rfile.readline().strip() # le client devra ajouter "\n" en fin de message !!
        print('>>> Reçu: %s' % data.decode())
        self.wfile.write(b"Bonjour " + data.strip() + b".\n") # envoie des bytes

if __name__ == "__main__":
    server = socketserver.TCPServer(SOCKET_SERVICE, TCPHandler)
    server.serve_forever()
