/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macampos <macampos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:52:03 by macampos          #+#    #+#             */
/*   Updated: 2024/03/04 20:02:09 by macampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_count(void)
{
	int	b;
	int	c;

	get()->i = 5;
	b = 5;
	c = 5;
	get()->i += get()->moves;
	while (get()->i > 14)
	{
		get()->i -= 10;
		b += 1;
	}
	while (b > 14)
	{
		b -= 10;
		c += 1;
	}
	while (c > 14)
		c -= 10;
	rendering(&get()->images[get()->i], (get()->map_x - 1), 0, 4);
	rendering(&get()->images[b], (get()->map_x - 2), 0, 4);
	rendering(&get()->images[c], (get()->map_x - 3), 0, 4);
}

int	handel_input(int keysym)
{
	if (keysym == XK_Escape)
		mlx_end(1);
	if (keysym == XK_w)
	{
		change_player(1);
		rendering_map(5);
	}
	if (keysym == XK_a)
	{
		change_player(2);
		rendering_map(5);
	}
	if (keysym == XK_s)
	{
		change_player(3);
		rendering_map(5);
	}
	if (keysym == XK_d)
	{
		change_player(4);
		rendering_map(5);
	}
	return (1);
}

int	handel_input2(int keysym)
{
	if (keysym == XK_w)
	{
		rendering_map(4);
	}
	if (keysym == XK_a)
	{
		rendering_map(4);
	}
	if (keysym == XK_s)
	{
		rendering_map(4);
	}
	if (keysym == XK_d)
	{
		rendering_map(4);
	}
	return (1);
}

void	init_mlx_window(void)
{
	int		width;
	int		height;
	char	*so_long;
	t_data	*temp;

	so_long = "so_longgg";
	width = ((get()->map_x) * SCALE);
	height = get()->map_y * SCALE;
	temp = get();
	temp->window = mlx_new_window(temp->mlx, width, height, so_long);
}

void	mlx_start(void)
{
	get()->mlx = mlx_init();
	init_mlx_window();
	init_mlx_images();
	rendering_map(4);
	mlx_hook(get()->window, 2, (1L << 0), handel_input, NULL);
	mlx_key_hook(get()->window, handel_input2, NULL);
	mlx_loop(get()->mlx);
}
