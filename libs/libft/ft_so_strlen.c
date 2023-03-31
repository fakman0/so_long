/* ************************************************************************************** */
/*                                                                                        */
/*                                                                   :::      ::::::::    */
/*   ft_so_strlen.c                                                :+:      :+:    :+:    */
/*                                                               +:+ +:+         +:+      */
/*   By: fakman <fakman@student.42kocaeli.com.tr>              +#+  +:+       +#+         */
/*                                                           +#+#+#+#+#+   +#+            */
/*   Created: 2023/03/31 16:40:06 by fakman                       #+#    #+#              */
/*   Updated: 2023/03/31 16:40:06 by fakman                      ###   ########.tr        */
/*                                                                                        */
/* ************************************************************************************** */

#include "libft.h"

size_t	ft_so_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	return (i);
}