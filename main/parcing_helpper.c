/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_helpper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macampos <macampos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:49:43 by macampos          #+#    #+#             */
/*   Updated: 2024/02/15 21:05:52 by macampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_if_squared(int fd, int x)
{
	char	*temp;

	temp = NULL;
	while (1)
	{
		temp = get_next_line(fd);
		if (!temp)
			return (0);
		if (x != (int)ft_strlen(temp))
			return (-1);
		free(temp);
	}
}

int	check_walls(int fd, int y, int x)
{
	char	*temp;
	int		i;

	i = -1;
	temp = get_next_line(fd);
	while (temp && temp[++i])
	{
		if (temp[i] != '1')
			return (-1);
	}
	free(temp);
	i = 1;
	while (temp && ++i != y)
	{
		temp = get_next_line(fd);
		if (temp[0] != '1' || temp[x] != '1')
			return (-1);
		free (temp);
	}
	i = -1;
	temp = get_next_line(fd);
	while (temp && temp[++i])
	{
		if (temp[i] != 1)
			return (-1);
	}
	return (0);
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
			ft_printf("%c", get()->map[get()->j][get()->i]);
			if (get()->map[get()->j][get()->i] == 'P')
				get()->player++;
			if (get()->map[get()->j][get()->i] == 'C')
				get()->colectable++;
			if (get()->map[get()->j][get()->i] == 'E')
				get()->exit++;
			get()->i++;
		}
		ft_printf("\n");
		get()->j++;
	}
	if (get()->player != 1 || get()->exit != 1)
		return (-1);
	return (0);
}

void	floodfill(char **map, int x, int y)
{
	ft_printf("%c\n", map[y][x]);
	if (map[y][x] == '1' || !map[y][x]
		|| map[y][x] == 'e' || map[y][x] == 'c'
		|| map[y][x] == 'p' || map[y][x] == 'y'
		|| y < 0 || y >= get()->map_y || x < 0
		|| x >= get()->map_x)
		return ;
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
	if(map[y][x] == '0')
		map[y][x] = '1';
	floodfill(map, (x + 1), y);
	floodfill(map, (x - 1), y);
	floodfill(map, x, (y + 1));
	floodfill(map, x, (y - 1));
}
