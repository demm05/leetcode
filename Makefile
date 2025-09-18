NAME = main

FILE := ./algo/dailyTemperatures.cpp

all: $(NAME)

$(NAME): $(FILE)
	@c++ -Wall -Wextra -g3 -o $@ $^

g gdb: all
	@gdb --tui $(NAME)

r run: all
	@./$(NAME)

clean:
	@rm -rf $(NAME)

re: clean all

.PHONY: all
