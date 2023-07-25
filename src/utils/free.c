/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 14:49:50 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/07/22 20:03:02 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/**
 * @brief Frees allocated memory for a stack
 * 
 * @param stack 
 */
void	free_stack(t_stack *stack)
{
	t_list	*tmp;

	while (stack->values)
	{
		tmp = stack->values;
		stack->values = stack->values->next;
		free(tmp);
	}
	free(stack);
}

/**
 * @brief Frees allocated memory for both stacks, a and b and moves
 * 
 * @param stacks 
 */
void	free_stacks(t_stacks *stacks)
{
	if (!stacks)
		return ;
	free_stack(stacks->stack_a);
	free_stack(stacks->stack_b);
	free(stacks->moves);
	free(stacks);
}
