/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macampos <macampos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 18:48:24 by macampos          #+#    #+#             */
/*   Updated: 2024/02/06 14:51:38 by macampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
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
}		t_data;

void	get_xy(int fd);
void	map(int fd);
void	floodfill(char **map, int x, int y);
int		player_colectable_exit(int fd);
int		check_walls(int fd, int y, int x);
int		check_if_squared(int fd, int x);

#endif