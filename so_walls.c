/* ************************************************************************************** */
/*                                                                                        */
/*                                                                   :::      ::::::::    */
/*   so_walls.c                                                    :+:      :+:    :+:    */
/*                                                               +:+ +:+         +:+      */
/*   By: fakman <fakman@student.42kocaeli.com.tr>              +#+  +:+       +#+         */
/*                                                           +#+#+#+#+#+   +#+            */
/*   Created: 2023/03/31 17:19:37 by fakman                       #+#    #+#              */
/*   Updated: 2023/03/31 17:19:37 by fakman                      ###   ########.tr        */
/*                                                                                        */
/* ************************************************************************************** */

#include "so_long.h"

void wall_control(int fd, int x, int y)
{
    int i;
    int rep_y;
    char *str;

    rep_y = 1;
    str = get_next_line(fd);
    while (str != NULL)
    {
        i = 0;
        while (str[i])
        {
            if(((rep_y == 1 && str[i] != '1') || (rep_y == y && str[i] != '1')) && str[i] != '\n')
                exit(ft_printf("the map wall is missing."));
            if((rep_y != 1 && rep_y != y) && (str[0] != '1' || str[x - 1] != '1'))
                exit(ft_printf("the map wall is missing."));
            i++;
        }
        rep_y++;
        str = get_next_line(fd);
    }
    close(fd);
}