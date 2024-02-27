/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating_images.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macampos <mcamposmendes@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 17:27:09 by macampos          #+#    #+#             */
/*   Updated: 2024/02/27 18:57:05 by macampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	create_image_addr(t_image *image)
{
	image->image_pixel = mlx_get_data_addr(image->img, &image->bits_per_pixel, &image->line_len, &image->endian);
}

void	create_image_ptr(t_image **image, char *file)
{
	(*image)->img = mlx_xpm_file_to_image(get()->mlx, file , &(*image)->width, &(*image)->height);
	if(!(*image)->img)
	{
		ft_printf("ERROR");
		exit(1);
	}
}

void 	create_image_ptr2(t_image **image, int width, int height)
{
	(*image)->img = mlx_new_image(get()->mlx, width, height);
}

void	create_images()
{
	create_image_ptr(&get()->images[0], "xpmfiles/tiles.xpm");
	create_image_ptr(&get()->images[1], "xpmfiles/character.xpm");
	ft_printf("%p\n %s\n", get()->images[1]->img, get()->images[1]->image_pixel);
	create_image_ptr2(&get()->images[2], SCALE2, SCALE3);
	create_image_ptr2(&get()->images[3], SCALE2, SCALE3);
	create_image_ptr2(&get()->images[4], SCALE2, SCALE3);
}