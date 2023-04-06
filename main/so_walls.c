/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_walls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakman <fakman@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 14:17:38 by fakman            #+#    #+#             */
/*   Updated: 2023/04/06 21:36:30 by fakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	wall_control(int fd, int x, int y)
{
	int		i;
	int		rep_y;
	char	*str;

	rep_y = 1;
	str = get_next_line(fd);
	while (str != NULL)
	{
		i = 0;
		while (str[i])
		{
			if (((rep_y == 1 && str[i] != '1') || (rep_y == y && str[i] != '1'))
				&& str[i] != '\n')
				exit(ft_printf("Error\nthe map wall is missing."));
			if ((rep_y != 1 && rep_y != y)
				&& (str[0] != '1' || str[x - 1] != '1'))
				exit(ft_printf("Error\nthe map wall is missing."));
			i++;
		}
		rep_y++;
		free(str);
		str = get_next_line(fd);
	}
}
