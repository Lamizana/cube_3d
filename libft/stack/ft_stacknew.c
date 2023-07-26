/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacknew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:53:16 by nminotte          #+#    #+#             */
/*   Updated: 2022/12/12 13:46:39 by nminotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_stack.h"

t_stack	*ft_stacknew(int content)
{
	t_stack	*stacknew;

	stacknew = malloc(sizeof(t_stack));
	if (stacknew)
	{
		stacknew->content = content;
		stacknew->next = NULL;
		stacknew->prev = NULL;
		return (stacknew);
	}
	return (0);
}
