NAME = Interfaces
FLAGS = -Wall -Wextra -Werror
SRCS =  main.cpp AMateria.cpp

CC = c++ -std=c++98 

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all