SRC = main.cpp
OBJ = $(SRC:.cpp=.o)
CXX = c++
CXXFLAGS = -Werror -Wextra -Wall -std=c++98

NAME = prog

all:$(NAME)

$(NAME):$(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(OBJ): $(SRC)
	$(CXX) $(CXXFLAGS) -c $(SRC) -o $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
