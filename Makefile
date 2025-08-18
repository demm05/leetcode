NAME = main

FILE := ./algo/bubbleSort.cpp

all: $(NAME)

$(NAME): $(FILE)
	@c++ -Wall -Wextra -o $@ $^

r run: all
	@./$(NAME)

.PHONY: all
