/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:24:28 by nminotte          #+#    #+#             */
/*   Updated: 2022/11/30 16:17:34 by nminotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putnbr_fd(int n, int fd)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		count = ft_putstr_fd("-2147483648", fd);
	}
	else if (n < 0)
	{
		count += ft_putchar_fd('-', fd);
		count += ft_putnbr_fd(-n, fd);
	}
	else if (n > 9)
	{
		count += ft_putnbr_fd((n / 10), fd);
		count += ft_putchar_fd((n % 10 + '0'), fd);
	}
	else
	{
		count += ft_putchar_fd((n + '0'), fd);
	}
	return (count);
}
