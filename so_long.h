/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakman <fakman@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:41:47 by fakman            #+#    #+#             */
/*   Updated: 2023/03/23 15:36:23 by fakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include "libs/libft/libft.h"
# include "libs/minilibx_opengl_20191021/mlx.h"

//controls
int	correct_ber(char *file);
int	map_items(char *name);

#endif