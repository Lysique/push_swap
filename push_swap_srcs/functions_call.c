/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_call.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 14:58:20 by tamighi           #+#    #+#             */
/*   Updated: 2021/11/03 15:22:50 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_call(t_stack *a, t_stack *b, t_data *data)
{
	data->n_op++;
	if (b)
		data->b_last = b->nb;
	if (!b)
	{
		rotate_stack(a);
		write(1, "ra\n", 3);
	}	
	else if (!a)
	{
		rotate_stack(b);
		write(1, "rb\n", 3);
	}
	else
	{
		rotate_stack(a);
		rotate_stack(b);
		write(1, "rr\n", 3);
	}
}

void	rotate_reverse_call(t_stack *a, t_stack *b, t_data *data)
{
	data->n_op++;
	if (!b)
	{
		rotate_reverse_stack(a);
		write(1, "rra\n", 4);
	}	
	else if (!a)
	{
		rotate_reverse_stack(b);
		write(1, "rrb\n", 4);
	}
	else
	{
		rotate_reverse_stack(a);
		rotate_reverse_stack(b);
		write(1, "rrr\n", 4);
	}
	if (b)
		data->b_last = last_nb(b);
}

void	swap_call(t_stack *a, t_stack *b, t_data *data)
{
	data->n_op++;
	if (b && data->count_b == 2)
		data->b_last = b->nb;
	if (!b)
	{
		swap_stack(a);
		write(1, "sa\n", 3);
	}	
	else if (!a)
	{
		swap_stack(b);
		write(1, "sb\n", 3);
	}
	else
	{
		swap_stack(a);
		swap_stack(b);
		write(1, "sr\n", 3);
	}
}

void	push_call(t_stack **a, t_stack **b, t_data *data, char c)
{
	data->n_op++;
	if (c == 'a')
	{
		push_stack(b, a);
		write(1, "pa\n", 3);
		data->count_a++;
		data->count_b--;
	}
	else if (c == 'b')
	{
		if (!*b)
		{
			data->b_last = (*a)->nb;
			data->b_biggest = (*a)->nb;
		}
		else if ((*a)->nb > data->b_biggest)
			data->b_biggest = (*a)->nb;
		push_stack(a, b);
		write(1, "pb\n", 3);
		data->count_a--;
		data->count_b++;
	}
}
