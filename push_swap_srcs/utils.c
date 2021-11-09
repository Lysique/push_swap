/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 14:49:11 by tamighi           #+#    #+#             */
/*   Updated: 2021/11/09 10:24:16 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_conditions(int before, t_data *data, int after, int moves)
{
	int	x;

	x = 0;
	if (moves == 0)
	{
		if (data->nb > after && (data->nb < before || after > before))
			x = 1;
		else if (after == data->b_biggest && data->nb < before)
			x = 1;
	}
	else if (data->nb > after && (after == data->b_biggest
			|| data->nb < before))
		x = 1;
	else if (after == data->b_biggest && data->nb < before)
		x = 1;
	return (x);
}

int	ft_exit(int error)
{
	if (error == EXIT_FAILURE)
		write(1, "Error\n", 6);
	exit(error);
}
