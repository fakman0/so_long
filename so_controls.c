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

int	map_items(char *name)
{
	int		fd;
	char	*str;
	int		i;

	fd = open(name, O_RDONLY);
	i = 0;
	str = get_next_line(fd);
	while (str != NULL)
	{
		while(str[i])
		{
			if(str[i] == 'p' || str[i] == 'e' || str[i] == 'c' || str[i] == '1' || str[i] == '0' || str[i] == '\n' )
			{
				i++;
				continue;
			}
			return (0);
		}
		str = get_next_line(fd);
	}
	return (1);
}