/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macampos <macampos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 18:47:13 by macampos          #+#    #+#             */
/*   Updated: 2024/02/16 23:11:25 by macampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
	check_if_squared();
	if (player_colectable_exit() == -1)
	{
		perror("to many or none exits/players");
		exit(1);
	}
	player_cordinates();
	floodfill(get()->map, get()->px, get()->py);
	if (get()->c != get()->colectable || get()->e != get()->exit)
		exit(1);
}

void print_map(char **map)
{
	int i;

	i = 0;
	while (map[i])
		ft_printf("%s", map[i++]);
	printf("\n");
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return 0;
	get_xy(open(argv[1], O_RDONLY));
	map(open(argv[1], O_RDONLY));
	print_map(get()->map);
	parsing(open(argv[1], O_RDONLY), argv[1]);
	mlx_start();
	//funcao de printar o mapa no terminal
	//funcaos dos movimentos
	//funcoa de terminar o jogo
	//inicia a parte grafica e troca a funcao de printar o mapa pela do mlx
}
