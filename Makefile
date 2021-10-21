NAME = push_swap
FILES = main push_swap get_stack sort_functions sort_five free_functions
OBJS = $(SRCS:.c=.o)
SRCS_DIR = ./
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)
bonus: $(NAME)
clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)
re: fclean all

.PHONY: all clean fclean re bonus

