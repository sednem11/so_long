/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cordinates.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macampos <mcamposmendes@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:43:09 by macampos          #+#    #+#             */
/*   Updated: 2024/02/08 22:31:53 by macampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_data	*get(void)
{
	static t_data	data;

	return (&data);
}

void	player_cordinates(int fd)
{
	char	*temp;

	get()->i = 0;
	get()->j = 0;
	while (1)
	{
		temp = get_next_line(fd);
		if (!temp)
			break ;
		while (temp[get()->i])
		{
			if (temp[get()->i] == 'P')
			{
				get()->px = get()->i;
				get()->py = get()->j;
			}
		}
		get()->j++;
		free (temp);
	}
}
