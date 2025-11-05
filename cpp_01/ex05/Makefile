NAME = violence
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp Harl.cpp
HEADERS = Harl.hpp
OBJS = $(SRCS:.cpp=.o)
RM = rm -f

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
	valgrind -s --leak-check=full --track-origins=yes --show-leak-kinds=all ./$(NAME)
	valgrind -s --leak-check=full --track-origins=yes --show-leak-kinds=all ./$(NAME) "DEBUG"

.PHONY: all clean fclean re
