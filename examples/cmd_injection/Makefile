# Makefile

CC = clang
CFLAGS = -Wall -Wextra

all: example

example: example.o
	$(CC) $(CFLAGS) -o example example.o

example.o: example.c
	$(CC) $(CFLAGS) -c example.c

clean:
	rm -rf example example.o compile_commands.json reports report_html
