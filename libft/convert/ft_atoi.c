/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:54:46 by nminotte          #+#    #+#             */
/*   Updated: 2022/12/14 12:01:38 by nminotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

static long	ft_numberint(const char *str, long value, int i)
{
	while (str[i] >= '0' && str[i] <= '9')
	{
		value = value * 10 + (str[i] - 48);
		if (value > 2147483649)
		{
			value = 2147483649;
			break ;
		}
		i++;
	}
	return (value);
}

long	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	value;

	i = 0;
	sign = 1;
	value = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	value = ft_numberint(str, value, i);
	value = value * sign;
	return (value);
}
