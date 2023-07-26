/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:54:46 by nminotte          #+#    #+#             */
/*   Updated: 2023/01/19 11:40:59 by nminotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

static long	ft_numberint(char *str, long value, int i)
{
	while ((str[i] >= '0' && str[i] <= '9')
		|| (str[i] >= 'A' && str[i] <= 'F')
		|| (str[i] >= 'a' && str[i] <= 'f'))
	{
		if (str[i] >= 'A' && str[i] <= 'F')
			str[i] = str[i] - 7;
		if (str[i] >= 'a' && str[i] <= 'f')
			str[i] = str[i] - 39;
		value = value * 16 + (str[i] - 48);
		if (value > 21474836478)
		{
			return (0);
		}
		i++;
	}
	return (value);
}

int	ft_atoi_color(char *str)
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
	if (str[i] == '0')
		i++;
	if (str[i] == 'x')
		i++;
	value = ft_numberint(str, value, i);
	value = value * sign;
	return (value);
}
