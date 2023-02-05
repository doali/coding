CC=g++
DBUS_CFLAGS=`pkg-config --cflags dbus-1`
DBUS_LDFLAGS=`pkg-config --libs dbus-1`
EXE=ping-pong

all: $(EXE)

$(EXE): dbus-ping-pong.c
	$(CC) $^ -o $(EXE) $(DBUS_CFLAGS) $(DBUS_LDFLAGS)

clean:
	rm $(EXE)
