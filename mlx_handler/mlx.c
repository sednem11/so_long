/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macampos <macampos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:52:03 by macampos          #+#    #+#             */
/*   Updated: 2024/03/08 14:38:28 by macampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	last_handel_input(void)
{
	mlx_end(0);
	return (1);
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
	ft_printf("%i\n", get()->moves);
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
	mlx_hook(get()->window, 17, 0, last_handel_input, NULL);
	mlx_hook(get()->window, 2, (1L << 0), handel_input, NULL);
	mlx_key_hook(get()->window, handel_input2, NULL);
	mlx_loop(get()->mlx);
}
