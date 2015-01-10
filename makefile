CC = gcc
FLAGS = -std=c99 -Wall -ggdb
FILES = main.o db.o

prog: $(FILES)
	$(CC) $(FLAGS) $(FILES) -o db
	
main.o: main.c
	$(CC) -c main.c

db.o: db.c
	$(CC) -c db.c
	
run: prog
	./db LARGE.db
	
.PHONY: clean
	
clean:
	rm -rf *.o prog
	rm -rf *~
	rm -rf *#

test: unittest.c db.c db.h
	$(CC) $(CFLAGS) -o -lcunit unittests unittest.c db.c

testrun: unittest.c db.c db.h
	$(CC) $(CFLAGS) -o -lcunit unittests unittest.c db.c
	./unittests