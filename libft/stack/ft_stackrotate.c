/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackrotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:01:22 by nminotte          #+#    #+#             */
/*   Updated: 2022/12/07 11:38:44 by nminotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	ft_stackrot_a(t_stack **stack)
{
	t_stack	*first;
	int		last;

	first = *stack;
	last = first->content;
	while (first->next)
	{
		first->content = first->next->content;
		first = first->next;
	}
	first->content = last;
	ft_putendl_fd("ra", 1);
}

void	ft_stackrot_b(t_stack **stack)
{
	t_stack	*first;
	int		last;

	first = *stack;
	last = first->content;
	while (first->next)
	{
		first->content = first->next->content;
		first = first->next;
	}
	first->content = last;
	ft_putendl_fd("rb", 1);
}

void	ft_stackrot_rr(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*first;
	int		last;
	t_stack	*first_b;
	int		last_b;

	first = *stack_a;
	last = first->content;
	while (first->next)
	{
		first->content = first->next->content;
		first = first->next;
	}
	first->content = last;
	first_b = *stack_b;
	last_b = first_b->content;
	while (first->next)
	{
		first->content = first->next->content;
		first = first->next;
	}
	first->content = last;
	ft_putendl_fd("rr", 1);
}
