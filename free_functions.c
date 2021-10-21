/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 12:29:17 by tamighi           #+#    #+#             */
/*   Updated: 2021/10/14 12:37:16 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	free_stack(t_stack *stack, int error)
{
	t_stack *addr;

	addr = stack;
	while (stack)
	{
		stack = stack->next;
		free(addr);
		addr = stack;
	}
	if (error)
		return (ft_error());
	return (0);
}
