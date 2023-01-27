/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:28:01 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/01/26 17:29:30 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	rra(t_vector *stack_a, int print)
{
	int	last_element;

	if (print == YES)
		ft_putendl_fd("rra", 1);
	last_element = stack_a->vector[stack_a->used_size - 1];
	push_stack(stack_a->vector, stack_a->used_size);
	stack_a->vector[0] = last_element;
}

void	rrb(t_vector *stack_b, int print)
{
	int	last_element;

	if (print == YES)
		ft_putendl_fd("rrb", 1);
	last_element = stack_b->vector[stack_b->used_size - 1];
	push_stack(stack_b->vector, stack_b->used_size);
	stack_b->vector[0] = last_element;
}

void	rrr(t_stacks *stacks, int print)
{
	if (print == YES)
		ft_putendl_fd("rrr", 1);
	rra(&stacks->stack_a, NO);
	rrb(&stacks->stack_b, NO);
}
