NAME = philosophers
CC = gcc
SRCS_FILES = init.c main.c philo_action.c philo_execute.c error_msg.c
UTILS_FILES = print.c time.c
SRCS = $(addprefix srcs/, $(SRCS_FILES))
UTILS = $(addprefix utils/, $(UTILS_FILES))
STANDARD_FLAGS = -Wall -Wextra -Werror 
OBJS = $(SRCS:.c=.o) $(UTILS:.c=.o)
LIBFT_DIR = libft_full/libft

all: $(NAME)

$(NAME): $(OBJS)
	@ make -C $(LIBFT_DIR)
	@ $(CC) -o $(NAME) $(OBJS) -L$(LIBFT_DIR) -lft $(STANDARD_FLAGS)
	@ echo Philosophers Compiled🤓

$(OBJS): %.o : %.c
	@ $(CC) $(STANDARD_FLAGS) -c $< -o $@

clean:
	@ make -C libft_full/ clean
	@ rm -rf $(NAME) $(OBJS)

fclean: clean
	@ make -C libft_full/ fclean
	@ rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re