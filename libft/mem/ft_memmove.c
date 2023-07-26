/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 20:24:51 by nminotte          #+#    #+#             */
/*   Updated: 2022/10/05 14:44:32 by nminotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dst;
	unsigned char	*s;

	i = 0;
	dst = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (!dst && !s)
		return (0);
	if (s < dst)
	{
		while (n > 0)
		{
			n--;
			dst[n] = s[n];
		}
	}
	while (i < n)
	{
		dst[i] = s[i];
		i++;
	}
	return (dest);
}
