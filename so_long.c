/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakman <fakman@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:56:59 by fakman            #+#    #+#             */
/*   Updated: 2023/03/23 15:50:00 by fakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	if (argc < 2)
		exit(ft_printf("you entered few arguments"));
	if (!correct_ber(argv[1]))
		exit(ft_printf("the extension of this file is not '.ber'!"));
	if (!map_items(argv[1]))
		exit(ft_printf("The map has a different argument!"));
	ft_printf("basarili");
}
