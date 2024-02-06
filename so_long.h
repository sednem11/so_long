/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macampos <mcamposmendes@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 18:48:24 by macampos          #+#    #+#             */
/*   Updated: 2024/02/05 16:40:38 by macampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SO_LONG_H
#define	SO_LONG_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct	data
{
	int		map_y;
	int		map_x;
	int		player;
	int		colectable;
	int		exit;
	int		i;
}	t_data;

void	get_xy(int fd);

#endif