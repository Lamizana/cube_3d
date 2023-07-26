/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 16:06:37 by nminotte          #+#    #+#             */
/*   Updated: 2022/11/30 16:27:33 by nminotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putaddress(unsigned long long ptr)
{
	int	len;

	len = 0;
	if (!ptr)
	{
		len += ft_putstr_fd("(nil)", 1);
		return (len);
	}	
	len += ft_putstr_fd("0x", 1);
	len += ft_putbase(ptr, "0123456789abcdef");
	return (len);
}
