/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_call.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 08:36:41 by tamighi           #+#    #+#             */
/*   Updated: 2021/11/08 16:00:42 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	rotation_reverse_call(t_stack *a, t_stack *b, char *call)
{
	if (call[2] == 'a')
		rotate_reverse_stack(a);
	else if (call[2] == 'b')
		rotate_reverse_stack(b);
	else if (call[2] == 'r')
	{
		rotate_reverse_stack(a);
		rotate_reverse_stack(b);
	}
	else
		return (0);
	return (1);
}

int	rotation_call(t_stack **a, t_stack **b, char *call)
{
	if (call[2] && call[1] == 'r' && !call[3])
		return (rotation_reverse_call(*a, *b, call));
	else if (call[1] && !call[2])
	{
		if (call[1] == 'a')
			rotate_stack(*a);
		else if (call[1] == 'b')
			rotate_stack(*b);
		else if (call[1] == 'r')
		{
			rotate_stack(*a);
			rotate_stack(*b);
		}
		else
			return (0);
	}
	else
		return (0);
	return (1);
}

int	swap_call(t_stack **a, t_stack **b, char *call)
{
	if (call[2])
		return (0);
	if (call[1] == 'a')
		swap_stack(*a);
	else if (call[1] == 'b')
		swap_stack(*b);
	else if (call[1] == 'r')
	{
		swap_stack(*a);
		swap_stack(*b);
	}
	else
		return (0);
	return (1);
}

int	push_call(t_stack **a, t_stack **b, char *call)
{
	if (call[2])
		return (0);
	if (call[1] == 'a')
		push_stack(b, a);
	else if (call[1] == 'b')
		push_stack(a, b);
	else
		return (0);
	return (1);
}
