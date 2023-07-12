
NAME = libft_full
CC = gcc
GNL = get_next_line.c get_next_line_utils.c
GNL_DIR = get_next_line
GNL_CMP = $(addprefix $(GNL_DIR)/, $(GNL))
STANDARD_FLAGS = -Wall -Wextra -Werror -g -O0
OBJS = $(GNL_CMP:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	@ make -C libft/ all
	@ make -C ft_printf/ all
	@ ar rcs $(NAME) $(OBJS)
	@ echo Library compiled✅

clean:
	@ make -C libft/ clean
	@ make -C ft_printf/ clean
	@ rm -f $(OBJS)
	@ rm -f $(NAME)

fclean:
	@ make -C libft/ fclean
	@ make -C ft_printf/ fclean
	@ rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re