/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating_images.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macampos <macampos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 17:27:09 by macampos          #+#    #+#             */
/*   Updated: 2024/03/04 18:04:48 by macampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	create_image_addr(t_image *image)
{
	image->image_pixel = mlx_get_data_addr(image->img, &image->bits_per_pixel,
			&image->line_len, &image->endian);
	if (!image->image_pixel)
	{
		ft_printf("image_pixel");
		mlx_end(0);
		exit(1);
	}
}

void	create_image_ptr(t_image **image, char *file)
{
	(*image)->img = mlx_xpm_file_to_image(get()->mlx, file, &(*image)->width,
			&(*image)->height);
	if (!(*image)->img)
	{
		ft_printf("ERROR\n");
		mlx_end(0);
		exit(1);
	}
	create_image_addr(*image);
}

void	create_image_ptr2(t_image **image, int width, int height)
{
	(*image)->img = mlx_new_image(get()->mlx, width, height);
	if (!(*image)->img)
	{
		ft_printf("ERROR\n");
		mlx_end(0);
		exit(1);
	}
	create_image_addr(*image);
}

void	create_images(void)
{
	create_image_ptr(&get()->images[0], "xpmfiles/TX-Tileset-Grass.xpm");
	create_image_ptr(&get()->images[1], "xpmfiles/character.xpm");
	create_image_ptr(&get()->images[3], "xpmfiles/Treasure-.xpm");
	create_image_ptr(&get()->images[4], "xpmfiles/TX-Props.xpm");
	create_image_ptr2(&get()->images[2], get()->map_x * SCALE, get()->map_y
		* SCALE);
	create_image_ptr(&get()->images[5], "xpmfiles/number0.xpm");
	create_image_ptr(&get()->images[6], "xpmfiles/number1.xpm");
	create_image_ptr(&get()->images[7], "xpmfiles/number2.xpm");
	create_image_ptr(&get()->images[8], "xpmfiles/number3.xpm");
	create_image_ptr(&get()->images[9], "xpmfiles/number4.xpm");
	create_image_ptr(&get()->images[10], "xpmfiles/number5.xpm");
	create_image_ptr(&get()->images[11], "xpmfiles/number6.xpm");
	create_image_ptr(&get()->images[12], "xpmfiles/number7.xpm");
	create_image_ptr(&get()->images[13], "xpmfiles/number8.xpm");
	create_image_ptr(&get()->images[14], "xpmfiles/number9.xpm");
}
