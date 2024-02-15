/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macampos <macampos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:52:03 by macampos          #+#    #+#             */
/*   Updated: 2024/02/15 21:06:58 by macampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	mlx_start()
{
	get()->mlx = mlx_init();
	get()->window = mlx_new_window(get()->mlx, 700, 700, "so_long");
	get()->image = mlx_new_image(get()->mlx, 20, 20);
	mlx_loop(get()->mlx);
}