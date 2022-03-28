CC = gcc

all: client server

c: client.o
	${CC} ${CFLAGS} -o c client.o

s: server.o
	${CC} ${CFLAGS} -o s server.o

client.o: client.c
	${CC} ${CFLAGS} -c client.c

server.o: server.c
	${CC} ${CFLAGS} -c server.c

clean:
	rm -f *.a *.o c s