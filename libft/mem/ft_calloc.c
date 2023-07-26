/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 12:31:44 by nminotte          #+#    #+#             */
/*   Updated: 2022/10/11 19:50:37 by nminotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tab;

	if (nmemb == 0 || size == 0)
	{
		tab = malloc(0);
		if (!tab)
			return (NULL);
		return (tab);
	}
	if (((nmemb * size) / size) != nmemb || size > 2147483647)
		return (0);
	tab = malloc(nmemb * size);
	if (!tab)
		return (0);
	ft_bzero(tab, (nmemb * size));
	return (tab);
}
