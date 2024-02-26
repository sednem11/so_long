/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macampos <macampos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 18:48:24 by macampos          #+#    #+#             */
/*   Updated: 2024/02/26 16:47:43 by macampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "minilibx-linux/mlx_int.h"
# include "minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>

# define SCALE 64

typedef struct	s_image
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
	int		i;
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
}		t_data;

t_data	*get(void);

void	put_image_to_window(t_image **image, int x, int y);
int		my_pixel_get(t_image **image, int x, int y, int positionx, int positiony);
void	create_image_addr(t_image **image);
void	get_xy(int fd);
void	map(int fd);
void	floodfill(char **map, int x, int y);
int		player_colectable_exit();
void	check_if_squared();
void	mlx_start();
void	player_cordinates();
void	print_map(char **map);
void	mlx_end();
void	rendering_map();
void	my_pixel_put(t_image **image, int x , int y, int color);
void	create_image_ptr(t_image **image, char *file);
void	create_images();

#endif