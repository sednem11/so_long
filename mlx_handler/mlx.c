/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macampos <mcamposmendes@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:52:03 by macampos          #+#    #+#             */
/*   Updated: 2024/02/29 15:40:45 by macampos         ###   ########.fr       */
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
		change_player(1);
	if (keysym == XK_a)
		change_player(2);
	if (keysym == XK_s)
		change_player(3);
	if (keysym == XK_d)
		change_player(4);
	rendering_map();
	return(1);
}

void	init_mlx_window()
{
	get()->width = ((get()->map_x - 1) * SCALE);
	get()->height = get()->map_y * SCALE;
	get()->window = mlx_new_window(get()->mlx, get()->width, get()->height, "so_long");
}

void	put_image_to_window(t_image **image, int x, int y)
{
	mlx_put_image_to_window(get()->mlx, get()->window, (*image)->img, x, y);
}

int		my_pixel_get(t_image *image, int x , int y, int positionx, int positiony)
{
	int	offset;

	y += (positiony * SCALE3);
	x += (positionx * SCALE2);
	offset = (image->line_len * y) + (x * (image->bits_per_pixel / 8));
	return *(unsigned int *)(image->image_pixel + offset);
}

void	my_pixel_put(t_image **image, int x , int y, int color)
{
	int	offset;

	offset = ((*image)->line_len * y) + (x * ((*image)->bits_per_pixel / 8));

	*((unsigned int *)(offset + (*image)->image_pixel)) = color;
}

void	init_mlx_images()
{
	int	i;

	i = 0;
	get()->images = (t_image **)malloc(sizeof(t_image *) * 10);
	while (i < 5)
	{
		get()->images[i] = (t_image *)malloc(sizeof(t_image));
		i++;
	}
	i = 0;
	create_images();
}
void	mlx_start()
{
	get()->mlx = mlx_init();
	init_mlx_window();
	init_mlx_images();
	print_map(get()->map);
	rendering_map();
	mlx_hook(get()->window, 2, (1L<<0), handel_input, NULL);
	mlx_loop(get()->mlx);
}