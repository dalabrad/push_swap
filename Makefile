NAME = push_swap
NAME_BONUS = checker

LIB_NAME = libft.a
PS_LIB_NAME = push_swap.a

LIB_SRCS_DIR = ./libft
LIB_SRCS = $(wildcard $(LIB_SRCS_DIR)/ft*.c)
PS_LIB_SRCS = $(wildcard ./ft*.c)

MAIN = main.c
MAIN_BONUS = main_bonus.c 

LIB_OBJS = $(LIB_SRCS:.c=.o)
PS_LIB_OBJS = $(PS_LIB_SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: $(LIB_NAME) $(PS_LIB_NAME) $(NAME)

$(LIB_NAME): $(LIB_OBJS)
	ar rcs $(LIB_NAME) $(LIB_OBJS)

$(PS_LIB_NAME): $(PS_LIB_OBJS)
	ar rcs $(PS_LIB_NAME) $(PS_LIB_OBJS)

$(NAME): $(LIB_NAME) $(PS_LIB_NAME) $(MAIN)
	$(CC) $(CFLAGS) -o $(NAME) $(MAIN) $(LIB_NAME) $(PS_LIB_NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus : $(LIB_NAME) $(PS_LIB_NAME) $(MAIN_BONUS)
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(MAIN_BONUS) $(LIB_NAME) $(PS_LIB_NAME)

clean:
	$(RM) $(LIB_OBJS) $(PS_LIB_OBJS)

fclean: clean
	$(RM) $(LIB_NAME) $(PS_LIB_NAME) $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re
