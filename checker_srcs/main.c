/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:39:00 by tamighi           #+#    #+#             */
/*   Updated: 2021/11/17 16:18:59 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_exit(int error)
{
	if (error == EXIT_FAILURE)
		write(1, "Error\n", 6);
	exit(error);
}

t_fcts	*fcts_struct_init(void)
{
	t_fcts	*fcts;

	fcts = (t_fcts *)malloc(sizeof(t_fcts) * 5);
	if (!fcts)
		return (0);
	fcts[0].call = 'r';
	fcts[0].function = rotation_call;
	fcts[1].call = 'p';
	fcts[1].function = push_call;
	fcts[2].call = 's';
	fcts[2].function = swap_call;
	fcts[3].call = 0;
	return (fcts);
}

void	execute_fcts(t_fcts *fcts, t_input *input, t_stack **a, t_stack **b)
{
	int	j;

	j = 0;
	while (input && fcts[j].call)
	{
		if (fcts[j].call == input->call[0])
		{
			if (!fcts[j].function(a, b, input->call))
			{
				free_all(*a, *b, input, fcts);
				ft_exit(EXIT_FAILURE);
			}
			j = 0;
			input = input->next;
		}
		else
			j++;
	}
	if (input)
	{
		free_all(*a, *b, input, fcts);
		ft_exit(EXIT_FAILURE);
	}
}

void	check_if_ordered(t_stack *a, t_stack *b)
{
	if (b)
	{
		write(1, "KO\n", 4);
		return ;
	}
	while (a->next)
	{
		if (a->nb > a->next->nb)
		{
			write(1, "KO\n", 4);
			return ;
		}
		a = a->next;
	}
	write(1, "OK\n", 4);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_input	*input;
	t_fcts	*fcts;

	if (argc < 2)
		ft_exit(EXIT_SUCCESS);
	a = get_stack(argc, argv);
	if (!a)
		ft_exit(EXIT_SUCCESS);
	b = 0;
	check_if_duplicates(a);
	fcts = fcts_struct_init();
	input = read_std_input(fcts, a);
	if (!fcts)
	{
		free_all(a, b, input, fcts);
		ft_exit(EXIT_FAILURE);
	}
	execute_fcts(fcts, input, &a, &b);
	check_if_ordered(a, b);
	free_all(a, b, input, fcts);
}
