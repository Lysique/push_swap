NAME_PS = push_swap
NAME_CHECKER = checker
FILES_PS = main push_swap check_if_duplicates get_stack sort_functions functions_call seek_functions sort_five sort_more find_best_push utils free_functions
FILES_CHECKER = main get_stack check_if_duplicates free_functions sort_functions functions_call read_std_input
OBJS_PS = $(SRCS_PS:.c=.o)
OBJS_CHECKER =  $(SRCS_CHECKER:.c=.o)
SRCS_DIR_PS = ./push_swap_srcs/
SRCS_DIR_CHECKER = ./checker_srcs/
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SRCS_PS = $(addprefix $(SRCS_DIR_PS), $(addsuffix .c, $(FILES_PS)))
SRCS_CHECKER = $(addprefix $(SRCS_DIR_CHECKER), $(addsuffix .c, $(FILES_CHECKER)))

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
all: $(NAME_PS) $(NAME_CHECKER)

$(NAME_PS): $(OBJS_PS)
	$(CC) -o $(NAME_PS) $(OBJS_PS)
$(NAME_CHECKER): $(OBJS_CHECKER)
	$(CC) -o $(NAME_CHECKER) $(OBJS_CHECKER)
clean:
	$(RM) $(OBJS_PS) $(OBJS_CHECKER)
fclean: clean
	$(RM) $(NAME_PS) $(NAME_CHECKER)
re: fclean all

.PHONY: all clean fclean re bonus

