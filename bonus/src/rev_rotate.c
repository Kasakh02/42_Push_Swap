/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:13:26 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/01/13 17:39:16 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

void	rev_rotate(t_checker **stack)
{
	t_checker	*before_last;
	t_checker	*last;

	if (!stack || !(*stack) || !((*stack)->next))
		return ;
	before_last = before_end_stack(*stack);
	last = end_stack(*stack);
	last->next = *stack;
	before_last->next = NULL;
	*stack = last;
}

void	rra(t_checker **stack_a)
{
	rev_rotate(stack_a);
}

void	rrb(t_checker **stack_b)
{
	rev_rotate(stack_b);
}

void	rrr(t_checker **stack_a, t_checker **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
}
