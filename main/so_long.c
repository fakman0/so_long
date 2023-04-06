/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakman <fakman@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 13:41:46 by fakman            #+#    #+#             */
/*   Updated: 2023/04/06 21:36:36 by fakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_game(void)
{
	exit(write(1, "The game have been closed.", 32));
	return (1);
}

int	main(int argc, char **argv)
{
	char	**map;
	t_data	*data;
	int		*p_axs;

	data = malloc(sizeof(t_data) * 1);
	map = read_map(argv[1]);
	p_axs = p_axis(map, 0, 0);
	controls(argc, argv);
	if (!recursive(map, p_axs[0], p_axs[1]))
		exit(ft_printf("Error\nmap is impossible."));
	free(p_axs);
	get_variables(argv[1], data);
	put_image(data, 0, 0);
	mlx_key_hook(data->w_p, keycode, data);
	mlx_hook(data->w_p, 17, 0, close_game, data);
	mlx_loop(data->m_p);
	return (0);
}
