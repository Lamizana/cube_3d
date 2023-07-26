/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 18:53:06 by nminotte          #+#    #+#             */
/*   Updated: 2022/11/30 16:28:25 by nminotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putbase(unsigned long long n, char *base)
{
	unsigned long long	len;
	int					count;

	count = 0;
	if (!base)
		return (count);
	len = ft_strlen (base);
	if (n > (len - 1))
	{
		count += ft_putbase((n / len), base);
		count += ft_putchar_fd((base[n % len]), 1);
	}
	else
		count += ft_putchar_fd((base[n % len]), 1);
	return (count);
}
