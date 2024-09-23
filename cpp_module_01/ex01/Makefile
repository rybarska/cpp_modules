SRC = main.cpp Zombie.cpp zombieHorde.cpp
OBJ = $(SRC:.cpp=.o)
CXX = c++
CXXFLAGS = -Werror -Wextra -Wall -std=c++98
NAME = prog

all:$(NAME)

$(NAME):$(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

main.o: main.cpp Zombie.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

Zombie.o: Zombie.cpp Zombie.hpp
	$(CXX) $(CXXFLAGS) -c Zombie.cpp -o Zombie.o

zombieHorde.o: zombieHorde.cpp
	$(CXX) $(CXXFLAGS) -c zombieHorde.cpp -o zombieHorde.o

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
