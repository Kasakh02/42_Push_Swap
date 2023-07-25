/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallSortUtils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 14:52:48 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/07/22 19:23:13 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/**
 * @brief Checks if nbr is in the second half of the stack
 * 
 * @param stack
 * @param nbr 
 * @return int 
 */
int	second_half(t_stack *stack, int nbr)
{
	t_list	*tmp;
	int		size;
	int		i;

	tmp = stack->values;
	size = stack_size(stack);
	i = 0;
	while (tmp)
	{
		if (tmp->content == nbr)
			break ;
		tmp = tmp->next;
		i++;
	}
	return (i >= size / 2);
}

/**
 * @brief Returns smallest number of stack
 * 
 * @param stack 
 * @return int 
 */
int	smallest_nbr(t_stacks *stacks)
{
	int		smallest;
	t_list	*tmp;

	smallest = stacks->stack_a->values->content;
	tmp = stacks->stack_a->values;
	while (tmp)
	{
		if (tmp->content < smallest)
			smallest = tmp->content;
		tmp = tmp->next;
	}
	while (stacks->stack_a->values->content != smallest)
	{
		if (second_half(stacks->stack_a, smallest))
			reverse(stacks->stack_a, "rra", stacks);
		else
			rotate(stacks->stack_a, "ra", stacks);
	}
	return (smallest);
}
