SRC = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
OBJ = $(SRC:.cpp=.o)
CXX = c++
CXXFLAGS = -Werror -Wextra -Wall -std=c++98
NAME = prog

all:$(NAME)

$(NAME):$(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

main.o: main.cpp Weapon.hpp HumanA.hpp HumanB.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

Weapon.0: Weapon.cpp Weapon.hpp
	$(CXX) $(CXXFLAGS) -c Weapon.cpp -o Weapon.o

HumanA.o: HumanA.cpp HumanA.hpp
	$(CXX) $(CXXFLAGS) -c HumanA.cpp -o HumanA.o

HumanB.o: HumanB.cpp HumanB.hpp
	$(CXX) $(CXXFLAGS) -c HumanB.cpp -o HumanB.o

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
