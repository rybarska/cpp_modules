SRC = main.cpp replace.cpp
OBJ = $(SRC:.cpp=.o)
CXX = c++
CXXFLAGS = -Werror -Wextra -Wall -std=c++98
NAME = prog

all:$(NAME)

$(NAME):$(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

main.o: main.cpp replace.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

replace.o: replace.cpp replace.hpp
	$(CXX) $(CXXFLAGS) -c replace.cpp -o replace.o

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
