/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:59:27 by nminotte          #+#    #+#             */
/*   Updated: 2023/05/03 16:25:22 by nminotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_str.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		cmp;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
		{
			cmp = (unsigned char)s1[i] - (unsigned char)s2[i];
			return (cmp);
		}
		i++;
	}
	return (0);
}
