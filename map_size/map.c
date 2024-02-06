/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macampos <macampos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:17:10 by macampos          #+#    #+#             */
/*   Updated: 2024/02/06 14:46:11 by macampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_data	*get(void)
{
	static t_data	data;

	return (&data);
}

void	map(int fd)
{
	char	**temp;

	get()->j = 0;
	while (1)
	{
		temp[get()->j] = get_next_line(fd);
		get()->map[get()->j] = (char *)malloc(get()->map_x + 1);
		if (!temp[get()->j])
			break ;
		get()->j++;
	}
	get()->map = (char *)malloc(get()->j + 1);
}
