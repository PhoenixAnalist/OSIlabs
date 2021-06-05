CC=gcc -std=c99

all: tcpclient tcpserver udpclient udpserver

tcp: tcpclient tcpserver

udp: udpclient udpserver

tcpclient: tcpclient.c
	$(CC) tcpclient.c -o tcpclient.exe

tcpserver: tcpserver.c
	$(CC) tcpserver.c -o tcpserver.exe

udpclient: udpclient.c
	$(CC) udpclient.c -o udpclient.exe

udpserver: udpserver.c
	$(CC) udpserver.c -o udpserver.exe

cltcp:
	rm tcpserver.exe tcpclient.exe

cludp:
	rm udpclient.exe udpserver.exe

clear: cltcp cludp