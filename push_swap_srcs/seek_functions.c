/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seek_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 14:35:11 by tamighi           #+#    #+#             */
/*   Updated: 2021/11/03 14:23:07 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	biggest_nb(t_stack *a)
{
	t_stack	*addr;
	int		nb;

	addr = a;
	nb = addr->nb;
	while (addr)
	{
		if (addr->nb > nb)
			nb = addr->nb;
		addr = addr->next;
	}
	return (nb);
}

int	last_nb(t_stack *a)
{
	t_stack	*addr;

	addr = a;
	while (addr->next)
		addr = addr->next;
	return (addr->nb);
}
