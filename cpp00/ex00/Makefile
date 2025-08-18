NAME = megaphone
FLAGS = -Wall -Wextra -Werror
SRCS = megaphone.cpp
CC = c++ -std=c++98 

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all