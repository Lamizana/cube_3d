/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr_pipex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:10:07 by nminotte          #+#    #+#             */
/*   Updated: 2023/02/14 12:11:50 by nminotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_str.h"

char	*ft_strrchr_pipex(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	c = c % 256;
	while (i > 0)
	{
		if (s[i] == c)
			return ((char *)&s[i + 1]);
		i--;
	}
	if (s[i] == c)
		return ((char *)&s[i]);
	return ((char *)&s[0]);
}
