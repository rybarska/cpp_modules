SRC = ./main.cpp \
      ./Bureaucrat.cpp \
      ./AForm.cpp \
      ./ShrubberyCreationForm.cpp \
      ./RobotomyRequestForm.cpp \
      ./PresidentialPardonForm.cpp \
      ./Intern.cpp
OBJ = $(SRC:.cpp=.o)
CXX = c++
CXXFLAGS = -Werror -Wextra -Wall -std=c++98
NAME = prog

all:$(NAME)

$(NAME):$(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
