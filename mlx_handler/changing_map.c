/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   changing_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macampos <macampos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:51:36 by macampos          #+#    #+#             */
/*   Updated: 2024/03/04 17:52:18 by macampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	help_change_player2(int direction, int x, int y)
{
	if (get()->map[y][x] == 'a')
		get()->map[y][x] = 'e';
	else
		get()->map[y][x] = '2';
	if (direction == 1 && get()->map[y - 1][x] != '1' && get()->map[y
		- 1][x] == 'e')
		get()->map[y - 1][x] = 'a';
	else if (direction == 1 && get()->map[y - 1][x] != '1')
		get()->map[y - 1][x] = 'y';
	else if (direction == 2 && get()->map[y][x - 1] != '1' && get()->map[y][x
		- 1] == 'e')
		get()->map[y][x - 1] = 'a';
	else if (direction == 2 && get()->map[y][x - 1] != '1')
		get()->map[y][x - 1] = 'y';
	else if (direction == 3 && get()->map[y + 1][x] != '1' && get()->map[y
		+ 1][x] == 'e')
		get()->map[y + 1][x] = 'a';
	else if (direction == 3 && get()->map[y + 1][x] != '1')
		get()->map[y + 1][x] = 'y';
	else if (direction == 4 && get()->map[y][x + 1] != '1' && get()->map[y][x
		+ 1] == 'e')
		get()->map[y][x + 1] = 'a';
	else if (direction == 4 && get()->map[y][x + 1] != '1' && get()->map[y][x
		+ 1] != 'e')
		get()->map[y][x + 1] = 'y';
}

int	help_change_player(int direction, int x, int y)
{
	while (get()->map[y][x])
	{
		if ((get()->map[y][x] == 'y' || get()->map[y][x] == 'a')
			&& (get()->map[y][x + 1] != '1' || direction != 4)
			&& (get()->map[y][x - 1] != '1' || direction != 2) && (get()->map[y
				+ 1][x] != '1' || direction != 3) && (get()->map[y
				- 1][x] != '1' || direction != 1))
		{
			get()->moves++;
			end_game(direction, x, y);
			help_change_player2(direction, x, y);
			return (1);
		}
		x++;
	}
	return (0);
}

void	change_player(int direction)
{
	int	y;
	int	check;

	check = 0;
	y = 0;
	while (get()->map[y] && check == 0)
	{
		check = help_change_player(direction, 0, y);
		y++;
	}
}
