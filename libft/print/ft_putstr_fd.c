/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 18:32:06 by nminotte          #+#    #+#             */
/*   Updated: 2022/11/30 16:34:58 by nminotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
	{
		i = ft_putstr_fd("(null)", 2);
		return (i);
	}
	if (fd > 0 && s)
	{
		while (s[i] != '\0')
			i += ft_putchar_fd(s[i], fd);
	}
	return (i);
}
