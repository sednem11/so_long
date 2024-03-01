/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_helpper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macampos <mcamposmendes@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:49:43 by macampos          #+#    #+#             */
/*   Updated: 2024/03/01 19:39:33 by macampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	player_colectable_exit2()
{
	get()->player2 = 0;
	get()->colectable2 = 0;
	get()->exit2 = 0;
	get()->j = 0;
	while (get()->j < get()->map_y)
	{
		get()->i = 0;
		while (get()->i < get()->map_x)
		{
			if (get()->map[get()->j][get()->i] == 'y' || get()->map[get()->j][get()->i] == 'a')
				get()->player2++;
			if (get()->map[get()->j][get()->i] == 'c')
				get()->colectable2++;
			if (get()->map[get()->j][get()->i] == 'e' ||
				get()->map[get()->j][get()->i] == 'a')
			{
				get()->ex = get()->i;
				get()->ey = get()->j;
				get()->exit2++;
			}
			get()->i++;
		}
		get()->j++;
	}
	return (0);
}

void	check_if_squared()
{
	int		i;

	i = 1;
	while (i < get()->map_y)
	{
		if ((int)ft_strlen(get()->map[i]) != (int)ft_strlen(get()->map[0]))
			exit(1);
		i++;
	}
}

int	player_colectable_exit()
{
	get()->player = 0;
	get()->colectable = 0;
	get()->exit = 0;
	get()->j = 0;
	while (get()->j < get()->map_y)
	{
		get()->i = 0;
		while (get()->i < get()->map_x)
		{
			if (get()->map[get()->j][get()->i] == 'P')
				get()->player++;
			if (get()->map[get()->j][get()->i] == 'C')
				get()->colectable++;
			if (get()->map[get()->j][get()->i] == 'E')
			{
				get()->ex = get()->i;
				get()->ey = get()->j;
				get()->exit++;
			}
			get()->i++;
		}
		get()->j++;
	}
	if (get()->player != 1 || get()->exit != 1)
		return (-1);
	return (0);
}

void	floodfill(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == '2'
		|| map[y][x] == 'e' || map[y][x] == 'c'
		|| map[y][x] == 'p' || map[y][x] == 'y' || map[y][x] == 'f')
		return ;
	if (y > get()->map_y || x > get()->map_x || y < 0 || x < 0)
		exit(1);
	map[get()->py][get()->px] = 'y';
	if (map[y][x] == 'C')
	{
		get()->c++;
		map[y][x] = 'c';
	}
	if (map[y][x] == 'E')
	{
		get()->e++;
		map[y][x] = 'e';
	}
	if (map[y][x] == 'F')
		map[y][x] = 'f';
	if(map[y][x] == '0')
		map[y][x] = '2';
	floodfill(map, (x + 1), y);
	floodfill(map, (x - 1), y);
	floodfill(map, x, (y + 1));
	floodfill(map, x, (y - 1));
}
