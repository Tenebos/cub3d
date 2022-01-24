SRCS	= main.c\
	  parsing.c\
	  pars.c\
	  pars2.c\
	  pars_map.c\
	  check_map.c\
	  init.c

OBJS	= ${SRCS:.c=.o}

RM	= rm -rf

CC	= clang
CFLAGS	= -Wall -Wextra -Werror

NAME	= cub3D

all:	$(NAME)

$(NAME): $(OBJS)
	make -C ./My-own-libft
	$(CC) $(OBJS) $(CFLAGS) -L ./minilibx-linux/ -L ./My-own-libft/ -lft -I ./minilibx-linux/mlx.h -lmlx -lXext -lX11 -lm -o $(NAME)

clean:
	make -C ./My-own-libft/ fclean
	rm -f $(OBJS)

fclean: clean
	rm -f libft.a
	rm -f $(NAME)

re:	fclean all
