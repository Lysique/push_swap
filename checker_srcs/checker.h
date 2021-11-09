/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:39:58 by tamighi           #+#    #+#             */
/*   Updated: 2021/11/08 16:30:39 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <limits.h>

typedef struct s_stack {
	int				nb;
	struct s_stack	*next;
}				t_stack;

typedef struct s_fcts {
	char	call;
	int		(*function)(t_stack **a, t_stack **b, char *call);
}				t_fcts;

typedef struct s_input {
	char			*call;
	struct s_input	*next;
}				t_input;

void	ft_exit(int error);

t_stack	*get_stack(int argc, char **params);
t_input	*read_std_input(t_fcts *fcts, t_stack *a);
void	check_if_duplicates(t_stack *a);

int		rotation_call(t_stack **a, t_stack **b, char *call);
int		swap_call(t_stack **a, t_stack **b, char *call);
int		push_call(t_stack **a, t_stack **b, char *call);

void	swap_stack(t_stack *stack);
void	rotate_stack(t_stack *stack);
void	rotate_reverse_stack(t_stack *stack);
void	push_stack(t_stack **from, t_stack **to);

void	free_stack(t_stack *stack);
void	free_my_input_list(t_input *input);
void	free_all(t_stack *a, t_stack *b, t_input *input, t_fcts *fcts);

#endif
