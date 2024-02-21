/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macampos <macampos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:17:10 by macampos          #+#    #+#             */
/*   Updated: 2024/02/20 15:45:23 by macampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	map(int fd)
{
	char	*temp;
	int j;

	j = 0;
	get()->map = (char **)ft_calloc(get()->map_y + 1, sizeof(char *));
	temp = get_next_line(fd);
	while(j < get()->map_y && temp)
	{
		get()->map[j] = ft_strtrim(temp, "\n ");
		j++;
		free(temp);
		temp = get_next_line(fd);
	}
	get()->map[get()->map_y] = NULL;
	free(temp);
}


/*

get()->map == {
	"11111111111",
	"10000000C01",
	"10P00000001",
	"10000000001",
	"10000000E01",
	"10000000001",
	"10000000001",
	"10000000001",
	"10000000001",
	"10000000001",
	"11111111111",
	NULL
}


*/