CC = gcc
FLAGS = -pedantic
#DB = -std=c++11

all: commandLine

commandLine: main.c
	$(CC) $(FLAGS) -o commandLine main.c

clean:
	rm -rf *.0 *.sw commandLine
