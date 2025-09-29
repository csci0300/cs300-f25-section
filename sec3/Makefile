CC = gcc
FLAGS = -ggdb3 -Wall -Wextra -Wshadow -std=gnu11 -Wno-unused-parameter -fsanitize=address

all: question1 question2

question1: question1.c
	$(CC) $(FLAGS) $^ -o $@ -lm

question2: question2.c
	$(CC) $(FLAGS) $^ -o $@ -lm

clean:
	rm -f question1 question2

.PHONY: all clean
