NAME = phonebook
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp PhoneBook.cpp
INCLUDES = PhoneBook.hpp Contact.hpp
OBJS = $(SRCS:.cpp=.o)
RM = rm -f

all: $(NAME)

# Phase d'assemblage
$(OBJS): %.o: %.cpp $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

# Phase de compilation
$(NAME): $(OBJS)
		$(CC) $(INCLUDES) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
