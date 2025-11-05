NAME = violence
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp HumanA.cpp HumanB.cpp Weapon.cpp
HEADERS = HumanA.hpp HumanB.hpp Weapon.hpp
OBJS = $(SRCS:.cpp=.o)
RM = rm -f
VG = valgrind -s --leak-check=full --show-leak-kinds=all

all: $(NAME)

# Compilation: .cpp -> .o initialization
%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Edition des liens: .o -> executable compilation
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

test: re
	$(VG) ./$(NAME)

.PHONY: all clean fclean re test
