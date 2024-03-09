/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macampos <macampos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 17:37:11 by macampos          #+#    #+#             */
/*   Updated: 2024/03/05 15:52:05 by macampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	end_before(int z)
{
	free_map();
	if (z == 1)
		ft_printf("player couldnt get to every colectable or exit\n");
	exit(1);
}

void	check_exit(int y, int x)
{
	if (get()->map[y][x] == 'e')
	{
		player_colectable_exit2();
		rendering(&get()->images[4], x, y, 9);
		rendering(&get()->images[4], x, (y - 1), 8);
		if (get()->colectable2 == 0)
		{
			rendering(&get()->images[4], x, (y - 1), 0);
			rendering(&get()->images[0], x, y, 1);
			rendering(&get()->images[4], x, y, 6);
			rendering(&get()->images[4], x, (y - 1), 7);
		}
	}
}

void	end_game2(int direction, int x, int y)
{
	if (direction == 1 && get()->map[y - 1][x] == 'f')
	{
		ft_printf("YOU LOST!!!");
		mlx_end(0);
	}
	else if (direction == 2 && get()->map[y][x - 1] == 'f')
	{
		ft_printf("YOU LOST!!!");
		mlx_end(0);
	}
	else if (direction == 3 && get()->map[y + 1][x] == 'f')
	{
		ft_printf("YOU LOST!!!");
		mlx_end(0);
	}
	else if (direction == 4 && get()->map[y][x + 1] == 'f')
	{
		ft_printf("YOU LOST!!!");
		mlx_end(0);
	}
}

void	end_game(int direction, int x, int y)
{
	if (direction == 1 && x == get()->ex && y == (get()->ey + 1)
		&& get()->colectable2 == 0)
	{
		ft_printf("YOU WON!!");
		mlx_end(0);
	}
	else if (direction == 4 && x == (get()->ex - 1) && y == get()->ey
		&& get()->colectable2 == 0)
	{
		ft_printf("YOU WON!!");
		mlx_end(0);
	}
	else if (direction == 3 && x == get()->ex && y == (get()->ey - 1)
		&& get()->colectable2 == 0)
	{
		ft_printf("YOU WON!!");
		mlx_end(0);
	}
	else if (direction == 2 && x == (get()->ex + 1) && y == get()->ey
		&& get()->colectable2 == 0)
	{
		ft_printf("YOU WON!!");
		mlx_end(0);
	}
	end_game2(direction, x, y);
}
