/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macampos <mcamposmendes@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 18:47:13 by macampos          #+#    #+#             */
/*   Updated: 2024/02/13 17:29:04 by macampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_data	*get(void)
{
	static t_data	data;

	return (&data);
}

void	parsing(int fd, char *av)
{
	const char *avv;

	get_xy(fd);
	get()->i = 0;
	while (av[get()->i] != '.')
	{
		get()->i++;
		*av = av[get()->i];
	}
	avv = av;
	if (ft_strnstr(avv, ".ber", 4) != 0)
	{
		perror("map is not .ber");
		exit(1);
	}
	if (check_if_squared(fd, get()->map_x) == -1)
	{
		perror("map is not squared");
		exit(1);
	}
	if (check_walls(fd, get()->map_y, get()->map_x) == -1)
	{
		perror("map doesnt have all walls");
		exit(1);
	}
	if (player_colectable_exit(fd) == -1)
	{
		perror("to many exits/players");
		exit(1);
	}
	floodfill(get()->map, get()->px, get()->py);
	if (get()->c != get()->colectable || get()->e != get()->exit)
		exit(1);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	get_xy(open(argv[1], O_RDONLY));
	map(open(argv[1], O_RDONLY));
	parsing(open(argv[1], O_RDONLY), argv[1]);
	mlx_start();
	//funcao de printar o mapa no terminal
	//funcaos dos movimentos
	//funcoa de terminar o jogo
	//inicia a parte grafica e troca a funcao de printar o mapa pela do mlx
}
