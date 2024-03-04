/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macampos <macampos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:17:10 by macampos          #+#    #+#             */
/*   Updated: 2024/03/04 19:32:19 by macampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	map(int fd)
{
	char	*temp;
	int		j;

	j = 0;
	(get())->map = (char **)ft_calloc((get())->map_y + 1, sizeof(char *));
	temp = get_next_line(fd);
	while (j < get()->map_y && temp)
	{
		(get())->map[j] = ft_strtrim(temp, "\n ");
		j++;
		free(temp);
		temp = get_next_line(fd);
	}
	get()->map[get()->map_y] = NULL;
	free(temp);
}
