/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:30:11 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/01/26 17:40:16 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	swap_a_b(t_vector *vector, int print, char stack)
{
	int	temp;

	if (print == YES && stack == 'a')
		ft_putendl_fd("sa", 1);
	else if (print == YES && stack == 'b')
		ft_putendl_fd("sb", 1);
	if (vector->used_size > 1)
	{
		temp = vector->vector[0];
		vector->vector[0] = vector->vector[1];
		vector->vector[1] = temp;
	}
}

void	ss(t_stacks *stacks, int print)
{
	if (print == YES)
		ft_putendl_fd("ss", 1);
	swap_a_b(&stacks->stack_a, NO, 'a');
	swap_a_b(&stacks->stack_b, NO, 'b');
}

void	ra(t_vector *stack_a, int print)
{
	int	first_element;

	if (print == YES)
		ft_putendl_fd("ra", 1);
	first_element = stack_a->vector[0];
	pop_stack(stack_a->vector, stack_a->used_size);
	stack_a->vector[stack_a->used_size - 1] = first_element;
}

void	rb(t_vector *stack_b, int print)
{
	int	first_element;

	if (print == YES)
		ft_putendl_fd("rb", 1);
	first_element = stack_b->vector[0];
	pop_stack(stack_b->vector, stack_b->used_size);
	stack_b->vector[stack_b->used_size - 1] = first_element;
}

void	rr(t_stacks *stacks, int print)
{
	if (print == YES)
		ft_putendl_fd("rr", 1);
	ra(&stacks->stack_a, NO);
	rb(&stacks->stack_b, NO);
}
