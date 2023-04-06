/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakman <fakman@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 13:26:44 by fakman            #+#    #+#             */
/*   Updated: 2023/04/06 20:39:54 by fakman           ###   ########.fr       */
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
		move(d, d->px_p[0], d->px_p[1], 'W');
	else if ((keycode == 100 || keycode == 2) && d->map[y][x + 1] != '1')
		move(d, d->px_p[0], d->px_p[1], 'D');
	else if ((keycode == 115 || keycode == 1) && d->map[y + 1][x] != '1')
		move(d, d->px_p[0], d->px_p[1], 'S');
	else if ((keycode == 97 || keycode == 0) && d->map[y][x - 1] != '1')
		move(d, d->px_p[0], d->px_p[1], 'A');
	else if (keycode == 53 || keycode == 65307)
		exit(ft_printf("You have exited the game."));
	return (1);
}

int	open_exit(t_data *d)
{
	int	y;
	int	x;

	d->c_count = 0;
	y = 0;
	while (d->map[y])
	{
		x = 0;
		while (d->map[y][x])
		{
			if (d->map[y][x] == 'C')
				d->c_count++;
			x++;
		}
		y++;
	}
	if (d->c_count == 0)
		return (1);
	return (0);
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
	int	mv;
	int	*ext;

	ext = e_axis(d->map, 0, 0);
	mv = 1;
	if (dir == 'W' && (d->map[y - 1][x] != 'E' || open_exit(d)))
		--d->px_p[0];
	else if (dir == 'D' && (d->map[y][x + 1] != 'E' || open_exit(d)))
		++d->px_p[1];
	else if (dir == 'S' && (d->map[y + 1][x] != 'E' || open_exit(d)))
		++d->px_p[0];
	else if (dir == 'A' && (d->map[y][x - 1] != 'E' || open_exit(d)))
		--d->px_p[1];
	else
		mv = 0;
	if (mv == 0)
		return (0);
	up_map(d, dir);
	put_image(d, 0, 0);
	d->step++;
	if (ext[0] == p_axis(d->map, 0, 0)[0] && ext[1] == p_axis(d->map, 0, 0)[1])
		exit(ft_printf("You finished the game."));
	ft_printf("Move count: %d\n", d->step);
	return (0);
}
