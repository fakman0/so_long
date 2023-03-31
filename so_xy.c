/* ************************************************************************************** */
/*                                                                                        */
/*                                                                   :::      ::::::::    */
/*   so_xy.c                                                       :+:      :+:    :+:    */
/*                                                               +:+ +:+         +:+      */
/*   By: fakman <fakman@student.42kocaeli.com.tr>              +#+  +:+       +#+         */
/*                                                           +#+#+#+#+#+   +#+            */
/*   Created: 2023/03/31 15:22:20 by fakman                       #+#    #+#              */
/*   Updated: 2023/03/31 15:22:20 by fakman                      ###   ########.tr        */
/*                                                                                        */
/* ************************************************************************************** */

#include "so_long.h"

size_t map_y(int fd)
{
    int y;
    char *str;

    if (fd <= 0)
        exit(ft_printf("An incorrect file was entered."));
    y = 0;
    str = get_next_line(fd);
    while (str != NULL)
    {
        y++;
        str = get_next_line(fd);
    }
    close(fd);
    if (y < 3)
        exit(ft_printf("y-axis is less than 3"));
    return (y);
}

size_t map_x(int fd)
{
    size_t x;
    char *str;
    if (fd <= 0)
		exit(ft_printf("An incorrect file was entered."));
    str = get_next_line(fd);
    x = ft_so_strlen(str);
    while (str != NULL)
    {
        if (x != ft_so_strlen(str))
            exit(ft_printf("the x-axis is not equal."));
        str = get_next_line(fd);
    }
    if (x < 3)
        exit(ft_printf("x-axis is less than 3"));
    return (x);
}

void map_axis(char *name)
{
    size_t x;
    size_t y;
    int fd;
    fd = open(name, O_RDONLY);
    x = map_x(fd);
    close(fd);
    fd = open(name, O_RDONLY);
    y = map_y(fd);
    close(fd);
    if (y == 3)
        if(x < 5)
            exit(ft_printf("the map is too small."));
    if (x == 3)
        if (y < 5)
            exit(ft_printf("the map is too small."));
}