/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_duplicates.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:14:46 by tamighi           #+#    #+#             */
/*   Updated: 2021/11/17 16:16:34 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	duplicates_found(t_stack *a)
{
	free_stack(a);
	ft_exit(EXIT_FAILURE);
}

void	check_if_duplicates(t_stack *a)
{
	t_stack	*addr;
	t_stack	*addr2;

	addr = a;
	while (addr->next)
	{
		addr2 = addr->next;
		while (addr2)
		{
			if (addr2->nb == addr->nb)
				duplicates_found(a);
			addr2 = addr2->next;
		}
		addr = addr->next;
	}
}
