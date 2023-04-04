CPPFLAGS = -Wall -Werror -Wextra -std=c++98

NAME = phonebook

SRC = 	main.cpp \
		Contact.cpp \
		Phonebook.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	c++ -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)b 

fclean: clean
	rm -f $(NAME)

re: clean fclean $(NAME)