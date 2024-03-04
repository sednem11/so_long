# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: macampos <macampos@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/27 18:38:34 by macampos          #+#    #+#              #
#    Updated: 2024/03/04 19:56:23 by macampos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = main/so_long.c main/parcing_helpper.c mlx_handler/mlx.c map_size/map_size_y.c map_size/map.c cordinates/cordinates.c mlx_handler/mlx_end.c  mlx_handler/rendering.c  \
		mlx_handler/creating_images.c mlx_handler/end_game.c mlx_handler/changing_map.c mlx_handler/mlx_helper.c  \

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address

LIBFLAGS = -lXext -lX11
LIB = minilibx-linux/libmlx_Linux.a

CC = cc

$(NAME): $(OBJS)
		$(MAKE) -C ./libft
		$(MAKE) -C ./minilibx-linux
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIB) $(LIBFLAGS) ./libft/libft.a -Llibft -lft

all: $(NAME)

clean:	
			cd libft && make clean
			rm -rf $(OBJS)

fclean:	clean
			cd libft && make fclean
			rm -rf $(NAME)

norm_fix: fclean
	python3 -m c_formatter_42 $(SRCS)
	norminette $(SRCS)

re:		fclean all

.PHONY: all clean fclean re