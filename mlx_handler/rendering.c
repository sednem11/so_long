/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macampos <macampos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:18:10 by macampos          #+#    #+#             */
/*   Updated: 2024/03/04 19:42:47 by macampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	help_find_position2(int i)
{
	if (i == 0)
		return (9);
	if (i == 1)
		return (2);
	if (i == 2)
		return (5);
	if (i == 3)
		return (7);
	if (i == 4)
		return (0);
	if (i == 5)
		return (0);
	if (i == 6)
		return (6);
	if (i == 7)
		return (5);
	if (i == 8)
		return (3);
	if (i == 9)
		return (4);
	return (0);
}

int	help_find_position(int i)
{
	if (i == 0)
		return (12);
	if (i == 1)
		return (2);
	if (i == 2)
		return (0);
	if (i == 3)
		return (5);
	if (i == 4)
		return (0);
	if (i == 5)
		return (17);
	if (i == 6)
		return (1);
	if (i == 7)
		return (1);
	if (i == 8)
		return (1);
	if (i == 9)
		return (1);
	return (0);
}

void	rendering(t_image **image, int positionx, int positiony, int i)
{
	int	y;
	int	x;
	int	color;

	y = 0;
	while (y < 32)
	{
		x = 0;
		while (x < 32)
		{
			color = my_pixel_get((*image), x, y, i);
			if (color != -16777216)
				my_pixel_put(&get()->images[2], x + (SCALE * positionx), y
					+ (SCALE * positiony), color);
			x++;
		}
		y++;
	}
}

void	help_rendering_map(int y, int x, int move)
{
	if (get()->map[y][x] == '1')
		rendering(&get()->images[4], x, y, 0);
	if (get()->map[y][x] != '1')
		rendering(&get()->images[0], x, y, 1);
	if (get()->map[y][x] == 'c')
		rendering(&get()->images[3], x, y, 2);
	if (get()->map[y][x] == 'y')
		rendering(&get()->images[1], x, y, move);
	if (get()->map[y][x] == 'f')
		rendering(&get()->images[3], x, y, 3);
	if (get()->map[y][x] == 'a')
	{
		if (get()->colectable2 == 0)
			rendering(&get()->images[4], x, y, 0);
		rendering(&get()->images[1], x, y, 4);
	}
}

void	rendering_map(int move)
{
	int	x;
	int	y;

	y = 0;
	while (y < get()->map_y)
	{
		x = 0;
		while (x < get()->map_x)
		{
			help_rendering_map(y, x, move);
			check_exit(y, x);
			x++;
		}
		y++;
	}
	move_count();
	mlx_put_image_to_window(get()->mlx, get()->window, get()->images[2]->img, 0,
		0);
}
