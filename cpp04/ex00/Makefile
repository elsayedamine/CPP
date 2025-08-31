NAME = Animal
FLAGS = -Wall -Wextra -Werror
SRCS = Animal.cpp  Cat.cpp  Dog.cpp  main.cpp  WrongAnimal.cpp  WrongCat.cpp

CC = c++ -std=c++98 

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all