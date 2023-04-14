NAME = push_swap
NAMEB = checker
SRC = 	ft_split.c\
		ft_strlen.c\
		main.c\
		sort_thousand.c\
		check_error.c\
		ft_atoi.c\
		ft_strdup.c\
		operations.c\
		utils.c\
		ft_memcpy.c\
		ft_strjoin.c\
		sort_algos.c\
		check_args.c\
		check_args_one.c\
		utils_one.c\
		sort_thousand_one.c\
		sort_algos_one.c\
		sort_algos_two.c\
		sort_algos_tree.c\
		operations_tree.c\
		operations_four.c\
		operations_two.c\
		check_args_two.c\
		ft_lstclear.c\
		

BSRC = 	ft_split.c\
		ft_strlen.c\
		sort_thousand.c\
		check_error.c\
		ft_atoi.c\
		ft_strdup.c\
		operations.c\
		utils.c\
		ft_memcpy.c\
		ft_strjoin.c\
		sort_algos.c\
		get_next_line.c\
		get_next_line_utils.c\
		checker.c\
		check_args.c\
		check_args_one.c\
		utils_one.c\
		ft_strncmp.c\
		sort_thousand_one.c\
		sort_algos_one.c\
		sort_algos_two.c\
		checker_one.c\
		sort_algos_tree.c\
		operations_tree.c\
		operations_four.c\
		operations_two.c\
		check_args_two.c\
		ft_lstclear.c\

OBJS = $(SRC:.c=.o)
BOBJS = $(BSRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME): $(OBJS) push_swap.h
	cc  $(SRC) $(CFLAGS) -o $(NAME)

bonus : push_swap.h
	cc $(BSRC) $(CFLAGS) -o $(NAMEB)

%.o: %.c push_swap.h
	$(CC)  -c $<

clean:
	rm -f $(OBJS) $(BOBJS)

fclean: clean
	rm -f $(NAME) $(NAMEB)

re: fclean all