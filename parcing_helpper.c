/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_helpper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macampos <mcamposmendes@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:49:43 by macampos          #+#    #+#             */
/*   Updated: 2024/02/08 22:23:00 by macampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_data	*get(void)
{
	static t_data	data;

	return (&data);
}

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
	while (temp[++i])
	{
		if (temp[i] != 1)
			return (-1);
	}
	free(temp);
	i = 2;
	while (i != y)
	{
		temp = get_next_line(fd);
		if (temp[1] != 1 || temp[x] != 1)
			return (-1);
		free (temp);
		i++;
	}
	i = -1;
	temp = get_next_line(fd);
	while (temp[++i])
	{
		if (temp[i] != 1)
			return (-1);
	}
	return (0);
}

int	player_colectable_exit(int fd)
{
	char	*temp;

	get()->player = 0;
	get()->colectable = 0;
	get()->exit = 0;
	get()->i = 0;
	while (1)
	{
		temp = get_next_line(fd);
		if (!temp)
			break ;
		while (temp[get()->i])
		{
			if (temp[get()->i] == 'P')
				get()->player++;
			if (temp[get()->i] == 'C')
				get()->colectable++;
			if (temp[get()->i] == 'E')
				get()->exit++;
			get()->i++;
		}
		free(temp);
	}
	if (get()->player != 1 || get()->exit != 1)
		return (-1);
	return(0);
}

void	floodfill(char **map, int x, int y)
{
	map[get()->py][get()->px] = 'y';
	if (map[y][x] == '1' || map[y][x]
		|| map[y][x] == 'e' || map[y][x] == 'c'
		|| map[y][x] == 'p' || map[y][x] == 'y'
		|| y < 0 || y >= get()->map_y || x < 0
		|| x >= get()->map_x)
		return ;
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
	floodfill(map, (x + 1), y);
	floodfill(map, (x - 1), y);
	floodfill(map, x, (y + 1));
	floodfill(map, x, (y - 1));
}
