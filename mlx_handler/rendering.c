/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macampos <macampos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:18:10 by macampos          #+#    #+#             */
/*   Updated: 2024/02/25 17:07:32 by macampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	rendering(t_image **image, int positionx, int positiony)
{
	int     x;
	int     y;
	int     color;
	
	y = 0;
	x = 0;
	while (y < (*image)->height)
	{
		while (x < (*image)->width)
		{
			color = my_pixel_get(image, x, y, positionx, positiony);
			my_pixel_put(image, x, y, color);
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
		while(x < get()->map_x)
		{
			if (get()->map[y][x] != 2)
				rendering(&get()->images[1], 1, 1);
			else if (get()->map[y][x] == 2)
				rendering(&get()->images[0], 3, 3);
			if (get()->map[y][x] == 'e')
				rendering(&get()->images[2], 9, 4);
			if (get()->map[y][x] == 'c')
				rendering(&get()->images[3], 5, 5);
			if (get()->map[y][x] == 'y')
				rendering(&get()->images[4], 1, 1);
		}
	}
}