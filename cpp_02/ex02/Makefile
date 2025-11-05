NAME = fixed
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp Fixed.cpp
INCLUDE = Fixed.hpp
OBJS = $(SRCS:.cpp=.o)
RM = rm -f
VG = valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes

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

test: re
	$(VG) ./$(NAME)

.PHONY: all clean fclean re test
