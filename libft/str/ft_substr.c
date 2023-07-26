/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 18:40:44 by nminotte          #+#    #+#             */
/*   Updated: 2022/10/04 11:44:27 by nminotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

static char	*ft_replace(char const *s, int start, size_t len, char *dest)
{
	size_t	i;

	i = 0;
	while (s[start] != '\0' && i < len)
	{
		dest[i] = s[start];
		i++;
		start++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	len_s;

	if (!s)
		return (0);
	len_s = ft_strlen(s);
	if (start >= len_s)
		dest = ft_strdup("");
	else if (len + start > len_s)
	{
		dest = malloc(sizeof(char) * (len_s - start + 1));
		if (!dest)
			return (0);
		ft_replace(s, start, len, dest);
	}
	else
	{
		dest = malloc(sizeof(char) * (len + 1));
		if (!dest)
			return (0);
		ft_replace(s, start, len, dest);
	}
	return (dest);
}
