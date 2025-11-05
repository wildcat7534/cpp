NAME = phonebook
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp PhoneBook.cpp Contact.cpp
HEADERS = PhoneBook.hpp Contact.hpp
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
	# lower the per-process open-file limit for valgrind (workaround for some Docker/envs)
	ulimit -n 1024 && valgrind -s --leak-check=full --track-origins=yes --show-leak-kinds=all ./$(NAME)

.PHONY: all clean fclean re
