NAME = libftprintf.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
SRCS = srcs/ft_print_hex.c srcs/ft_print_chars.c srcs/ft_print_ptr.c srcs/ft_print_nums.c includes/ft_printf.c

OBJS = $(SRCS:.c=.o)

%.o: %.c
	gcc -Wall -Wextra -Werror -I include/ -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft/ all
	cp libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(NAME)
fclean: clean
	rm -f $(NAME)
	make -C libft/ clean

re: fclean all
.PHONY: all clean fclean re
