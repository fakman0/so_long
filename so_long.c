/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakman <fakman@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 13:41:46 by fakman            #+#    #+#             */
/*   Updated: 2023/04/01 17:55:04 by fakman           ###   ########.fr       */
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
		while (map[y][x] && map[y][x] != 'p')
			x++;
		if (map[y][x] == 'p')
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
			if (map[i][j] == 'e' || map[i][j] == 'c')
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
	if (map[y - 1][x] == '0' || map[y - 1][x] == 'c' || map[y - 1][x] == 'e')
		recursive(map, y - 1, x);
	if (map[y][x + 1] == '0' || map[y][x + 1] == 'c' || map[y][x + 1] == 'e')
		recursive(map, y, x + 1);
	if (map[y + 1][x] == '0' || map[y + 1][x] == 'c' || map[y + 1][x] == 'e')
		recursive(map, y + 1, x);
	if (map[y][x - 1] == '0' || map[y][x - 1] == 'c' || map[y][x - 1] == 'e')
		recursive(map, y, x - 1);
	if (param_count(map) == 0)
		return (1);
	else
		return (0);
}

int	main(int argc, char **argv)
{
	int		fd;
	char	**map;

	controls(argc, argv);
	map = read_map(argv[1]);
	if (!recursive(map, p_axis(map, 0, 0)[0], p_axis(map, 0, 0)[1]))
		exit(ft_printf("map is impossible."));
	return(0);
}
