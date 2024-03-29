/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macampos <macampos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 18:48:24 by macampos          #+#    #+#             */
/*   Updated: 2024/03/05 15:25:24 by macampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "minilibx-linux/mlx_int.h"
# include "minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>

# define SCALE 32
# define SCALE2 32
# define SCALE3 32

typedef struct s_image
{
	void	*img;
	char	*image_pixel;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}		t_image;

typedef struct s_data
{
	int		map_y;
	int		map_x;
	int		player;
	int		colectable;
	int		exit;
	int		ex;
	int		ey;
	int		player2;
	int		colectable2;
	int		exit2;
	int		i;
	int		x;
	int		j;
	int		px;
	int		py;
	int		c;
	int		p;
	int		e;
	char	**map;
	t_image	**images;
	void	*mlx;
	void	*window;
	int		width;
	int		height;
	int		moves;
}		t_data;

t_data	*get(void);

void	end_before(int z);
void	free_map(void);
void	put_image_to_window(t_image **image, int x, int y);
int		my_pixel_get(t_image *image, int x, int y, int i);
void	create_image_addr(t_image *image);
void	get_xy(int fd);
void	map(int fd);
void	floodfill(char **map, int x, int y);
int		player_colectable_exit(void);
void	check_if_squared(void);
void	mlx_start(void);
void	player_cordinates(void);
void	print_map(char **map);
void	mlx_end(int esc);
void	rendering_map(int move);
void	my_pixel_put(t_image **image, int x, int y, int color);
void	create_image_ptr(t_image **image, char *file);
void	create_images(void);
void	change_player(int direction);
void	player_colectable_exit2(void);
void	end_game(int direction, int x, int y);
void	end_game2(int direction, int x, int y);
void	rendering(t_image **image, int positionx, int positiony, int i);
void	move_count(void);
void	change_player(int direction);
void	check_exit(int y, int x);
void	init_mlx_images(void);
int		help_find_position(int i);
int		help_find_position2(int i);

#endif