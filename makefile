CC = gcc
FLAGS = -std=c99 -Wall
FILES = main.o db.o



prog: $(FILES)
	$(CC) $(FLAGS) $(FILES) -o test
	
main.o: main.c
	$(CC) $(FLAGS) main.c

db.o: db.c
	$(CC) -c db.c
	
run: 
	./test
	
clean:
	rm -rf *o prog
