/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigSortUtils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 16:00:01 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/07/25 12:23:56 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/**
 * @brief Puts number in question in top of stack a
 * 
 * @param stacks 
 */
void	put_top_a(t_stacks *stacks, int final)
{
	int	size;
	int	i;

	size = stack_size(stacks->stack_a);
	if (final == -1)
		return ;
	else if ((size / 2) >= final)
	{
		i = final;
		while (i)
		{
			rotate(stacks->stack_a, "ra", stacks);
			i--;
		}
	}
	else if ((size / 2) < final)
	{
		i = final;
		while (i < size)
		{
			reverse(stacks->stack_a, "rra", stacks);
			i++;
		}
	}
}

/**
 * @brief Puts number in question in top of stack b
 * 
 * @param stacks 
 */
void	put_top_b(t_stacks *stacks, int final)
{
	int	size;
	int	i;

	size = stack_size(stacks->stack_b);
	if (final == -1)
		return ;
	else if ((size / 2) >= final)
	{
		i = final;
		while (i)
		{
			rotate(stacks->stack_b, "rb", stacks);
			i--;
		}
	}
	else if ((size / 2) < final)
	{
		i = final;
		while (i < size)
		{
			reverse(stacks->stack_b, "rrb", stacks);
			i++;
		}
	}
}

/**
 * @brief Get the cost to put object of index i on top of the stack
 * 
 * @param size 
 * @param i 
 * @return int 
 */
int	get_cost_up(int size, int i)
{
	int	result;

	result = 0;
	if (i <= (size / 2))
		result = i;
	else if (i > (size / 2))
		result = size - i;
	return (result);
}

/**
 * @brief Get the best friend of nbr in question, in stack b, of stack a
 * 
 * @param stack 
 * @param content 
 * @return int 
 */
int	get_best_friend(t_stack *stack, int content)
{
	int		friend;
	int		i;
	int		nbr;
	t_list	*temp;

	i = INT_MAX;
	friend = INT_MAX;
	temp = stack->values;
	while (stack->values)
	{
		nbr = stack->values->content - content;
		if ((nbr < i) && nbr > 0)
		{
			i = nbr;
			friend = stack->values->content;
		}
		stack->values = stack->values->next;
	}
	stack->values = temp;
	if (friend == INT_MAX)
		return (-1);
	return (get_index(stack->values, friend));
}
