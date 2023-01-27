/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:27:41 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/01/26 17:29:07 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	push_stack(int *vector, int used_size)
{
	while (used_size > 0)
	{
		vector[used_size] = vector[used_size - 1];
		used_size--;
	}
}

void	pop_stack(int *vector, int used_size)
{
	int	i;

	i = 0;
	while (i < used_size)
	{
		vector[i] = vector[i + 1];
		i++;
	}
}

void	pa(t_stacks *stacks, int print)
{
	int	used_size_b;
	int	used_size_a;

	used_size_b = stacks->stack_b.used_size;
	used_size_a = stacks->stack_a.used_size;
	if (print == YES)
		ft_putendl_fd("pa", 1);
	if (used_size_b == 0)
		return ;
	if (used_size_a == 0)
		stacks->stack_a.vector[0] = stacks->stack_b.vector[0];
	else
	{
		push_stack(stacks->stack_a.vector, used_size_a);
		stacks->stack_a.vector[0] = stacks->stack_b.vector[0];
	}
	pop_stack(stacks->stack_b.vector, used_size_b);
	stacks->stack_a.used_size++;
	stacks->stack_b.used_size--;
}

void	pb(t_stacks *stacks, int print)
{
	int	used_size_b;
	int	used_size_a;

	used_size_b = stacks->stack_b.used_size;
	used_size_a = stacks->stack_a.used_size;
	if (print == YES)
		ft_putendl_fd("pb", 1);
	if (used_size_a == 0)
		return ;
	if (used_size_b == 0)
		stacks->stack_b.vector[0] = stacks->stack_a.vector[0];
	else
	{
		push_stack(stacks->stack_b.vector, used_size_b);
		stacks->stack_b.vector[0] = stacks->stack_a.vector[0];
	}
	pop_stack(stacks->stack_a.vector, used_size_a);
	stacks->stack_b.used_size++;
	stacks->stack_a.used_size--;
}
