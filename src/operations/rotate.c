/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 10:57:32 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/07/24 12:49:30 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/**
 * @brief Reverse rotates the stack: 1 2 3 becoming 3 1 2;
 * Writes rra or rrb depending on the msg
 * 
 * @param stack 
 * @param msg 
 */
void	reverse(t_stack *stack, char *msg, t_stacks *stacks)
{
	t_list	*first;
	t_list	*second;

	first = stack->values;
	second = first->next;
	while (second->next)
	{
		first = first->next;
		second = second->next;
	}
	second->next = stack->values;
	stack->values = second;
	first->next = NULL;
	stacks->moves[stacks->moves_count++] = msg;
}

/**
 * @brief Rotates the stack: 1 2 3 becoming 2 3 1;
 * Writes ra or rb depending on the msg
 * 
 * @param stack 
 * @param msg 
 */
void	rotate(t_stack *stack, char *msg, t_stacks *stacks)
{
	int		tmp;
	t_list	*first;

	first = stack->values;
	tmp = first->content;
	while (first->next)
	{
		first->content = first->next->content;
		first = first->next;
	}
	first->content = tmp;
	stacks->moves[stacks->moves_count++] = msg;
}
