SRC = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp
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

newZombie.o: newZombie.cpp
	$(CXX) $(CXXFLAGS) -c newZombie.cpp -o newZombie.o

randomChump.o: randomChump.cpp
	$(CXX) $(CXXFLAGS) -c randomChump.cpp -o randomChump.o

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
