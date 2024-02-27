/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macampos <macampos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:18:10 by macampos          #+#    #+#             */
/*   Updated: 2024/02/27 20:20:33 by macampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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