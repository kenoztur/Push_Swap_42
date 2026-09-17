NAME = push_swap.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

FILES = algorithm_complex \
		algorithm_medium \
		algorithm_simple \
		algorithm_selection_sort \
		bench_mode \
		helper \
		operation_op \
		operation_push \
		operation_r_rotate \
		operation_rotate \
		operation_swap \
		parser_fill_flags \
		parser_get_numbers \
		parser_parse

SRCS = $(addprefix ./, $(addsuffix .c, $(FILES)))
OBJS = $(addprefix ./, $(addsuffix .o, $(FILES)))

all: $(NAME)
	$(CC) $(CFLAGS) main.c -o push_swap push_swap.a

$(NAME): $(OBJS)
	make -C libft all
	cp libft/libft.a $(NAME)
	$(AR) $(NAME) $(OBJS)

%.o : %.c push_swap.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJS)
	make -C libft clean

fclean: clean
	$(RM) $(NAME) push_swap
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re