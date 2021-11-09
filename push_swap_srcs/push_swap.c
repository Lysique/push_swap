/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 12:27:36 by tamighi           #+#    #+#             */
/*   Updated: 2021/11/09 10:37:02 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_sorting(t_stack *a, t_stack *b, t_data *data)
{
	if (data->count_a == 2)
	{
		if (a->nb > a->next->nb)
			swap_call(a, 0, data);
		return ;
	}
	if (data->count_a <= 5)
		sort_five(&a, &b, data);
	else
		sort_more(&a, &b, data);
}

t_data	create_data_struct(int count)
{
	t_data	data;

	data.n_op = 0;
	data.count_a = count;
	data.count_b = 0;
	data.pos_a = 0;
	data.pos_b = 0;
	data.b_last = 0;
	data.b_biggest = 0;
	return (data);
}

void	push_swap(int argc, char **params)
{
	t_stack	*a;
	t_stack	*b;
	int		count;
	t_data	data;

	count = 0;
	a = get_stack(argc, params, &count);
	check_if_duplicates(a);
	if (count < 2)
	{
		free_stack(a);
		return ;
	}
	b = 0;
	data = create_data_struct(count);
	algo_sorting(a, b, &data);
	free_stack(a);
}
