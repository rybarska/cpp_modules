SRC = main.cpp Contact.cpp PhoneBook.cpp
OBJ = $(SRC:.cpp=.o)
CXX = c++
CXXFLAGS = -Werror -Wextra -Wall -std=c++98
NAME = phonebook

all:$(NAME)

$(NAME):$(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

main.o: main.cpp Contact.hpp PhoneBook.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

Contact.o: Contact.cpp Contact.hpp
	$(CXX) $(CXXFLAGS) -c Contact.cpp -o Contact.o

PhoneBook.o: PhoneBook.cpp PhoneBook.hpp
	$(CXX) $(CXXFLAGS) -c PhoneBook.cpp -o PhoneBook.o

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
