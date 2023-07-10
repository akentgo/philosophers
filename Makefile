NAME = philosophers
CC = gcc
SRCS_FILES = init.c main.c philo_action.c philo_execute.c
UTILS_FILES = error_msg.c print.c time.c
SRCS = $(addprefix srcs/, $(SRCS_FILES)) $(addprefix utils/, $(UTILS_FILES))
STANDARD_FLAGS = -Wall -Wextra -Werror 
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ make -C libft_v1/ all
	@ $(CC) $(STANDARD_FLAGS) -o $(NAME) $(OBJS) -Llibft_full

$(OBJS) : $(SRCS)
	@ $(CC) $(STANDARD_FLAGS) -c $(SRCS) -Iincludes

clean:
	@ make -C libft_v1/ clean
	@ rm -f $(NAME)

fclean: clean
	@ make -C libft_v1/ fclean
	@ rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re