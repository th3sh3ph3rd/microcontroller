# author: Thomas Lamprecht, 2018

OBJECTS_DB = database.o channel_info.o

CC = gcc
CFLAGS = -std=gnu11 -Wall -pedantic -g

all: database

database: $(OBJECTS_DB)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f database  *.o
