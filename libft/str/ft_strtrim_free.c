/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:49:45 by nminotte          #+#    #+#             */
/*   Updated: 2023/07/28 11:55:21 by nminotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

static size_t	ft_first_oc(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	match;

	i = 0;
	match = 0;
	while (s1[i] != '\0' && match == 0)
	{
		j = 0;
		while (set[j] != '\0' && match == 0)
		{
			if (set[j] == s1[i])
			{
				match = 1;
				j = 0;
			}
			else
				j++;
		}
		match = 0;
		if (set[j] == '\0')
			match = 1;
		i++;
	}
	return (i);
}

static size_t	ft_last_oc(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	match;

	i = ft_strlen(s1);
	match = 0;
	while (i > 0 && match == 0)
	{
		i--;
		j = 0;
		while (set[j] != '\0' && match == 0)
		{
			if (set[j] == s1[i])
			{
				match = 1;
				j = 0;
			}
			else
				j++;
		}
		match = 0;
		if (set[j] == '\0')
				match = 1;
	}
	return (i);
}

char	*ft_strtrim_free(char **s1, char const *set)
{
	char	*dest;
	size_t	first;
	size_t	last;

	if (!s1 || !*s1)
		return (0);
	first = ft_first_oc(*s1, set) - 1;
	if (first + 1 == ft_strlen(*s1))
	{
		dest = ft_strdup("");
		return (dest);
	}
	last = ft_last_oc(*s1, set) + 1;
	last -= first;
	dest = ft_substr(*s1, first, last);
	free(*s1);
	return (dest);
}
