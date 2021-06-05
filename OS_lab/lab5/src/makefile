CC=gcc -std=c99

all: mutex parallel_factorial deadlock

mutex: mutex.c
	$(CC) mutex.c -lpthread -o mutex.exe

parallel_factorial: parallel_factorial.c
	$(CC) parallel_factorial.c -lpthread -o parallel_factorial.exe

deadlock: deadlock.c
	$(CC) deadlock.c -lpthread -o deadlock.exe

clear:
	rm mutex.exe parallel_factorial.exe deadlock.exe
