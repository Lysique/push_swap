/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_std_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:28:20 by tamighi           #+#    #+#             */
/*   Updated: 2021/11/09 13:59:13 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	free_and_exit(t_stack *a, t_input *input, t_fcts *fcts)
{
	free_all(a, 0, input, fcts);
	ft_exit(EXIT_FAILURE);
}

t_input	*input_add(t_input *input, char *line, t_fcts *fcts, t_stack *a)
{
	t_input	*addr;
	t_input	*new;

	new = malloc(sizeof(t_input));
	if (!new || !line)
	{
		if (line)
			free(line);
		free_and_exit(a, input, fcts);
	}
	addr = input;
	new->call = line;
	new->next = 0;
	while (addr && addr->next)
		addr = addr->next;
	if (!addr)
		return (new);
	else
		addr->next = new;
	return (input);
}

char	*ft_strjoin(char *line, char *buf)
{
	int		i;
	char	*new;

	i = 0;
	while (line && line[i])
		i++;
	new = malloc(i + 2);
	if (!new)
		return (0);
	i = 0;
	while (line && line[i])
	{
		new[i] = line[i];
		i++;
	}
	new[i++] = buf[0];
	new[i] = '\0';
	free(line);
	return (new);
}

t_input	*read_std_input(t_fcts *fcts, t_stack *a)
{
	char	*line;
	char	buf[1];
	int		ret;
	t_input	*input;

	ret = read(0, buf, 1);
	input = 0;
	line = 0;
	while (ret > 0)
	{
		if (buf[0] == '\n')
		{
			input = input_add(input, line, fcts, a);
			line = 0;
		}
		else
		{
			line = ft_strjoin(line, buf);
			if (!line)
				free_and_exit(a, input, fcts);
		}
		ret = read(0, buf, 1);
	}
	return (input);
}
