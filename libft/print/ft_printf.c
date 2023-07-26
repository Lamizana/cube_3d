/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:46:29 by nminotte          #+#    #+#             */
/*   Updated: 2022/11/30 16:25:56 by nminotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_which(char elem, va_list arg)
{
	int	count;

	count = 0;
	if (elem == 'c')
		count += ft_putchar_fd(((char)va_arg(arg, int)), 1);
	else if (elem == 's')
		count += ft_putstr_fd((va_arg(arg, char *)), 1);
	else if (elem == 'p')
		count += ft_putaddress(va_arg(arg, unsigned long long));
	else if (elem == 'd' || elem == 'i')
		count += ft_putnbr_fd(va_arg(arg, int), 1);
	else if (elem == 'u')
		count += ft_putnbr_u(va_arg(arg, unsigned int));
	else if (elem == 'X')
		count += ft_putbase(va_arg(arg, unsigned int), "0123456789ABCDEF");
	else if (elem == 'x')
		count += ft_putbase(va_arg(arg, unsigned int), "0123456789abcdef");
	else if (elem == '%')
		count += ft_putchar_fd('%', 1);
	else
	{
		count += ft_putchar_fd('%', 1);
		count += ft_putchar_fd(((char)elem), 1);
	}
	return (count);
}

static int	ft_loopwrite(const char *src, va_list arg)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (src[i] != '\0')
	{
		while (src[i] != '%' && src[i])
		{
			count += ft_putchar_fd(((char)src[i]), 1);
			i++;
		}
		if (src[i] == '%' && src[i + 1] != '\0')
		{
			i++;
			count += ft_which(src[i], arg);
			i++;
		}
		else if (src[i + 1] == '\0' && src[i] == '%')
		{
			count += ft_putchar_fd(((char)src[i]), 1);
			return (count);
		}
	}
	return (count);
}

int	ft_printf(const char *src, ...)
{
	int		count;
	va_list	param_ptr;

	if (!src)
		return (0);
	va_start (param_ptr, src);
	count = 0;
	count = ft_loopwrite(src, param_ptr);
	va_end (param_ptr);
	return (count);
}
