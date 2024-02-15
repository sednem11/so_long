/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cordinates.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macampos <macampos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:43:09 by macampos          #+#    #+#             */
/*   Updated: 2024/02/15 20:53:05 by macampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	player_cordinates()
{
	char *temp;

	get()->j = 0;
	while (get()->j < get()->map_y)
	{
		get()->i = 0;
		temp = get()->map[get()->j];
		while (get()->i < get()->map_x)
		{
			if (temp[get()->i] == 'P')
			{
				get()->px = get()->i;
				get()->py = get()->j;
			}
			get()->i++;
		}
		get()->j++;
	}
}
