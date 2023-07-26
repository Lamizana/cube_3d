/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:57:25 by nminotte          #+#    #+#             */
/*   Updated: 2022/11/26 13:23:52 by nminotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

static size_t	ft_countword(char const *s, char c)
{
	size_t	word;
	size_t	i;

	i = 0;
	word = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			word++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	return (word);
}

static size_t	ft_start(char const *s, char c, size_t index)
{
	size_t	i;
	size_t	start;

	i = index;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			start = i;
			return (start);
		}
	}
	return (0);
}

static size_t	ft_lenword(char const *s, char c, size_t index)
{
	size_t	i;
	size_t	len_w;

	i = index;
	while (s[i] != c && s[i] != '\0')
		i++;
	len_w = i - index;
	return (len_w);
}

static int	ft_free_all(char **dest)
{
	int	i;

	i = 0;
	while (dest[i] != 0)
	{
		free(dest[i]);
		i++;
	}
	free(dest);
	dest = NULL;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	index;
	size_t	word;
	size_t	len_w;
	char	**dest;

	i = 0;
	if (!s)
		return (0);
	word = ft_countword(s, c);
	dest = ft_calloc((word + 1), sizeof(char *));
	if (!dest)
		return (0);
	index = 0;
	while (i < word)
	{
		index = ft_start(s, c, index);
		len_w = ft_lenword(s, c, index);
		dest[i] = ft_substr(s, index, len_w);
		if (!dest[i])
			word = ft_free_all(dest);
		index = index + len_w;
		i++;
	}
	return (dest);
}
