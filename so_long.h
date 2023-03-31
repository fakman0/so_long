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
int controls(int argc, char **argv);
int	correct_ber(char *file);
int	map_items(char *name);
int item_count(int fd, int p, int e, int c);
int map_y(int fd);
int map_x(int fd);
int map_axis(char *name);

#endif