/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:42:49 by nminotte          #+#    #+#             */
/*   Updated: 2022/10/06 15:24:59 by nminotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_convert.h"

static void	ft_changeint(int n, int count, char *str)
{	
	int	i;

	i = 0;
	str[count] = '\0';
	count -= 1;
	if (n < 0)
	{
		str[i] = '-';
		n = -n;
		i++;
	}
	while (count >= i)
	{
		if (n > 0)
		{
			str[count] = (n % 10) + '0';
			n = n / 10;
		}	
		count--;
	}
}

static int	ft_count(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		count;

	if (n == -2147483648)
	{
		str = ft_strdup("-2147483648");
		return (str);
	}
	if (n == 0)
	{
		str = malloc(sizeof(char) * 2);
		if (!str)
			return (0);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	count = ft_count(n);
	str = malloc(sizeof(char) * (count + 1));
	if (!str)
		return (0);
	ft_changeint(n, count, str);
	return (str);
}
