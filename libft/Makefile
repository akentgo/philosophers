#This makefile compiles all three folders, libft, gnl and printf

NAME = libft_full
CC = gcc
GNL = get_next_line.c get_next_line_utils.c
GNL_CMP = $(addprefix get_next_line/ ${GNL})
STANDARD_FLAGS = -Wall -Wextra -Werror -g -O0
OBJS = $(GNL_CMP).c=.o


all: $(NAME)

$(NAME): $(OBJS)
	make -C libft/ all
	make -C ft_printf/ all
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(NAME)

fclean: clean
	make -C libft/ clean
	make -C ft_printf/ clean

re: fclean all

.PHONY: all clean fclean re