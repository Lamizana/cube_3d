/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:12:04 by nminotte          #+#    #+#             */
/*   Updated: 2022/12/21 14:07:07 by nminotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"
#include <stdlib.h>

void	ft_putstack(t_stack **stack, int new)
{
	t_stack	*tmp;
	t_stack	*tmps;

	tmp = *stack;
	tmps = *stack;
	if (!*stack)
	{
		*stack = ft_stacknew(new);
		return ;
	}
	tmp = ft_stacklast(tmp);
	tmps = ft_stacklast(tmps);
	tmp->next = ft_stacknew(new);
	ft_stacklast(tmp)->prev = tmps;
	return ;
}

t_stack	*ft_push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*stack_tmp;

	stack_tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	(*stack_a)->prev = NULL;
	if (!stack_b)
	{
		stack_tmp->next = NULL;
		stack_b = &stack_tmp;
	}
	else
	{
		stack_tmp->next = *stack_b;
		stack_b = &stack_tmp;
	}
	ft_putendl_fd("pb", 1);
	return (*stack_b);
}

t_stack	*ft_push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*stack_tmp;

	stack_tmp = *stack_b;
	if (!stack_b)
		return (NULL);
	if (!((*stack_b)->next))
	{
		stack_tmp->next = *stack_a;
		(*stack_a)->prev = stack_tmp;
		(*stack_a) = (*stack_a)->prev;
		(*stack_a)->prev = NULL;
		stack_b = NULL;
	}
	if (stack_b && (*stack_b)->next)
	{	
		*stack_b = (*stack_b)->next;
		(*stack_b)->prev = NULL;
		stack_tmp->next = *stack_a;
		(*stack_a)->prev = stack_tmp;
	}
	ft_putendl_fd("pa", 1);
	if (!stack_b)
		return (NULL);
	return (*stack_b);
}
