/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macampos <mcamposmendes@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:52:03 by macampos          #+#    #+#             */
/*   Updated: 2024/02/21 21:03:14 by macampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	movement()
{
	if (movementt()->w != movementt()->s || movementt()->a != movementt()->d)
	{
		if(movementt()->w == 1)
			ft_printf("W\n");
		if(movementt()->s == 1)
			ft_printf("S\n");
		if(movementt()->a == 1)
			ft_printf("A\n");
		if(movementt()->d == 1)
			ft_printf("D\n");
	}
		
}
int		handel_input2(int keysym)
{
	if (keysym == XK_w)
	{
		movementt()->w = 0;
		ft_printf("%d\n", movementt()->w);
	}
	if (keysym == XK_a)
	{
		movementt()->a = 0;
	}
	if (keysym == XK_s)
	{
		movementt()->s = 0;
	}
	if (keysym == XK_d)
	{
		movementt()->d = 0;
		ft_printf("%d\n", get()->d);
	}
	return(1);
}

int		handel_input(int keysym)
{
	if (keysym == XK_Escape)
	{
		ft_printf("you have pressed (ESC)\n");
		mlx_end();
		return(0);
	}
	if (keysym == XK_w)
	{
		movementt()->w = 1;
		ft_printf("%d\n", movementt()->w);
	}
	if (keysym == XK_a)
	{
		movementt()->a = 1;
	}
	if (keysym == XK_s)
	{
		movementt()->s = 1;
	}
	if (keysym == XK_d)
	{
		movementt()->d = 1;
		ft_printf("%d\n", movementt()->d);
	}
	return(1);
}

void	mlx_start()
{
	get()->mlx = mlx_init();
	mlx_do_key_autorepeatoff(get()->mlx);
	get()->window = mlx_new_window(get()->mlx, 1000, 1000, "so_long");
	mlx_hook(get()->window, 2, (1L<<0), handel_input, NULL);
	mlx_key_hook(get()->window, handel_input2, NULL);
	mlx_loop(get()->mlx);
}