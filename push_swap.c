/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 12:27:36 by tamighi           #+#    #+#             */
/*   Updated: 2021/10/19 17:21:18 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error(void)
{
	write(1, "Error\n", 6);
	exit(0);
}

void	print_stack(t_stack *a)
{
	while (a)
	{
		printf("stack : %d\n", a->nb);
		a = a->next;
	}
	printf("\n");
}

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

void	algo_ps(t_stack *a, t_stack *b, int count, t_data *data)
{
	if (count == 2)
	{
		if (a->nb > a->next->nb)
			swap_stack(a, data);
		return ;
	}
	if (count <= 5)
		sort_five(&a, &b, data);
	else
		sort_more(&a, &b, data);
}

void	push_swap(int argc, char **params)
{
	t_stack	*a;
	t_stack	*b;
	int		count;
	t_data	data;

	count = 0;
	a = get_stack(argc, params, &count);
	if (count < 2)
		return ;
	b = NULL;
	data.max = 0;
	data.min = 0;
	data.countMax = 0;
	data.countMin = 0;
	data.nOp = 0;
	data.count = count;
	while (!is_sorted(a))
		algo_ps(a, b, count, &data);
	print_stack(a);
	printf("%d\n", data.nOp);
	free_stack(a, 0);
}
