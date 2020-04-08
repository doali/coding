#!/usr/bin/env python3
import socketserver

SOCKET_SERVICE = ('127.0.0.1', 8809)

class UDPHandler(socketserver.DatagramRequestHandler):
    '''
    Handler d'un socket server gérant :
    - bind
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
    server = socketserver.UDPServer(SOCKET_SERVICE, UDPHandler)
    server.serve_forever()
