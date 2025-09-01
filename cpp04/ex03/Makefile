NAME = Interfaces
FLAGS = -Wall -Wextra -Werror
SRCS =  AMateria.cpp Cure.cpp  ICharacter.cpp main.cpp Character.cpp Ice.cpp IMateriaSource.cpp MateriaSource.cpp

CC = c++ -std=c++98 

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all