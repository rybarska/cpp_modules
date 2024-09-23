SRC = main.cpp Harl.cpp
OBJ = $(SRC:.cpp=.o)
CXX = c++
CXXFLAGS = -Werror -Wextra -Wall -std=c++98
NAME = harlFilter

all:$(NAME)

$(NAME):$(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

main.o: main.cpp Harl.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

Harl.o: Harl.cpp Harl.hpp
	$(CXX) $(CXXFLAGS) -c Harl.cpp -o Harl.o

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
