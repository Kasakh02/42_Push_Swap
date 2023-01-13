/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:13:29 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/01/13 11:35:19 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

void	rotate(t_checker **stack)
{
	t_checker	*tmp;
	t_checker	*tail;

	tmp = *stack;
	*stack = (*stack)->next;
	tail = end_stack(*stack);
	tmp->next = NULL;
	tail->next = tmp;
}

void	ra(t_checker **stack_a)
{
	rotate(stack_a);
}

void	rb(t_checker **stack_b)
{
	rotate(stack_b);
}

void	rr(t_checker **stack_a, t_checker **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}
