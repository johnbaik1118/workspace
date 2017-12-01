CC=gcc
CFLAGS=-I.
DEPS = ./headers/*
OBJ = poker_print.o poker_game.o

%.o: ./sources/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

poker: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
