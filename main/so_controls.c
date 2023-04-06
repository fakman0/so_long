/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_controls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakman <fakman@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 14:19:30 by fakman            #+#    #+#             */
/*   Updated: 2023/04/06 21:36:21 by fakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	controls(int argc, char **argv)
{
	if (argc < 2)
		exit(ft_printf("Error\nyou entered few arguments"));
	if (!correct_ber(argv[1]))
		exit(ft_printf("Error\nthe extension of this file is not '.ber'!"));
	if (!map_items(argv[1]))
		exit(ft_printf("Error\nThe map has a different argument!"));
	map_axis(argv[1]);
}

char	**read_map(char *name)
{
	int			fd;
	size_t		i;
	size_t		y;
	char		**str;

	fd = open(name, O_RDONLY);
	i = 0;
	y = map_y(fd);
	close(fd);
	fd = open(name, O_RDONLY);
	str = malloc(sizeof(char *) * (y + 1));
	str[i] = get_next_line(fd);
	while (str[i] != NULL)
	{
		i++;
		str[i] = get_next_line(fd);
	}
	return (str);
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
		exit(ft_printf("Error\nAn incorrect file was entered."));
	str = get_next_line(fd);
	while (str != NULL)
	{
		i = 0;
		while (str[i])
		{
			if (str[i] != 'P' && str[i] != 'E' && str[i] != 'C' && str[i] != '1'
				&& str[i] != '0' && str[i] != '\n')
				return (0);
			i++;
		}
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	fd = open(name, O_RDONLY);
	item_count(fd, 0, 0, 0);
	return (1);
}

int	item_count(int fd, int p, int e, int c)
{
	char	*str;
	int		i;

	str = get_next_line(fd);
	while (str != NULL)
	{
		i = 0;
		while (str[i])
		{
			if (str[i] == 'P')
				p++;
			if (str[i] == 'E')
				e++;
			if (str[i] == 'C')
				c++;
			i++;
		}
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	close(fd);
	if (p == 1 && e == 1 && c >= 1)
		return (1);
	exit(ft_printf("Error\nthe number of parameters is wrong!"));
}
