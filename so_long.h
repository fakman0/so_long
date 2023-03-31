/* ************************************************************************************** */
/*                                                                                        */
/*                                                                   :::      ::::::::    */
/*   so_long.h                                                     :+:      :+:    :+:    */
/*                                                               +:+ +:+         +:+      */
/*   By: fakman <fakman@student.42kocaeli.com.tr>              +#+  +:+       +#+         */
/*                                                           +#+#+#+#+#+   +#+            */
/*   Created: 0003/03/23 15:36:23 by man                          #+#    #+#              */
/*   Updated: 2023/03/31 15:23:40 by fakman                      ###   ########.tr        */
/*                                                                                        */
/* ************************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include "libs/libft/libft.h"
# include "libs/minilibx_opengl_20191021/mlx.h"

//controls
void controls(int argc, char **argv);
int	correct_ber(char *file);
int	map_items(char *name);
int item_count(int fd, int p, int e, int c);
size_t map_y(int fd);
size_t map_x(int fd);
void map_axis(char *name);
void wall_control(int fd, int x, int y);

#endif