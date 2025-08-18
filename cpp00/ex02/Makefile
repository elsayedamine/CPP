NAME = BankAccounts
FLAGS = -Wall -Wextra -Werror
SRCS =	Account.cpp \
		tests.cpp
CC = c++ -std=c++98

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all