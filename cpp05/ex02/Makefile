NAME = executors
FLAGS = -Wall -Wextra -Werror
SRCS =	AForm.cpp main.cpp RobotomyRequestForm.cpp Bureaucrat.cpp \
		PresidentialPardonForm.cpp  ShrubberyCreationForm.cpp


CC = c++ -std=c++98 

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all