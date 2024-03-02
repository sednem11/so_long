/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macampos <macampos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:18:10 by macampos          #+#    #+#             */
/*   Updated: 2024/03/02 19:43:57 by macampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	help_change_player(int direction, int x, int y)
{
	while (get()->map[y][x])
	{
		if ((get()->map[y][x] == 'y' || get()->map[y][x] == 'a')
			&& (get()->map[y][x + 1] != '1' || direction != 4)
			&& (get()->map[y][x - 1] != '1' || direction != 2) && (get()->map[y
				+ 1][x] != '1' || direction != 3) && (get()->map[y
				- 1][x] != '1' || direction != 1))
		{
			get()->moves++;
			end_game2(direction, x, y);
			end_game(direction, x, y);
			if (get()->map[y][x] == 'a')
				get()->map[y][x] = 'e';
			else
				get()->map[y][x] = '2';
			if (direction == 1 && get()->map[y - 1][x] != '1')
			{
				if (get()->map[y - 1][x] == 'e')
					get()->map[y - 1][x] = 'a';
				else
					get()->map[y - 1][x] = 'y';
			}
			else if (direction == 2 && get()->map[y][x - 1] != '1')
			{
				if (get()->map[y][x - 1] == 'e')
					get()->map[y][x - 1] = 'a';
				else
					get()->map[y][x - 1] = 'y';
			}
			else if (direction == 3 && get()->map[y + 1][x] != '1')
			{
				if (get()->map[y + 1][x] == 'e')
					get()->map[y + 1][x] = 'a';
				else
					get()->map[y + 1][x] = 'y';
			}
			else if (direction == 4 && get()->map[y][x + 1] != '1'
				&& get()->map[y][x + 1] == 'e')
				get()->map[y][x + 1] = 'a';
			else if (direction == 4 && get()->map[y][x + 1] != '1'
				&& get()->map[y][x + 1] != 'e')
				get()->map[y][x + 1] = 'y';
			return (1);
		}
		x++;
	}
	return (0);
}

void	change_player(int direction)
{
	int	y;
	int	check;

	check = 0;
	y = 0;
	while (get()->map[y] && check == 0)
	{
		check = help_change_player(direction, 0, y);
		y++;
	}
}

void	rendering(t_image **image, t_image **image2, int positionx,
		int positiony, int i, int j)
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
			color = my_pixel_get((*image), x, y, i, j);
			if (color != -16777216)
				my_pixel_put(image2, x + (SCALE * positionx), y + (SCALE
						* positiony), color);
			x++;
		}
		y++;
	}
}

void	check_exit(int y, int x)
{
	if (get()->map[y][x] == 'e')
	{
		player_colectable_exit2();
		if (get()->colectable2 == 0)
			rendering(&get()->images[4], &get()->images[2], x, y, 12, 9);
	}
}

void	rendering_map()
{
	int	x;
	int	y;

	y = 0;
	while (y < get()->map_y)
	{
		x = 0;
		while (x < get()->map_x)
		{
			if (get()->map[y][x] == '1')
				rendering(&get()->images[4], &get()->images[2], x, y, 12, 9);
			if (get()->map[y][x] != '1')
				rendering(&get()->images[0], &get()->images[2], x, y, 2, 2);
			if (get()->map[y][x] == 'y')
				rendering(&get()->images[1], &get()->images[2], x, y, 0, 0);
			if (get()->map[y][x] == 'c')
				rendering(&get()->images[3], &get()->images[2], x, y, 0, 5);
			if (get()->map[y][x] == 'f')
				rendering(&get()->images[3], &get()->images[2], x, y, 5, 7);
			if (get()->map[y][x] == 'a')
			{
				if (get()->colectable2 == 0)
					rendering(&get()->images[4], &get()->images[2], x, y, 12,
						9);
				rendering(&get()->images[1], &get()->images[2], x, y, 0, 0);
			}
			check_exit(y, x);
			x++;
		}
		y++;
	}
	move_count();
	mlx_put_image_to_window(get()->mlx, get()->window, get()->images[2]->img, 0,
		0);
}
