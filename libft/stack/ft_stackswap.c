/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackswap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:32:27 by nminotte          #+#    #+#             */
/*   Updated: 2022/12/19 16:53:13 by nminotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	ft_stackswap_a(t_stack *stack)
{
	int	tmp;

	tmp = stack->next->content;
	stack->next->content = stack->content;
	stack->content = tmp;
	ft_putendl_fd("sa", 1);
}

void	ft_stackswap_b(t_stack *stack)
{
	int	tmp;

	tmp = stack->next->content;
	stack->next->content = stack->content;
	stack->content = tmp;
	ft_putendl_fd("sb", 1);
}

void	ft_stackswap_ss(t_stack *stack_a, t_stack *stack_b)
{
	int	tmp_a;
	int	tmp_b;

	tmp_a = stack_a->next->content;
	stack_a->next->content = stack_a->content;
	stack_a->content = tmp_a;
	tmp_b = stack_b->next->content;
	stack_b->next->content = stack_b->content;
	stack_b->content = tmp_b;
	ft_putendl_fd("ss", 1);
}
