/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macampos <mcamposmendes@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:18:10 by macampos          #+#    #+#             */
/*   Updated: 2024/02/29 15:11:09 by macampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	help_change_player(int direction, int x, int y)
{
	while (get()->map[y][x])
	{
		if (get()->map[y][x] == 'y' && (get()->map[y][x + 1] != '1' || direction != 4) &&
			(get()->map[y][x - 1] != '1' || direction != 2) &&
			(get()->map[y + 1][x] != '1' || direction != 3) &&
			(get()->map[y - 1][x] != '1' || direction != 1))
		{
			get()->map[y][x] = '2';
			if (direction == 1 && get()->map[y - 1][x] != '1')
				get()->map[y - 1][x] = 'y';
			else if (direction == 2 && get()->map[y][x - 1] != '1')
				get()->map[y][x - 1] = 'y';
			else if (direction == 3 && get()->map[y + 1][x] != '1')
				get()->map[y + 1][x] = 'y';
			else if (direction == 4 && get()->map[y][x + 1] != '1')
				get()->map[y][x + 1] = 'y';
			return(1);
		}
		x++;
	}
	return(0);
}

void	change_player(int	direction)
{
	int		y;
	int		check;
	check = 0;

	y = 0;
	while (get()->map[y] && check == 0)
	{
		check = help_change_player(direction, 0, y);
		y++;
	}
}

void	rendering(t_image **image, t_image **image2, int positionx, int positiony, int i, int j)
{
	int				y;
	int				x;
	int				color;
	
	y = 0;
	while (y < 32)
	{	
		x = 0;
		while (x < 32)
		{
			color = my_pixel_get((*image), x, y, i, j);
			if (color != -16777216)
				my_pixel_put(image2, x + (SCALE * positionx), y + (SCALE * positiony), color);
			x++;
		}
		y++;
	}
}

void	rendering_map()
{
	int x;
	int y;
	
	x = 0;
	y = 0;
	while (y < get()->map_y)
	{
		while (x < get()->map_x - 1)
		{
			ft_printf("%i\n", x);
			if (get()->map[y][x] == '1')
				rendering(&get()->images[0], &get()->images[2], x, y,  1, 1);
			if (get()->map[y][x] != '1')
				rendering(&get()->images[0], &get()->images[2], x, y, 3, 3);
			if (get()->map[y][x] == 'y')
				rendering(&get()->images[1], &get()->images[2], x, y, 0, 0);
			x++;
		}
		x = 0;
		y++;
	}
	mlx_put_image_to_window(get()->mlx, get()->window, get()->images[2]->img, 0, 0);
}
