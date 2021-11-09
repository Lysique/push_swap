/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:05:18 by tamighi           #+#    #+#             */
/*   Updated: 2021/11/09 10:24:59 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack {
	int				nb;
	struct s_stack	*next;
}				t_stack;

typedef struct s_data {
	int	count_a;
	int	count_b;
	int	pos_a;
	int	pos_b;
	int	b_last;
	int	b_biggest;
	int	nb;
	int	n_op;
}				t_data;

void	push_swap(int argc, char **params);

t_stack	*get_stack(int argc, char **params, int *count);

int		ft_exit(int error);
int		push_conditions(int before, t_data *data, int after, int moves);
void	check_if_duplicates(t_stack *a);

int		last_nb(t_stack *a);
int		biggest_nb(t_stack *a);

void	sort_five(t_stack **a, t_stack **b, t_data *data);
void	sort_more(t_stack **a, t_stack **b, t_data *data);

void	find_best_push(t_stack *a, t_stack *b, t_data *data, int moves);

void	swap_call(t_stack *a, t_stack *b, t_data *data);
void	rotate_call(t_stack *a, t_stack *b, t_data *data);
void	rotate_reverse_call(t_stack *a, t_stack *b, t_data *data);
void	push_call(t_stack **a, t_stack **b, t_data *data, char c);

void	swap_stack(t_stack *stack);
void	rotate_stack(t_stack *stack);
void	rotate_reverse_stack(t_stack *stack);
void	push_stack(t_stack **from, t_stack **to);

void	free_stack(t_stack *stack);

#endif
