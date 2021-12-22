# -*- Makefile -*-
CC=gcc
AR=ar
FLAGS= -Wall -g

all: answer
 
ans: answers.a addFunc.a stringProg

stringProg: main.o answers.a addFunc.a
	$(CC) $(FLAGS) -o stringProg main.o addFunc.a answers.a

main.o: main.c
	$(CC) $(FLAGS) -c main.c

answers.a: Q1.o Q2.o Q3.o answers.h
	$(AR) -rcs answers.a Q1.o Q2.o Q3.o

Q1.o: Q1.c answers.h
	$(CC) $(FLAGS) -c Q1.c


Q2.o: Q2.c answers.h
	$(CC) $(FLAGS) -c Q2.c


Q3.o: Q3.c answers.h
	$(CC) $(FLAGS) -c Q3.c


addFunc.a: addFunc.o
	$(AR) -rcs addFunc.a addFunc.o

addFunc.o: addFunc.c addFunc.h
	$(CC) $(FLAGS) -c addFunc.c

.PHONY: clean all
clean:
	rm -f *.o *.a *.so stringProg