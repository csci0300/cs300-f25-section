CC = gcc
FLAGS = -ggdb3 -Wall -Wextra -Wshadow -std=gnu11 -fsanitize=address -Wno-unused-parameter

all: starter pipes

pipes: pipes.c
	$(CC) $(FLAGS) $^ -o $@ -lm

starter: starter.c
	$(CC) $(FLAGS) $^ -o $@ -lm

starter-complete: starter-complete.c
	$(CC) $(FLAGS) $^ -o $@ -lm

clean:
	rm -f starter starter-complete pipes

.PHONY: all clean
