CC=gcc
CFLAGS=-I.
DEPS = ./headers/*
OBJ = poker_print.o poker_game.o poker_comp.o

%.o: ./sources/%.c $(DEPS)
	$(CC) -g -c -o $@ $< $(CFLAGS)

poker: $(OBJ)
	$(CC) -g -o $@ $^ $(CFLAGS)

clean:
	rm *.o poker
