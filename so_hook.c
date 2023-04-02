/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakman <fakman@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 13:26:44 by fakman            #+#    #+#             */
/*   Updated: 2023/04/02 14:20:45 by fakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keycode(int keycode, t_data *data)
{
	if (keycode == 119 || keycode == 13)
		move(data, data->px_p[0] - 1, data->px_p[1]);
	else if (keycode == 100 || keycode == 2)
		move(data, data->px_p[0], data->px_p[1] + 1);
	else if (keycode == 115 || keycode == 1)
		move(data, data->px_p[0] + 1, data->px_p[1]);
	else if (keycode == 97 || keycode == 0)
		move(data, data->px_p[0], data->px_p[1] - 1);
	else if (keycode == 53 || keycode == 65307)
		exit(ft_printf("You have exited the game."));
	return (ft_printf("%d", data->step));
}

void	move(t_data *d,int y,int x)
{
	int	old_x;
	int	old_y;

	
	old_x = d->px_p[0] * 50;
	old_y = d->px_p[1] * 50;
	y = y * 50;
	x = x * 50;
	mlx_put_image_to_window(d->m_p, d->w_p, d->b_p, d->px_p[0], d->px_p[1]);
	mlx_put_image_to_window(d->m_p, d->w_p, d->b_p, old_y, old_x);
	d->step++;
}