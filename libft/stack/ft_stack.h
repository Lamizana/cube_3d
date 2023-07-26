/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:05:44 by nminotte          #+#    #+#             */
/*   Updated: 2022/12/19 11:14:17 by nminotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_H
# define FT_STACK_H

# include "../libft.h"

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

t_stack	*ft_stacknew(int content);
t_stack	*ft_stacklast(t_stack *stack);
t_stack	*ft_stackfirst(t_stack *stack);
t_stack	*ft_push_a(t_stack **stack_a, t_stack **stack_b);
t_stack	*ft_push_b(t_stack **stack_a, t_stack **stack_b);

void	ft_putstack(t_stack **stack, int new);
void	ft_push(t_stack **stack, int new);
void	ft_stackadd_front(t_stack *stack, t_stack *new);
void	ft_stackdelone(t_stack *stack);
void	ft_stackswap_a(t_stack *stack);
void	ft_stackswap_b(t_stack *stack);
void	ft_stackswap_ss(t_stack *stack_a, t_stack *stack_b);
void	ft_stackrrot_a(t_stack **stack);
void	ft_stackrrot_b(t_stack **stack);
void	ft_stackrrot_rr(t_stack **stack_a, t_stack **stack_b);
void	ft_stackrot_a(t_stack **stack);
void	ft_stackrot_b(t_stack **stack);
void	ft_stackrot_rr(t_stack **stack_a, t_stack **stack_b);
void	ft_stackclear(t_stack **stack);

int		ft_stacksize(t_stack *stack);
int		ft_stackfind(t_stack *stk, int tofind);

#endif
