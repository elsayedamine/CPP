NAME = PhoneBook
FLAGS = -Wall -Wextra -Werror
SRCS =	PhoneBook.cpp \
		Contact.cpp \
		main.cpp
CC = c++ -std=c++98

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all