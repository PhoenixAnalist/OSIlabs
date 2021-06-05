CC=g++
CFLAGS=-I.

all: parallel_min_max Shawn parallel_sum process_memory

parallel_min_max: find_min_max.o parallel_min_max.c
	$(CC) parallel_min_max.c find_min_max.o utils.o -o parallel_min_max.exe

find_min_max.o: utils.o find_min_max.c find_min_max.h
	$(CC) -c find_min_max.c -o find_min_max.o

utils.o: utils.c utils.h
	$(CC) -c utils.c -o utils.o

Shawn: Shawn.c
	$(CC) Shawn.c -o Shawn.exe

parallel_sum: parallel_sum.c
	$(CC) parallel_sum.c utils.c sum.c -pthread -o parallel_sum

process_memory: process_memory.c
	$(CC) process_memory.c -o process_memory.exe

clear:
	rm parallel_min_max.exe find_min_max.o utils.o Shawn.exe process_memory.exe