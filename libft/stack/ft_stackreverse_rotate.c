/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackreverse_rotate.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:58:12 by nminotte          #+#    #+#             */
/*   Updated: 2022/12/19 17:18:21 by nminotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_stack.h"

void	ft_stackrrot_a(t_stack **stack)
{
	t_stack	*stack_tmp;
	int		tmp;

	stack_tmp = *stack;
	stack_tmp = ft_stacklast(*stack);
	tmp = stack_tmp->content;
	while (stack_tmp->prev)
	{
		stack_tmp->content = stack_tmp->prev->content;
		stack_tmp = stack_tmp->prev;
	}
	stack_tmp->content = tmp;
	ft_putendl_fd("rra", 1);
}

void	ft_stackrrot_b(t_stack **stack)
{
	t_stack	*stack_tmp;
	int		tmp;

	stack_tmp = *stack;
	stack_tmp = ft_stacklast(*stack);
	tmp = stack_tmp->content;
	while (stack_tmp->prev)
	{
		stack_tmp->content = stack_tmp->prev->content;
		stack_tmp = stack_tmp->prev;
	}
	stack_tmp->content = tmp;
	ft_putendl_fd("rrb", 1);
}

void	ft_stackrrot_rr(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*stack_tmp;
	int		tmp;

	stack_tmp = *stack_a;
	stack_tmp = ft_stacklast(*stack_a);
	tmp = stack_tmp->content;
	while (stack_tmp->prev)
	{
		stack_tmp->content = stack_tmp->prev->content;
		stack_tmp = stack_tmp->prev;
	}
	stack_tmp->content = tmp;
	stack_tmp = *stack_b;
	stack_tmp = ft_stacklast(*stack_b);
	tmp = stack_tmp->content;
	while (stack_tmp->prev)
	{
		stack_tmp->content = stack_tmp->prev->content;
		stack_tmp = stack_tmp->prev;
	}
	stack_tmp->content = tmp;
	ft_putendl_fd("rrr", 1);
}
