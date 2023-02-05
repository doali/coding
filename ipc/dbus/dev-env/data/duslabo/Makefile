all: server client

server: server.cpp
	g++ server.cpp -o server -I/usr/include/dbus-1.0 -I/usr/lib/x86_64-linux-gnu/dbus-1.0/include -ldbus-1

client: client.cpp
	g++ client.cpp -o client -I/usr/include/dbus-1.0 -I/usr/lib/x86_64-linux-gnu/dbus-1.0/include -ldbus-1

clean:
	rm client server
