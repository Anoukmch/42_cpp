# Program name
NAME	= ex03

# Compiler
CC		= c++
CFLAGS	= -Werror -Wextra -Wall -std=c++98

# Files
HEADER = ./AMateria.hpp ./Character.hpp ./Cure.hpp ./Ice.hpp ./ICharacter.hpp ./MateriaSource.hpp ./IMateriaSource.hpp
SRCS	= main.cpp AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp
OBJS	= $(SRCS:.cpp=.o)
INC		= -I ./

# Build rule
all: $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

# Program build rule
$(NAME): $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(INC)

# Clean rules

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

# Remake
re: fclean all

.PHONY: all re clean fclean
