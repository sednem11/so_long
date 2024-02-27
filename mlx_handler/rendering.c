/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macampos <mcamposmendes@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:18:10 by macampos          #+#    #+#             */
/*   Updated: 2024/02/27 18:46:50 by macampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	rendering(t_image **image, t_image **image2, int positionx, int positiony, int i, int j)
{
	int				y;
	int				x;
	unsigned int	color;
	
	y = 0;
	x = 0;
	while (y < 29)
	{
		while (x < 33)
		{
			color = my_pixel_get((*image), x, y, positionx, positiony);
			my_pixel_put(image2, x, y, color);
			x++;
		}
		x = 0;
		y++;
	}
	mlx_put_image_to_window(get()->mlx, get()->window, (*image2)->img, (i * SCALE2), (j * SCALE3));
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
				rendering(&get()->images[0], &get()->images[3], 1, 1, x, y);
			if (get()->map[y][x] != '1')
				rendering(&get()->images[0], &get()->images[2], 3, 3, x, y);
			if (get()->map[y][x] == 'y')
				rendering(&get()->images[1], &get()->images[4], 1, 1, x, y);
			x++;
		}
		x = 0;
		y++;
	}
}