/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:26:25 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/01/26 17:41:25 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	is_nbr(char *number)
{
	int	i;

	i = 0;
	if (number[i] == '-')
		i++;
	while (number[i])
	{
		if (!ft_isdigit(number[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_duplicate(t_stacks *stacks, int number)
{
	int	size;
	int	i;

	i = 0;
	size = stacks->stack_a.used_size;
	if (size == 0)
		return (1);
	while (i < size)
	{
		if (stacks->stack_a.vector[i] == number)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	is_sorted(t_vector *vector)
{
	int	i;
	int	*tmp;

	i = 0;
	tmp = vector->vector;
	while (i < vector->used_size - 1)
	{
		if (tmp[i] > tmp[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	count_nbr(char *string)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (string[i])
	{
		if (string[i] == ' ')
			count++;
		i++;
	}
	return (count);
}

int	put_err(t_stacks *stacks, char *message, int ret)
{
	if (stacks)
	{
		if (stacks->stack_a.vector)
			free(stacks->stack_a.vector);
		if (stacks->stack_b.vector)
			free(stacks->stack_b.vector);
	}
	if (message != NULL)
		ft_putendl_fd(message, 2);
	return (ret);
}
