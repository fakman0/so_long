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
	if (fd <= 0)
		exit(ft_printf("An incorrect file was entered."));
	str = get_next_line(fd);
	while (str != NULL)
	{
		i = 0;
		while(str[i])
		{
			if(str[i] != 'p' && str[i] != 'e' && str[i] != 'c' && str[i] != '1' && str[i] != '0' && str[i] != '\n')
				return (0);
			i++;
		}
		str = get_next_line(fd);
	}
	close(fd);
	fd = open(name, O_RDONLY);
	if(item_count(fd));
	return (1);
}

int item_count(int fd)
{
	char	*str;
	int		i;
	int		p;
	int		e;
	int		c;

	p = 0;
	e = 0;
	c = 0;
	if (fd <= 0)
		exit(ft_printf("an incorrect file was entered!"));
	str = get_next_line(fd);
	while (str != NULL)
	{
		i = 0;
		while(str[i])
		{
			if(str[i] == 'p')
				p++;
			if(str[i] == 'e')
				e++;
			if(str[i] == 'c')
				c++;
			i++;
		}
		str = get_next_line(fd);
	}
	if (p == 1 && e == 1 && c >= 1)
		return (1);
	exit(ft_printf("the number of parameters is wrong!"));
}