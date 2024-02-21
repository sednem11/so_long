/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macampos <macampos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 18:48:24 by macampos          #+#    #+#             */
/*   Updated: 2024/02/20 11:25:37 by macampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "minilibx-linux/mlx_int.h"
# include "minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct data
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
	void	*mlx;
	void	*image;
	void	*window;
	int		w;
	int		a;
	int		s;
	int		d;
}		t_data;

t_data	*get(void);

void	get_xy(int fd);
void	map(int fd);
void	floodfill(char **map, int x, int y);
int		player_colectable_exit();
void	check_if_squared();
void	mlx_start();
void	player_cordinates();
void	print_map(char **map);
void	mlx_end();

#endif