/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakman <fakman@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 21:08:53 by fakman            #+#    #+#             */
/*   Updated: 2023/04/06 21:30:10 by fakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
