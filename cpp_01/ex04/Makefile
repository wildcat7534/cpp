NAME = sed
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp 
HEADERS = 
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
	@rm -f *.replace
	@printf "Running tests with Valgrind...\n\n"

	@printf "Test 1: Replace 'truc' with 'bidule' in .test.txt\n"
	@- $(VG) ./$(NAME) .test.txt "truc" "bidule"

	@chmod ugo-r .test2.txt
	@printf "Test 2: Replace 'truc' with '' in .test2.txt\n"
	@- $(VG) ./$(NAME) .test2.txt "truc" ""
	@chmod ugo+r .test2.txt

	@printf "Test 3: Replace 'truc' with '' in .test3.txt\n"
	@- $(VG) ./$(NAME) .test3.txt "truc" ""

	@printf "Test 4: Replace 'truc' with '' in .test4.txt\n"
	@- $(VG) ./$(NAME) .test4.txt "truc" ""

	@printf "Test 5: Replace '' with '' in .test4.txt\n"
	@- $(VG) ./$(NAME) .test4.txt "" ""

	@printf "Test 6: Replace \\\\n with '*' in .test6.txt\n"
	@- $(VG) ./$(NAME) .test6.txt $$'\n' "*"

.PHONY: all clean fclean re
