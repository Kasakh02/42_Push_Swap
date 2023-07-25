/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 15:45:57 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/07/23 14:50:02 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/**
 * @brief Pushes the first node of a to b
 * 
 * @param stacks 
 */
void	pb(t_stacks *stacks, int flag)
{
	t_list	*tmp;

	if (stacks->stack_a->values)
	{
		tmp = stacks->stack_a->values;
		stacks->stack_a->values = tmp->next;
		tmp->next = stacks->stack_b->values;
		stacks->stack_b->values = tmp;
		if (flag)
			stacks->moves[stacks->moves_count++] = "pb";
	}
}

/**
 * @brief Pushes the first node of b to a
 * 
 * @param stacks 
 */
void	pa(t_stacks *stacks, int flag)
{
	t_list	*tmp;

	if (stacks->stack_b->values)
	{
		tmp = stacks->stack_b->values;
		stacks->stack_b->values = tmp->next;
		tmp->next = stacks->stack_a->values;
		stacks->stack_a->values = tmp;
		if (flag)
			stacks->moves[stacks->moves_count++] = "pa";
	}
}
