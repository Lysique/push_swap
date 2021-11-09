/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:11:56 by tamighi           #+#    #+#             */
/*   Updated: 2021/11/03 15:28:44 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_stack(t_stack **from, t_stack **to)
{
	t_stack	*addr;

	addr = *to;
	*to = *from;
	*from = (*from)->next;
	(*to)->next = addr;
}

void	rotate_reverse_stack(t_stack *stack)
{
	t_stack	*addr;
	int		x;

	addr = stack;
	if (!addr->next)
		return ;
	while (addr->next)
	{
		x = (stack)->nb;
		addr = addr->next;
		(stack)->nb = addr->nb;
		addr->nb = x;
	}
}

void	rotate_stack(t_stack *stack)
{
	t_stack	*addr;
	int		x;

	addr = stack;
	if (!addr->next)
		return ;
	x = addr->nb;
	while (addr->next)
	{
		addr->nb = addr->next->nb;
		addr->next->nb = x;
		addr = addr->next;
	}
}

void	swap_stack(t_stack *stack)
{
	int	x;

	if (!stack->next)
		return ;
	x = stack->nb;
	stack->nb = stack->next->nb;
	stack->next->nb = x;
}
