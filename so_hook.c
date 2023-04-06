/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakman <fakman@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 13:26:44 by fakman            #+#    #+#             */
/*   Updated: 2023/04/06 17:51:42 by fakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keycode(int keycode, t_data *d)
{
	int	y;
	int	x;

	y = d->px_p[0];
	x = d->px_p[1];
	if ((keycode == 119 || keycode == 13) && d->map[y - 1][x] != '1')
		move(d, --d->px_p[0], d->px_p[1] , 'W');
	else if ((keycode == 100 || keycode == 2) && d->map[y][x + 1] != '1')
		move(d, d->px_p[0], ++d->px_p[1], 'D');
	else if ((keycode == 115 || keycode == 1) && d->map[y + 1][x] != '1')
		move(d, ++d->px_p[0], d->px_p[1], 'S');
	else if ((keycode == 97 || keycode == 0) && d->map[y][x - 1] != '1')
		move(d, d->px_p[0], --d->px_p[1], 'A');
	else if (keycode == 53 || keycode == 65307)
		exit(ft_printf("You have exited the game."));
	return (1);
}

void	up_map(t_data *d, char dir)
{
	int	y;
	int	x;

	y = d->px_p[0];
	x = d->px_p[1];
	if (dir == 'W')
	{
		d->map[y + 1][x] = '0';
		d->map[y][x] = 'P';
	}
	else if (dir == 'D')
	{
		d->map[y][x - 1] = '0';
		d->map[y][x] = 'P';
	}
	else if (dir == 'S')
	{
		d->map[y - 1][x] = '0';
		d->map[y][x] = 'P';
	}
	else if (dir == 'A')
	{
		d->map[y][x + 1] = '0';
		d->map[y][x] = 'P';
	}
}


int	move(t_data *d, int y, int x, char dir)
{
	if (d->map[y][x] == 'C')
		d->c_count++;
	ft_printf("\n coin: %d", d->c_count);
	up_map(d, dir);
	put_image(d, 0, 0);
	d->step++;
	ft_printf("%d", d->step);
	return (0);
}