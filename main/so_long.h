/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakman <fakman@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 14:18:46 by fakman            #+#    #+#             */
/*   Updated: 2023/04/06 21:16:00 by fakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include "../libs/libft/libft.h"
# include "../libs/minilibx/mlx.h"

//struct
typedef struct s_data
{
	char	**map;
	void	*m_p;
	void	*w_p;
	int		*px_p;
	int		*ex_p;
	void	*p_p;
	void	*b_p;
	void	*v_p;
	void	*c_p;
	void	*e_p;
	int		step;
	int		c_count;
}				t_data;

//so_axis
int		*p_axis(char **map, int y, int x);
int		*e_axis(char **map, int y, int x);
size_t	map_y(int fd);
size_t	map_x(int fd);
void	map_axis(char *name);
//so_walls
void	wall_control(int fd, int x, int y);
//so_hook
int		keycode(int keycode, t_data *d);
int		open_exit(t_data *d);
void	up_map(t_data *d, char dir);
int		move(t_data *d, int y, int x, char dir);
//so_controls
void	controls(int argc, char **argv);
char	**read_map(char *name);
int		correct_ber(char *file);
int		map_items(char *name);
int		item_count(int fd, int p, int e, int c);
//put_image
void	put_image(t_data *d, int i, int j);
//path_find
int		recursive(char **map, int y, int x);
int		param_count(char **map);
//init
void	get_variables(char *name, t_data *var);
#endif
