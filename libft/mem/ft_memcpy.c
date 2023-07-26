/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 15:19:19 by nminotte          #+#    #+#             */
/*   Updated: 2022/10/05 12:18:02 by nminotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_mem.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dst;
	unsigned char	*s;

	i = 0;
	dst = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (!s && !dst)
		return (0);
	while (i < n)
	{
		dst[i] = s[i];
		i++;
	}
	return (dest);
}
