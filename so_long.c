/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macampos <mcamposmendes@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 18:47:13 by macampos          #+#    #+#             */
/*   Updated: 2024/02/05 16:51:44 by macampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_data *get(void)
{
	static t_data data;
	return(&data);
}

int	check_if_squared(int fd, int x)
{
	char	*temp;

	temp = NULL;
	while(1)
	{
		temp = get_next_line(fd);
		if(!temp)
			return(0);
		if(x != ft_strlen(temp))
			return(-1);
		if(x != get()->map_y)
			return(-1);
		free(temp);
	}
}

int	check_walls(int fd, int y, int x)
{
	char	*temp;
	int		i;
	int		x;

	x = 0;
	i = -1;
	temp = get_next_line(fd);
	while (temp[++i])
	{
		if(temp[i] != 1)
			return(-1);
	}
	free(temp);
	i = 2;
	while(i != y)
	{
		temp = get_next_line(fd);
		if(temp[1] != 1 || temp[x] != 1)
			return(-1);
		free(temp);
		i++;
	}
	i = -1;
	temp = get_next_line(fd);
	while (temp[++i])
	{
		if(temp[i] != 1)
			return(-1);
	}
	return(0);
}

int		player_colectable_exit(int fd)
{
	char	*temp;
	
	get()->player == 0;
	get()->colectable == 0;
	get()->exit == 0;
	get()->i = 0;
	while(1)
	{
		temp = get_next_line(fd);
		if (!temp)
			break;
		while(temp[get()->i])
		{
			if (temp[get()->i] == "P")
				get()->player++;
			if (temp[get()->i] == "C")
				get()->colectable++;
			if (temp[get()->i] == "E")
				get()->exit++;
			get()->i++;
		}
		free(temp);
	}
	if (get()->player != 1 || get()->exit != 1)
		return(-1);
}

void	parsing(int fd, char *av)
{
	get_xy(fd);
	get()->i = ft_strlen(av);
	if(ft_strnstr(av[get()->i - 4], ".ber", 4) != 0)
	{
		perror("map is not .ber");
		exit(1);
	}
	if (check_if_squared(fd, get()->map_x) == -1)
	{
		perror("map is not squared");
		exit(1);
	}
	if (check_walls(fd, get()->map_y, get()->map_x) == -1);
	{
		perror("map doesnt have all walls");
		exit(1);
	}
	if (player_colectable_exit(fd) == -1)
	{
		perror("to many exits/players");
		exit(1);
	}
}


// void	parsing(void)
// {
// 	//checar a proporcao de pce;
// 	//ver se o mapa e quadrado 
// 	//ver se o mapa e .ber
// 	//ver se o mapa tem saida (floodfill)
// 	//se for verdade passa.
// }

int	main(int argc, char **argv)
{

	if (argc == 2)
	get_xy(open(argv[1], O_RDONLY));
	//save map();
	//parsing();
	
	//iniciar os componentes do mlx
	//funcao de printar o mapa no terminal
	//funcaos dos movimentos
	//funcoa de terminar o jogo
	//inicia a parte grafica e troca a funcao de printar o mapa pela do mlx
	

}