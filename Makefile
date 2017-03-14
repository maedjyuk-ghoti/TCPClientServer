CC=clang++

CPPFLAGS=
LDFLAGS=

all: client server

client: client.o client_main.cpp
	$(CC) $(LDFLAGS) -o client client.o client_main.cpp

server: server.o server_main.cpp
	$(CC) $(LDFLAGS) -o server server.o server_main.cpp

client.o: client.cpp client.h
	$(CC) $(CPPFLAGS) -c client.cpp

server.o: server.cpp server.h
	$(CC) $(CPPFLAGS) -c server.cpp

clean:
	rm *.o server client
