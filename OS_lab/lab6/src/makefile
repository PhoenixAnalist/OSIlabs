CC=gcc -std=c99

all: client server
	
client: client.c factorial
	$(CC) client.c factorial.o -o client.exe

server: server.c factorial
	$(CC) server.c factorial.o -lpthread  -o server.exe

factorial: factorial.c factorial.h
	$(CC) -c factorial.c -o factorial.o

clear:
	rm factorial.o client.exe server.exe