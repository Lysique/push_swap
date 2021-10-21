/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 16:13:52 by tamighi           #+#    #+#             */
/*   Updated: 2021/10/19 16:49:50 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *a, t_data *data)
{
	if (is_sorted(a))
		return ;
	if (a->nb < a->next->nb && a->nb < a->next->next->nb)
		swap_stack(a, data);
	if (a->nb > a->next->nb && a->nb > a->next->next->nb)
		rotate_stack(a, data);
	if (!is_sorted(a))
	{
		if (a->nb > a->next->nb)
			swap_stack(a, data);
		else
			rotate_reverse_stack(a, data);
	}
}

int	last_nb(t_stack *a)
{
	t_stack *addr;

	addr = a;
	while (addr->next)
		addr = addr->next;
	return (addr->nb);
}

void	sort_new_element(t_stack *a, t_data *data)
{
	int	x;

	x = a->nb;
	if (is_sorted(a))
		return ;
	if (x < a->next->next->nb)
	{
		swap_stack(a, data);
		return ;
	}
	if (x < last_nb(a))
	{
		rotate_reverse_stack(a, data);
		swap_stack(a, data);
		sort_new_element(a, data);
	}
	rotate_stack(a, data);
}

void	sort_five(t_stack **a, t_stack **b, t_data *data)
{
	int	i;

	i = 3;
	while (data->count > i)
	{
		push_stack(a, b, data);
		i++;
	}
	sort_three(*a, data);
	if (data->count == 3)
		return ;
	if ((*b)->next && (*b)->nb > (*b)->next->nb)
		swap_stack(*b, data);
	while (i > 3)
	{
		push_stack(b, a, data);
		sort_new_element(*a, data);
		i--;
	}
}
