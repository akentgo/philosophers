NAME = libftprintf.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
SRCS = srcs/ft_print_hex.c srcs/ft_print_chars.c srcs/ft_print_ptr.c srcs/ft_print_nums.c includes/ft_printf.c

OBJS = $(SRCS:.c=.o)

%.o: %.c
	@ gcc -Wall -Wextra -Werror -I includes/ -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@ ar rcs $(NAME) $(OBJS)
	@ echo Ft_printf compiled👍🏻

clean:
	@ rm -f $(NAME)
	@ echo Ft_printf clean finished✅
fclean: clean
	@ rm -f $(OBJS)

re: fclean all
.PHONY: all clean fclean re
