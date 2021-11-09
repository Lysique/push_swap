/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 12:29:17 by tamighi           #+#    #+#             */
/*   Updated: 2021/11/08 15:32:12 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	free_my_input_list(t_input *input)
{
	t_input	*addr;

	while (input)
	{
		if (input->call)
			free(input->call);
		addr = input;
		input = input->next;
		free(addr);
	}
}

void	free_stack(t_stack *stack)
{
	t_stack	*addr;

	addr = stack;
	while (stack)
	{
		stack = stack->next;
		free(addr);
		addr = stack;
	}
}

void	free_all(t_stack *a, t_stack *b, t_input *input, t_fcts *fcts)
{
	free_stack(a);
	free_stack(b);
	free_my_input_list(input);
	if (fcts)
		free(fcts);
}
