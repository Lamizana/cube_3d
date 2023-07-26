/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 02:05:04 by nminotte          #+#    #+#             */
/*   Updated: 2022/11/30 16:31:28 by nminotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putendl_fd(char *s, int fd)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (s)
	{
		while (s[i] != '\0')
		{
			count += ft_putchar_fd(s[i], fd);
			i++;
		}
		count += ft_putchar_fd('\n', fd);
	}
	return (count);
}
