/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 15:51:19 by tamighi           #+#    #+#             */
/*   Updated: 2021/11/03 15:02:50 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	order_b_stack(t_stack *b, t_data *data)
{
	int		i;
	t_stack	*addr;

	i = 0;
	addr = b;
	data->b_biggest = biggest_nb(b);
	while (addr->nb != data->b_biggest && ++i)
		addr = addr->next;
	while (i && i != data->count_b)
	{
		if (i <= data->count_b / 2)
		{
			i--;
			rotate_call(0, b, data);
		}
		else
		{
			i++;
			rotate_reverse_call(0, b, data);
		}
	}
}

void	push_to_a(t_stack **a, t_stack **b, t_data *data)
{
	int	nb;
	int	i;

	i = 5;
	order_b_stack(*b, data);
	nb = last_nb(*a);
	while (data->count_b || i)
	{
		if (!i)
			push_call(a, b, data, 'a');
		else if ((*b) && (*b)->nb > nb)
			push_call(a, b, data, 'a');
		else
		{
			rotate_reverse_call(*a, 0, data);
			nb = last_nb(*a);
			i--;
		}
	}
}

void	best_push_rotations(t_stack *a, t_stack *b, t_data *data)
{
	while (data->pos_a > 0 && data->pos_b > 0)
	{
		data->pos_a--;
		data->pos_b--;
		rotate_call(a, b, data);
	}
	while (data->pos_a < 0 && data->pos_b < 0)
	{
		data->pos_a++;
		data->pos_b++;
		rotate_reverse_call(a, b, data);
	}
	while (data->pos_a-- > 0)
		rotate_call(a, 0, data);
	while (data->pos_b-- > 0)
		rotate_call(0, b, data);
	while (data->pos_a++ < -1)
		rotate_reverse_call(a, 0, data);
	while (data->pos_b++ < -1)
		rotate_reverse_call(0, b, data);
}

void	push_to_b(t_stack **a, t_stack **b, t_data *data)
{
	find_best_push(*a, *b, data, 0);
	best_push_rotations(*a, *b, data);
	push_call(a, b, data, 'b');
}

void	sort_more(t_stack **a, t_stack **b, t_data *data)
{
	while (data->count_a > 5)
		push_to_b(a, b, data);
	sort_five(a, b, data);
	if (data->count_b > 0)
		push_to_a(a, b, data);
}
