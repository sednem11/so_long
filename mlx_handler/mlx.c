/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macampos <macampos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:52:03 by macampos          #+#    #+#             */
/*   Updated: 2024/02/24 20:22:13 by macampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int		handel_input(int keysym)
{
	if (keysym == XK_Escape)
	{
		ft_printf("you have pressed (ESC)\n");
		mlx_end();
		return(0);
	}
	if (keysym == XK_w)
		ft_printf("W\n");
	if (keysym == XK_a)
		ft_printf("W\n");
	if (keysym == XK_s)
		ft_printf("W\n");
	if (keysym == XK_d)
		ft_printf("W\n");
	return(1);
}

void	init_mlx_window()
{
	get()->width = get()->map_x * SCALE;
	get()->height = get()->map_y * SCALE;
	get()->window = mlx_new_window(get()->mlx, get()->width, get()->height, "so_long");
}

void	create_image_addr(t_image **image)
{
	(*image)->image_pixel = mlx_get_data_addr((*image)->img, &(*image)->bits_per_pixel, &(*image)->line_len, &(*image)->endian);
}
void	create_image_ptr(t_image **image)
{
		(*image)->img = mlx_xpm_file_to_image(get()->mlx, "DinoSprites-mort.xpm" , &(*image)->width, &(*image)->height);
}

void	put_image_to_window(t_image **image, int x, int y)
{
	mlx_put_image_to_window(get()->mlx, get()->window, (*image)->img, x, y);
}

int		my_pixel_get(t_image **image, int x , int y)
{
	int	offset;

	offset = ((*image)->line_len * y) + (x * ((*image)->bits_per_pixel / 8));
	return *(unsigned int *)((*image)->img + offset);
}

void	my_pixel_put(t_image **image, int x , int y, int color)
{
	int	offset;

	offset = ((*image)->line_len * y) + (x * ((*image)->bits_per_pixel / 8));

	*((unsigned int *)(offset + (*image)->image_pixel)) = color;
}
void	create_images()
{
	create_image_ptr(&get()->images[0]);
	create_image_ptr(&get()->images[1]);
	create_image_ptr(&get()->images[2]);
	create_image_ptr(&get()->images[3]);
	create_image_ptr(&get()->images[4]);
	create_image_ptr(&get()->images[5]);
	create_image_ptr(&get()->images[6]);
	create_image_ptr(&get()->images[7]);
	create_image_ptr(&get()->images[8]);
	create_image_ptr(&get()->images[9]);
	get()->images[10] = NULL;
}

void	init_mlx_images()
{
	int	i;

	i = 0;
	create_images();
	while (get()->images[i] && get()->images != NULL)
	{
		create_image_addr(&get()->images[i]);
		i++;
	}
}
void	mlx_start()
{
	get()->mlx = mlx_init();
	init_mlx_window();
	init_mlx_images();
	rendering_map();
	mlx_hook(get()->window, 2, (1L<<0), handel_input, NULL);
	mlx_loop(get()->mlx);
}