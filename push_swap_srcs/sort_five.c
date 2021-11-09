/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 16:13:52 by tamighi           #+#    #+#             */
/*   Updated: 2021/11/08 11:33:58 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a)
{
	int	x;

	while (a->next)
	{
		x = a->nb;
		if (a->next->nb < x)
			return (0);
		a = a->next;
	}
	return (1);
}

void	sort_three(t_stack *a, t_data *data)
{
	if (is_sorted(a))
		return ;
	if (a->nb < a->next->nb && a->nb < a->next->next->nb)
		swap_call(a, 0, data);
	if (a->nb > a->next->nb && a->nb > a->next->next->nb)
		rotate_call(a, 0, data);
	if (!is_sorted(a))
	{
		if (a->nb > a->next->nb)
			swap_call(a, 0, data);
		else
			rotate_reverse_call(a, 0, data);
	}
}

void	sort_new_element(t_stack **a, t_stack **b, t_data *data)
{
	int	i;

	if ((*b)->nb < (*a)->nb)
	{
		push_call(a, b, data, 'a');
		return ;
	}
	if ((*b)->nb < (*a)->next->nb)
	{
		push_call(a, b, data, 'a');
		swap_call(*a, 0, data);
		return ;
	}
	i = 1;
	while ((*b)->nb < last_nb(*a) && ++i)
		rotate_reverse_call(*a, 0, data);
	push_call(a, b, data, 'a');
	while (i--)
		rotate_call((*a), 0, data);
}

void	sort_five(t_stack **a, t_stack **b, t_data *data)
{
	if (is_sorted(*a))
		return ;
	while (data->count_a > 3)
		push_call(a, b, data, 'b');
	sort_three(*a, data);
	if (data->count_a + data->count_b == 3)
		return ;
	if ((*b)->next && (*b)->nb > (*b)->next->nb)
		swap_call(0, *b, data);
	while (data->count_b && data->count_a < 5)
		sort_new_element(a, b, data);
}
