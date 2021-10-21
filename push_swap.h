/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:05:18 by tamighi           #+#    #+#             */
/*   Updated: 2021/10/19 16:17:11 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
#include <stdio.h>

typedef struct s_stack {
	int		nb;
	struct s_stack	*next;
}				t_stack;

typedef struct s_data {
	int	max;
	int	min;
	int	count;
	int	countMax;
	int	countMin;
	int	nOp;
}				t_data;

void	push_swap(int argc, char **params);

t_stack	*get_stack(int argc, char **params, int *count);
t_stack	*stack_add(t_stack *stack, int nb);
int		ft_error(void);

int		is_sorted(t_stack *a);

void	sort_five(t_stack **a, t_stack **b, t_data *data);

void	swap_stack(t_stack *stack, t_data *data);
void	rotate_stack(t_stack *stack, t_data *data);
void	rotate_reverse_stack(t_stack *stack, t_data *data);
void	push_stack(t_stack **from, t_stack **to, t_data *data);

int		free_stack(t_stack *stack, int error);

#endif
