/* ************************************************************************************** */
/*                                                                                        */
/*                                                                   :::      ::::::::    */
/*   so_controls.c                                                 :+:      :+:    :+:    */
/*                                                               +:+ +:+         +:+      */
/*   By: fakman <fakman@student.42kocaeli.com.tr>              +#+  +:+       +#+         */
/*                                                           +#+#+#+#+#+   +#+            */
/*   Created: 0003/03/23 15:52:10 by man                          #+#    #+#              */
/*   Updated: 2023/03/31 15:26:07 by fakman                      ###   ########.tr        */
/*                                                                                        */
/* ************************************************************************************** */

#include "so_long.h"

void controls(int argc, char **argv)
{
	if (argc < 2)
		exit(ft_printf("you entered few arguments"));
	if (!correct_ber(argv[1]))
		exit(ft_printf("the extension of this file is not '.ber'!"));
	if (!map_items(argv[1]))
		exit(ft_printf("The map has a different argument!"));
	map_axis(argv[1]);
	ft_printf("basarili");
}

int	correct_ber(char *file)
{
	int	i;

	i = ft_so_strlen(file) - 1;
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
	item_count(fd, 0, 0, 0);
	return (1);
}

int item_count(int fd, int p, int e, int c)
{
	char	*str;
	int		i;

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
	close(fd);
	if (p == 1 && e == 1 && c >= 1)
		return (1);
	exit(ft_printf("the number of parameters is wrong!"));
}