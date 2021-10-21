/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 09:56:05 by tamighi           #+#    #+#             */
/*   Updated: 2021/10/19 15:17:10 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	ft_atoi(char **str)
{
	int				i;
	int				sign;
	int				nb;

	i = 0;
	nb = 0;
	sign = 1;
	while (ft_isspace(**str))
		(*str)++;
	if ((**str) == '-')
		sign = -1;
	if (**str == '+' || **str == '-')
		(*str)++;
	while (**str >= '0' && **str <= '9')
	{
		if (nb * sign < INT_MIN / 10 || nb * sign > INT_MAX / 10)
			return (ft_error());
		nb = nb * 10 + (**str - '0');
		(*str)++;
	}
	return (nb * sign);
}

int	check_param(char *str)
{
	int	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if ((str[i] == '+' || str[i] == '-') && ++i)
		if (str[i] < '0' || str[i] > '9')
			return (ft_error());
	if (str[i] >= '0' && str[i] <= '9')
		return (1);
	else if (str[i] && !ft_isspace(str[i]))
		return (ft_error());
	return (0);
}

t_stack	*stack_add(t_stack *stack, int nb)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		free_stack(stack, 1);
	new->nb = nb;
	new->next = stack;
	return (new);
}

t_stack	*get_stack(int argc, char **params, int *count)
{
	int		i;
	t_stack	*stack;

	stack = NULL;
	i = 1;
	while (i < argc)
	{
		while (check_param(params[i]))
		{
			(*count)++;
			stack = stack_add(stack, ft_atoi(&params[i]));
		}
		i++;
	}
	return (stack);
}
