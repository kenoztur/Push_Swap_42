# NAME        = push_swap

# CC          = cc
# CFLAGS      = -Wall -Wextra -Werror

# LIBFT_DIR   = libft
# LIBFT       = $(LIBFT_DIR)/libft.a

# SRCS        =

# OBJS        = $(SRCS:.c=.o)

# INCLUDES    = -I. -I$(LIBFT_DIR)

# all: $(LIBFT) $(NAME)

# $(LIBFT):
# 	@make -C $(LIBFT_DIR)

# $(NAME): $(OBJS) $(LIBFT)
# 	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

# clean:
# 	@rm -f $(OBJS)
# 	@make -C $(LIBFT_DIR) clean

# fclean: clean
# 	@rm -f $(NAME)
# 	@make -C $(LIBFT_DIR) fclean

# re: fclean all

# .PHONY: all clean fclean re

TARGET   = push_swap.a

CC      = gcc
CFLAGS  = -Wall -Wextra
AR      = ar
ARFLAGS = rcs

rwildcard = $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2) $(filter $(subst *,%,$2),$d))

SRCS = $(call rwildcard,,*.c)
OBJS = $(SRCS:.c=.o)

INCLUDE_DIRS = $(sort $(dir $(SRCS)))
CFLAGS      += $(addprefix -I,$(INCLUDE_DIRS))

all: $(TARGET)

$(TARGET): $(OBJS)
	$(AR) $(ARFLAGS) $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re