/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_find.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakman <fakman@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 20:46:42 by fakman            #+#    #+#             */
/*   Updated: 2023/04/06 21:01:15 by fakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	recursive(char **map, int y, int x)
{
	map[y][x] = '1';
	if (map[y - 1][x] == '0' || map[y - 1][x] == 'C')
		recursive(map, y - 1, x);
	if (map[y][x + 1] == '0' || map[y][x + 1] == 'C')
		recursive(map, y, x + 1);
	if (map[y + 1][x] == '0' || map[y + 1][x] == 'C')
		recursive(map, y + 1, x);
	if (map[y][x - 1] == '0' || map[y][x - 1] == 'C')
		recursive(map, y, x - 1);
	if (param_count(map) == 0)
		return (1);
	else
		return (0);
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
			if (map[i][j] == 'C')
				counter++;
			j++;
		}
		i++;
	}
	return (counter);
}
