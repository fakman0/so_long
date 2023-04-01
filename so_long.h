/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakman <fakman@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 14:18:46 by fakman            #+#    #+#             */
/*   Updated: 2023/04/01 17:52:02 by fakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include "libs/libft/libft.h"
# include "libs/minilibx_opengl_20191021/mlx.h"

//controls
void	controls(int argc, char **argv);
int		correct_ber(char *file);
int		map_items(char *name);
int		item_count(int fd, int p, int e, int c);
size_t	map_y(int fd);
size_t	map_x(int fd);
void	map_axis(char *name);
void	wall_control(int fd, int x, int y);
char	**read_map(char *name);
int		recursive(char **map, int y, int x);
int		*p_axis(char **map, int i, int j);

#endif