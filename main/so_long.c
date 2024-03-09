/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macampos <macampos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 18:47:13 by macampos          #+#    #+#             */
/*   Updated: 2024/03/08 18:22:54 by macampos         ###   ########.fr       */
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
	const char	*avv;

	get_xy(fd);
	get()->i = 0;
	while (av[get()->i] != '.')
	{
		get()->i++;
	}
	av = &av[get()->i];
	avv = av;
	if (ft_strncmp(avv, ".ber", 4) != 0)
	{
		perror("map is not .ber");
		end_before(0);
	}
	check_if_squared();
	if (player_colectable_exit() == -1)
	{
		perror("to many or none exits/players");
		end_before(0);
	}
	player_cordinates();
	floodfill(get()->map, get()->px, get()->py);
	if (get()->c != get()->colectable || get()->e != get()->exit)
		end_before(1);
}

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		ft_printf("%s\n", map[i++]);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	if (open(argv[1], O_RDONLY) == -1)
		return (0);
	get_xy(open(argv[1], O_RDONLY));
	map(open(argv[1], O_RDONLY));
	print_map(get()->map);
	parsing(open(argv[1], O_RDONLY), argv[1]);
	mlx_start();
}
