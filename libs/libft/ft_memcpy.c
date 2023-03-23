/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakman <fakman@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:44:18 by fakman            #+#    #+#             */
/*   Updated: 2023/03/23 14:44:19 by fakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*ret;

	if (!dest && !src)
		return (NULL);
	if (dest == src)
		return (dest);
	ret = dest;
	while (n--)
		*((unsigned char *)dest++) = *((unsigned char *)src++);
	return (ret);
}
