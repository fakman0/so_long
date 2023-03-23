/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_controls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakman <fakman@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:57:35 by fakman            #+#    #+#             */
/*   Updated: 2023/03/23 15:52:10 by fakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	correct_ber(char *file)
{
	int	i;

	i = ft_strlen(file) - 1;
	if (file[i--] == 'r')
		if (file[i--] == 'e')
			if (file[i--] == 'b')
				if (file[i] == '.')
					return (1);
	return (0);
}

int	map_items(char *str)
{
	int		fd;
	char	*str;
	int i;

	i = 0;
	fd = open("maps/test_map1", O_RDONLY);
	str = get_next_line(fd);
	while(str[i] ==)
}