/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:54:53 by nminotte          #+#    #+#             */
/*   Updated: 2022/10/05 18:36:06 by nminotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_str.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len_dest;
	size_t	len_src;
	size_t	len_sum;
	size_t	i;

	if ((!dest || !src) && size == 0)
		return (0);
	i = 0;
	len_src = ft_strlen(src);
	len_dest = ft_strlen(dest);
	len_sum = len_dest + len_src;
	if (len_dest > size || size == 0)
		return (size + len_src);
	while (src[i] != '\0' && (len_dest + i) < (size - 1))
	{
		dest[len_dest + i] = src[i];
		i++;
	}
	dest[len_dest + i] = '\0';
	return (len_sum);
}
