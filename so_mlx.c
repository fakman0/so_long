/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakman <fakman@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 21:08:53 by fakman            #+#    #+#             */
/*   Updated: 2023/04/06 17:29:41 by fakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_variables(char *name, t_data *var)
{
	int	fd;
	int	x;
	int	y;
	int	w;

	w = 50;
	fd = open(name, O_RDONLY);
	x = map_x(fd);
	close(fd);
	fd = open(name, O_RDONLY);
	y = map_y(fd);
	var->name = name;
	var->map = read_map(name);
	var->m_p = mlx_init();
	var->w_p = mlx_new_window(var->m_p, x * 50, y * 50, "God Of War 2D");
	var->px_p = p_axis(var->map, 0, 0);
	var->ex_p = e_axis(var->map, 0, 0);
	var->p_p = mlx_xpm_file_to_image(var->m_p, "tx/kratos.xpm", &w, &w);
	var->b_p = mlx_xpm_file_to_image(var->m_p, "tx/bground.xpm", &w, &w);
	var->v_p = mlx_xpm_file_to_image(var->m_p, "tx/wall.xpm", &w, &w);
	var->c_p = mlx_xpm_file_to_image(var->m_p, "tx/collectible.xpm", &w, &w);
	var->e_p = mlx_xpm_file_to_image(var->m_p, "tx/exit.xpm", &w, &w);
	var->c_count = 0;
	var->step = 0;
}

void	put_image(t_data *d, int i, int j)
{
	int	x;
	int	y;

	while (d->map[i])
	{
		y = i * 50;
		j = 0;
		while (d->map[i][j] != '\0')
		{
			x = j * 50;
			if (d->map[i][j] == '1')
				mlx_put_image_to_window(d->m_p, d->w_p, d->v_p, x, y);
			else if (d->map[i][j] == '0')
				mlx_put_image_to_window(d->m_p, d->w_p, d->b_p, x, y);
			else if (d->map[i][j] == 'C')
				mlx_put_image_to_window(d->m_p, d->w_p, d->c_p, x, y);
			else if (d->map[i][j] == 'E')
				mlx_put_image_to_window(d->m_p, d->w_p, d->e_p, x, y);
			else if (d->map[i][j] == 'P')
				mlx_put_image_to_window(d->m_p, d->w_p, d->p_p, x, y);
			j++;
		}
		i++;
	}
}
