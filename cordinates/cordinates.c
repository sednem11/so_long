/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cordinates.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macampos <mcamposmendes@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:43:09 by macampos          #+#    #+#             */
/*   Updated: 2024/03/01 12:11:52 by macampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	player_cordinates(void)
{
	char	*temp;

	get()->j = 0;
	while (get()->j < get()->map_y)
	{
		get()->i = 0;
		temp = get()->map[get()->j];
		while (get()->i < get()->map_x)
		{
			if (temp[get()->i] == 'P' || temp[get()->i] == 'y'
				|| temp[get()->i] == 'a')
			{
				get()->px = get()->i;
				get()->py = get()->j;
			}
			get()->i++;
		}
		get()->j++;
	}
}
