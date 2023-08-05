
FLAGS = -Wall -Werror -Wextra

CFILES = big_sort.c	ft_split.c \
		manage_stack.c  start_init.c \
		calc_cost.c	main.c \
		order_num.c reverse_rotate.c \
		swap.c check_errors.c \
		push_num.c rotate.c \
		utils.c check_utils.c \
		manage_pos.c small_sort.c

OFILES = $(CFILES:%.c=%.o)

NAME = push_swap

all: $(NAME)

$(NAME): $(OFILES)
	$(CC) $(FLAGS) -o $(NAME) $(OFILES)

%.o: %.c
	$(CC) $(FLAGS) -o $@ -c $<
	
clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all 
