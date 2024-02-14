# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: macampos <mcamposmendes@gmail.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/27 18:38:34 by macampos          #+#    #+#              #
#    Updated: 2024/02/13 17:27:10 by macampos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Name = so_long

SRCS = so_long.c parcing_helpper.c mlx_handler/mlx.c map_size/map_size_y.c map_size/map.c cordinates/cordinates.c  \

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

CC = cc

$(NAME): $(OBJS)
		$(MAKE) -C ./libft
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS) ./libft/libft.a -Llibft -lft ./minilibx-linux/libmlx.a

all: $(NAME)

clean:	
			cd libft && make clean
			rm -rf $(OBJS)

fclean:	clean
			cd libft && make fclean
			rm -rf $(NAME)

re:		fclean all

.PHONY: all clean fclean re