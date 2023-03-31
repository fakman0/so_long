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

int map_y(int fd)
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

int map_x(int fd)
{
    int x;
    char *str;

    str = get_next_line(fd);
    x = ft_strlen(str) - 1;
    while (str != NULL)
    {
        if (x != (ft_strlen(str) - 1))
            exit(ft_printf("the x-axis is not equal."));
        str = get_next_line(fd);
    }
    close(fd);
    if (x < 3)
        exit(ft_printf("x-axis is less than 3"));
    return (x);
}

int map_axis(char *name)
{
    int x;
    int y;
    int fd;

    fd = open(name, O_RDONLY);
    x = map_x(fd);
    fd = open(name, O_RDONLY);
    y = map_y(fd);
    if (y == 3 || y == 4)
        if(x < 5)
            exit(ft_printf("the map is too small."));
    if (x == 3 || x == 4)
        if (y < 5)
            exit(ft_printf("the map is too small."));
    return (1);
}