/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 16:01:40 by tamighi           #+#    #+#             */
/*   Updated: 2021/11/03 15:24:34 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_b_end(t_stack *b, t_data *data, int moves)
{
	int		j;
	t_stack	*addr;

	j = 0;
	addr = b;
	while ((j <= data->count_b - moves - 1 || j < data->count_b / 2) && ++j)
		addr = addr->next;
	while (j < data->count_b - 1)
	{
		if (push_conditions(addr->nb, data, addr->next->nb, j))
		{
			data->pos_b = (j - data->count_b + 1);
			return (1);
		}
		addr = addr->next;
		j++;
	}	
	if (moves && push_conditions(addr->nb, data, b->nb, j))
	{
		data->pos_b = j - data->count_b;
		return (1);
	}
	return (0);
}

int	check_b_beginning(t_stack *b, t_data *data, int moves)
{
	int		j;
	t_stack	*addr;

	if (push_conditions(data->b_last, data, b->nb, 0))
	{
		data->pos_b = 0;
		return (1);
	}
	j = 1;
	addr = b;
	while (j <= moves && j <= data->count_b / 2)
	{
		if (push_conditions(addr->nb, data, addr->next->nb, j))
		{
			data->pos_b = j;
			return (1);
		}
		addr = addr->next;
		j++;
	}
	return (0);
}

int	check_a_end(t_stack *a, t_stack *b, t_data *data, int moves)
{	
	int		i;
	t_stack	*addr;

	i = 1;
	addr = a;
	while (i <= data->count_a - moves && ++i)
		addr = addr->next;
	while (i <= data->count_a)
	{
		data->nb = addr->nb;
		if (check_b_beginning(b, data, moves - i)
			|| check_b_end(b, data, moves))
		{
			data->pos_a = i - data->count_a - 1;
			return (1);
		}
		addr = addr->next;
		i++;
	}
	return (0);
}

int	check_a_begining(t_stack *a, t_stack *b, t_data *data, int moves)
{
	int		i;
	t_stack	*addr;

	i = 0;
	addr = a;
	if (!b || !b->next)
		return (1);
	while (i <= moves && i <= data->count_a / 2)
	{
		data->nb = addr->nb;
		if (check_b_beginning(b, data, moves)
			|| check_b_end(b, data, moves - i))
		{
			data->pos_a = i;
			return (1);
		}
		addr = addr->next;
		i++;
	}
	return (0);
}

void	find_best_push(t_stack *a, t_stack *b, t_data *data, int moves)
{
	if (check_a_begining(a, b, data, moves))
		return ;
	else if (check_a_end(a, b, data, moves))
		return ;
	find_best_push(a, b, data, moves + 1);
}
