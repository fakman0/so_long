/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakman <fakman@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 13:41:46 by fakman            #+#    #+#             */
/*   Updated: 2023/04/02 00:52:43 by fakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



int	*p_axis(char **map, int y, int x)
{
	int	*ret;

	ret = malloc(sizeof(int) * 2);
	while (map[y])
	{
		x = 0;
		while (map[y][x] && map[y][x] != 'P')
			x++;
		if (map[y][x] == 'P')
			break ;
		else
			y++;
	}
	ret[0] = y;
	ret[1] = x;
	return (ret);
}

int	param_count(char **map)
{
	int	counter;
	int	i;
	int	j;

	i = 0;
	counter = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E' || map[i][j] == 'C')
				counter++;
			j++;
		}
		i++;
	}
	return (counter);
}

int	recursive(char **map, int y, int x)
{
	map[y][x] = '1';
	if (map[y - 1][x] == '0' || map[y - 1][x] == 'C' || map[y - 1][x] == 'E')
		recursive(map, y - 1, x);
	if (map[y][x + 1] == '0' || map[y][x + 1] == 'C' || map[y][x + 1] == 'E')
		recursive(map, y, x + 1);
	if (map[y + 1][x] == '0' || map[y + 1][x] == 'C' || map[y + 1][x] == 'E')
		recursive(map, y + 1, x);
	if (map[y][x - 1] == '0' || map[y][x - 1] == 'C' || map[y][x - 1] == 'E')
		recursive(map, y, x - 1);
	if (param_count(map) == 0)
		return (1);
	else
		return (0);
}

int	main(int argc, char **argv)
{
	char	**map;
	t_data	*data;

	data = malloc(sizeof(t_data) * 1);
	map = read_map(argv[1]);
	controls(argc, argv);
	if (!recursive(map, p_axis(map, 0, 0)[0], p_axis(map, 0, 0)[1]))
		exit(ft_printf("map is impossible."));
	get_variables(argv[1], data);
	put_image(data, 0, 0);
	mlx_loop(data->m_p);
	return (0);
}
