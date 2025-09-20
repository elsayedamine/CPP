NAME = Bureaucrat
FLAGS = -Wall -Wextra -Werror
SRCS = main.cpp Bureaucrat.cpp

CC = c++ -std=c++98 

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all