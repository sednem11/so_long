/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_end.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macampos <macampos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:56:47 by macampos          #+#    #+#             */
/*   Updated: 2024/03/04 18:03:29 by macampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_map(void)
{
	int	i;

	i = 0;
	while (get()->map[i])
	{
		free(get()->map[i]);
		i++;
	}
	free(get()->map);
}

void	free_images(void)
{
	int	i;

	i = 0;
	while (i < 15)
	{
		free(get()->images[i]);
		i++;
	}
	free(get()->images);
}

void	destroy_images(void)
{
	int	i;

	i = 0;
	while (i < 15)
	{
		mlx_destroy_image(get()->mlx, get()->images[i]->img);
		i++;
	}
}

void	mlx_end(int esc)
{
	if (esc == 1)
		ft_printf("you have pressed (ESC)\n");
	mlx_do_key_autorepeaton(get()->mlx);
	mlx_destroy_window(get()->mlx, get()->window);
	destroy_images();
	mlx_destroy_display(get()->mlx);
	free(get()->mlx);
	free_map();
	free_images();
	exit(1);
}
