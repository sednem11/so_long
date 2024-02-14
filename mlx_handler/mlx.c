/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macampos <mcamposmendes@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:52:03 by macampos          #+#    #+#             */
/*   Updated: 2024/02/08 22:23:40 by macampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_data	*get(void)
{
	static t_data	data;

	return (&data);
}

void	mlx_start()
{
    get()->mlx = mlx_init();
	get()->window = mlx_new_window(get()->mlx, 100, 100, "so_long");
	get()->image = mlx_new_image(get()->mlx, 5, 5);
}