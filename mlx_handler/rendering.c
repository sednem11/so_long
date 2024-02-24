/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macampos <macampos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:18:10 by macampos          #+#    #+#             */
/*   Updated: 2024/02/24 20:24:28 by macampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	rendering(t_image **image)
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
			color = my_pixel_get(image, x, y);
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
			if (get()->map[y][x] == 1)
				rendering(&get()->images[1]);
			else if (get()->map[y][x] == 0)
				rendering(&get()->images[0]);
			else if (get()->map[y][x] == 'E')
				rendering(&get()->images[2]);
			else if (get()->map[y][x] == 'C')
				rendering(&get()->images[3]);
			else if (get()->map[y][x] == 'P')
				rendering(&get()->images[4]);
		}
	}
}