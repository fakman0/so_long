/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakman <fakman@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:43:02 by fakman            #+#    #+#             */
/*   Updated: 2023/03/23 14:43:03 by fakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_find_digit(int n)
{
	int	digit;

	digit = 0;
	while (n > 0)
	{
		n = n / 10;
		digit++;
	}
	return (digit);
}

static char	*ft_neg_itoa(int n)
{
	char	*result;
	int		i;
	int		j;
	int		pos;

	pos = (n * -1);
	j = ft_find_digit(pos) + 1;
	i = ft_find_digit(pos);
	result = (char *)malloc(sizeof(char) * (ft_find_digit(pos) + 2));
	if (!result)
		return (NULL);
	while (i != -1)
	{
		result[i] = (pos % 10) + 48;
		pos /= 10;
		i--;
	}
	result[j] = '\0';
	result[0] = '-';
	return (result);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		i;
	int		j;

	j = ft_find_digit(n);
	i = ft_find_digit(n) - 1;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == -0)
		return (ft_strdup("0"));
	if (n < 0)
		return (ft_neg_itoa(n));
	result = (char *)malloc(sizeof(char) * (ft_find_digit(n) + 1));
	if (!result)
		return (NULL);
	while (i != -1)
	{
		result[i] = (n % 10) + 48;
		n /= 10;
		i--;
	}
	result[j] = '\0';
	return (result);
}
