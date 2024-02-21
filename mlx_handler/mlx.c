/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macampos <macampos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:52:03 by macampos          #+#    #+#             */
/*   Updated: 2024/02/20 18:58:36 by macampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	movement()
{
	while(get()->w != get()->s && get()->a != get()->d)
	{
		if(get()->w == 1)
			ft_printf("W\n");
		if(get()->s == 1)
			ft_printf("S\n");
		if(get()->a == 1)
			ft_printf("A\n");
		if(get()->d == 1)
			ft_printf("D\n");
	}
		
}
int		handel_input2(int keysym, t_data *get())
{
	if (keysym == XK_w)
	{
		get()->w = 0;
		ft_printf("%d\n", get()->w);
	}
	if (keysym == XK_a)
	{
		get()->a = 0;
	}
	if (keysym == XK_s)
	{
		get()->s = 0;
	}
	if (keysym == XK_d)
	{
		get()->d = 0;
	}
	return(1);
}

int		handel_input(int keysym, t_data *get())
{
	if (keysym == XK_Escape)
	{
		ft_printf("you have pressed (ESC)\n");
		mlx_end();
		return(0);
	}
	if (keysym == XK_w)
	{
		get()->w = 1;
		ft_printf("%d\n", get()->w);
	}
	if (keysym == XK_a)
	{
		get()->a = 1;
	}
	if (keysym == XK_s)
	{
		get()->s = 1;
	}
	if (keysym == XK_d)
	{
		get()->d = 1;
	}
	return(1);
}

void	mlx_start()
{
	get()->mlx = mlx_init();
	get()->window = mlx_new_window(get()->mlx, 700, 700, "so_long");
	mlx_key_hook(get()->window, handel_input2, get);
	mlx_hook(get()->window, 2, (1L<<0), handel_input, get);
	movement();
	mlx_loop(get()->mlx);
}      