CC = gcc

all: client server

client: client.o
	${CC} ${CFLAGS} -o client client.o

server: serverMultiThread.o
	${CC} ${CFLAGS} -pthread -o server serverMultiThread.o

client.o: client.c
	${CC} ${CFLAGS} -c client.c

server.o: server.c
	${CC} ${CFLAGS} -c server.c

serverMultiThread.o: serverMultiThread.c
	${CC} ${CFLAGS} -c serverMultiThread.c

clean:
	rm -f *.a *.o client server