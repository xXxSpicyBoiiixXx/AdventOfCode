CC = gcc

CFLAGS = -g -Wall -lm -O3 

all: main.c 
	$(CC) $(CFLAGS) main.c -o main.o 

run: 
	./main.o

clean:
	$(RM) -rf answer.txt *.o *.~ *.dSYM 

