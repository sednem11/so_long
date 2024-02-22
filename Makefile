# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: macampos <mcamposmendes@gmail.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/27 18:38:34 by macampos          #+#    #+#              #
#    Updated: 2024/02/21 20:15:34 by macampos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = main/so_long.c main/parcing_helpper.c mlx_handler/mlx.c map_size/map_size_y.c map_size/map.c cordinates/cordinates.c mlx_handler/mlx_end.c  \

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g

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

re:		fclean all

.PHONY: all clean fclean re