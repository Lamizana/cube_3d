/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackfind.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:45:46 by nminotte          #+#    #+#             */
/*   Updated: 2022/12/13 20:19:29 by nminotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

int	ft_stackfind(t_stack *stk, int tofind)
{
	while (stk)
	{
		if (stk->content == tofind)
			return (1);
		stk = stk->next;
	}
	return (0);
}
