CC = gcc
CFLAGS = -Wall -fPIC

all: serialize_sanity.o 

example: example.c serialize_sanity.o
	$(CC) $(CFLAGS) -o example example.c serialize_sanity.o

serialize_sanity.o: serialize_sanity.c serialize_sanity.h
	$(CC) $(CFLAGS) -c serialize_sanity.c

clean:
	rm -f *.o example
 