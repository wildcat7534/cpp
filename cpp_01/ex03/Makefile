NAME = violentWorld
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp HumanA.cpp HumanB.cpp Weapon.cpp
INCLUDE = HumanA.hpp HumanB.hpp Weapon.hpp
OBJS = $(SRCS:.cpp=.o)
RM = rm -f

all: $(NAME)
$(NAME): $(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
%.o: %.cpp $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@
clean:
		$(RM) $(OBJS)
fclean: clean
		$(RM) $(NAME)
re: fclean all
.PHONY: all clean fclean re