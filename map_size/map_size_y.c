/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size_y.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macampos <mcamposmendes@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 19:00:28 by macampos          #+#    #+#             */
/*   Updated: 2024/02/05 14:47:40 by macampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_data *get(void)
{
	static t_data data;
	return(&data);
}

void	get_xy(int fd)
{
	int		i;
	char	*temp;

	i = 0;
	temp = NULL;
	while(1)
	{
		temp = get_next_line(fd);
		if (!temp)
			break;
		get()->map_x = ft_strlen(temp);
		free(temp);
		i++;
	}
	get()->map_y = i;
}
