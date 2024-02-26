/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating_images.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macampos <macampos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 17:27:09 by macampos          #+#    #+#             */
/*   Updated: 2024/02/26 16:41:25 by macampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	create_image_addr(t_image **image)
{
	(*image)->image_pixel = mlx_get_data_addr((*image)->img, &(*image)->bits_per_pixel, &(*image)->line_len, &(*image)->endian);
}

void	create_image_ptr(t_image **image, char *file)
{
	(*image)->img = mlx_xpm_file_to_image(get()->mlx, file , &(*image)->width, &(*image)->height);
}

void	create_images()
{
	create_image_ptr(&get()->images[0], "tiles.xpm");
	create_image_ptr(&get()->images[1], "tiles.xpm");
	create_image_ptr(&get()->images[2], "tiles.xpm");
	create_image_ptr(&get()->images[3], "tiles.xpm");
	create_image_ptr(&get()->images[4], "DinoSprites-mort");
}