/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_end.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macampos <mcamposmendes@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:56:47 by macampos          #+#    #+#             */
/*   Updated: 2024/03/03 21:13:15 by macampos         ###   ########.fr       */
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
	while(get()->images[i])
	{
		free(get()->images[i]->img);
		i++;
	}
	free(get()->images);
}

void	mlx_end(void)
{
	mlx_do_key_autorepeaton(get()->mlx);
	mlx_destroy_window(get()->mlx, get()->window);
	mlx_destroy_display(get()->mlx);
	free(get()->mlx);
	free_map();
	free_images();
	exit(1);
}
