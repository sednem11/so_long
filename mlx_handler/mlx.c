/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macampos <macampos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:52:03 by macampos          #+#    #+#             */
/*   Updated: 2024/02/26 16:47:12 by macampos         ###   ########.fr       */
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

void	put_image_to_window(t_image **image, int x, int y)
{
	mlx_put_image_to_window(get()->mlx, get()->window, (*image)->img, x, y);
}

int		my_pixel_get(t_image **image, int x , int y, int positionx, int positiony)
{
	int	offset;

	y *= positiony;
	x *= positionx;
	offset = ((*image)->line_len * y) + (x * ((*image)->bits_per_pixel / 8));
	return *(unsigned int *)((*image)->img + offset);
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
	get()->images = (t_image **)calloc(sizeof(t_image *), 5);
	while (i < 5)
	{
		get()->images[i] = (t_image *)calloc(sizeof(t_image), 1);
		i++;
	}
	i = 0;
	create_images();
	while (i < 5)
	{
		create_image_addr(&get()->images[i]);
		i++;
	}
}
void	mlx_start()
{
	get()->mlx = mlx_init();
	init_mlx_window();
	ft_printf("%s\n", "AQUIIIIIII!!!!!!");
	init_mlx_images();
	ft_printf("%s\n", "AQUIIIIIII!!!!!!");
	rendering_map();
	mlx_hook(get()->window, 2, (1L<<0), handel_input, NULL);
	mlx_loop(get()->mlx);
}