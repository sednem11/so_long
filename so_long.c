/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macampos <macampos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 18:47:13 by macampos          #+#    #+#             */
/*   Updated: 2024/02/06 14:50:29 by macampos         ###   ########.fr       */
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
	get_xy(fd);
	get()->i = ft_strlen(av);
	if (ft_strnstr(av[get()->i - 4], ".ber", 4) != 0)
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
	
	//iniciar os componentes do mlx
	//funcao de printar o mapa no terminal
	//funcaos dos movimentos
	//funcoa de terminar o jogo
	//inicia a parte grafica e troca a funcao de printar o mapa pela do mlx
}