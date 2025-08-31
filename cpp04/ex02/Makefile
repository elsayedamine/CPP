NAME = AAnimal
FLAGS = -Wall -Wextra -Werror
SRCS = AAnimal.cpp  Cat.cpp  Dog.cpp  main.cpp  WrongAnimal.cpp  WrongCat.cpp Brain.cpp 

CC = c++ -std=c++98 

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all