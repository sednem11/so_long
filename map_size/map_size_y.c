/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size_y.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macampos <macampos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 19:00:28 by macampos          #+#    #+#             */
/*   Updated: 2024/02/14 17:01:09 by macampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	get_xy(int fd)
{
	int		i;
	char	*temp;

	i = 0;
	while (1)
	{
		temp = get_next_line(fd);
		if (!temp)
			break ;
		get()->map_x = ft_strlen(temp);
		free (temp);
		i++;
	}
	get()->map_y = i;
}
