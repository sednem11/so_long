/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macampos <mcamposmendes@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 17:37:11 by macampos          #+#    #+#             */
/*   Updated: 2024/03/03 21:15:47 by macampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	end_game2(int direction, int x, int y)
{
	if (direction == 1 && get()->map[y - 1][x] == 'f')
	{
		ft_printf("YOU LOST!!!");
		mlx_end();
	}
	else if (direction == 2 && get()->map[y][x - 1] == 'f')
	{
		ft_printf("YOU LOST!!!");
		mlx_end();
	}
	else if (direction == 3 && get()->map[y + 1][x] == 'f')
	{
		ft_printf("YOU LOST!!!");
		mlx_end();
	}
	else if (direction == 4 && get()->map[y][x + 1] == 'f')
	{
		ft_printf("YOU LOST!!!");
		mlx_end();
	}
}

void	end_game(int direction, int x, int y)
{
	if (direction == 1 && x == get()->ex && y == (get()->ey + 1)
		&& get()->colectable2 == 0)
	{
		ft_printf("YOU WON!!");
		mlx_end();
	}
	else if (direction == 4 && x == (get()->ex - 1) && y == get()->ey
		&& get()->colectable2 == 0)
	{
		ft_printf("YOU WON!!");
		mlx_end();
	}
	else if (direction == 3 && x == get()->ex && y == (get()->ey - 1)
		&& get()->colectable2 == 0)
	{
		ft_printf("YOU WON!!");
		mlx_end();
	}
	else if (direction == 2 && x == (get()->ex + 1) && y == get()->ey
		&& get()->colectable2 == 0)
	{
		ft_printf("YOU WON!!");
		mlx_end();
	}
}
