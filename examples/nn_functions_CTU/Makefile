CC = clang
CFLAGS = -Wall -Wextra

all: example

example: main.o data.o operations.o
	$(CC) $(CFLAGS) -o example main.o data.o operations.o -lm

main.o: main.c data.h operations.h
	$(CC) $(CFLAGS) -c main.c

data.o: data.c data.h
	$(CC) $(CFLAGS) -c data.c

operations.o: operations.c operations.h
	$(CC) $(CFLAGS) -c operations.c

clean:
	rm -rf example main.o data.o operations.o compile_commands.json reports reports_html

