/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macampos <macampos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 18:47:13 by macampos          #+#    #+#             */
/*   Updated: 2024/02/05 14:33:17 by macampos         ###   ########.fr       */
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

int	check_flood(int fd, int y, int x)
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

void	get_xy(int fd)
{
	int		i;
	char	*temp;

	i = 0;
	temp = NULL;
	while(1)
	{
		temp = get_next_line(fd);
		if (!temp)
			break;
		get()->map_x = ft_strlen(temp);
		free(temp);
		i++;
	}
	get()->map_y = i;
}

int		parsing(int fd, char *av)
{
	get_xy(fd);
	get()->i = ft_strlen(av);
	if(ft_strnstr(av[get()->i - 4], ".ber", 4) != 0)
		return(-1);
	if (check_if_squared(fd, get()->map_x) == -1)
		return(-1);
	if (check_flood(fd, get()->map_y, get()->map_x) == -1);
		return(-1);
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