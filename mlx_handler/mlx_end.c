/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_end.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macampos <macampos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:56:47 by macampos          #+#    #+#             */
/*   Updated: 2024/02/20 18:57:34 by macampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_map()
{
	int		i;

	i = 0;
	while(get()->map[i])
	{
		free(get()->map[i]);
		i++;
	}
	free(get()->map);
}

void	mlx_end()
{
	mlx_do_key_autorepeaton(get()->mlx);
	mlx_destroy_window(get()->mlx, get()->window);
	mlx_destroy_display(get()->mlx);
	free(get()->mlx);
	free_map();
	exit(1);
}
