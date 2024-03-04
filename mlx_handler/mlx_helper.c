/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macampos <macampos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 19:35:25 by macampos          #+#    #+#             */
/*   Updated: 2024/03/04 19:43:36 by macampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_image_to_window(t_image **image, int x, int y)
{
	mlx_put_image_to_window(get()->mlx, get()->window, (*image)->img, x, y);
}

int	my_pixel_get(t_image *image, int x, int y, int i)
{
	int	offset;
	int	positionx;
	int	positiony;

	positionx = help_find_position(i);
	positiony = help_find_position2(i);
	y += (positiony * SCALE3);
	x += (positionx * SCALE2);
	offset = (image->line_len * y) + (x * (image->bits_per_pixel / 8));
	return (*(unsigned int *)(image->image_pixel + offset));
}

void	my_pixel_put(t_image **image, int x, int y, int color)
{
	int	offset;

	offset = ((*image)->line_len * y) + (x * ((*image)->bits_per_pixel / 8));
	*((unsigned int *)(offset + (*image)->image_pixel)) = color;
}

void	init_mlx_images(void)
{
	int	i;

	i = 0;
	get()->images = (t_image **)malloc(sizeof(t_image *) * 20);
	while (i < 15)
	{
		get()->images[i] = (t_image *)malloc(sizeof(t_image));
		i++;
	}
	i = 0;
	create_images();
}
