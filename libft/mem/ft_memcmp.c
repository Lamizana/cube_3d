/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 11:58:59 by nminotte          #+#    #+#             */
/*   Updated: 2022/09/30 12:25:47 by nminotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_mem.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	i = 0;
	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	while (i < n)
	{
		if (ptr1[i] < ptr2[i] || ptr1[i] > ptr2[i])
			return ((int)(ptr1[i]) - ptr2[i]);
		i++;
	}
	return (0);
}
