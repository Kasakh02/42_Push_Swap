/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 14:23:32 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/07/22 18:48:08 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/**
 * @brief Get the max number of stack
 * 
 * @param stack 
 * @return int 
 */
int	get_max(t_stack *stack)
{
	int		max;
	t_list	*tmp;

	if (!stack)
		return (-1);
	tmp = stack->values;
	max = tmp->content;
	while (tmp)
	{
		if (tmp->content > max)
			max = tmp->content;
		tmp = tmp->next;
	}
	return (max);
}

/**
 * @brief Get the index of max in stack
 * 
 * @param max 
 * @param stack 
 * @return int 
 */
int	get_index(t_list *stack, int max)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = stack;
	while (stack)
	{
		if (stack->content == max)
			return (i);
		stack = stack->next;
		i++;
	}
	stack = tmp;
	return (-1);
}

/**
 * @brief Calculate the avarege number inside stack
 * 
 * @param stack 
 * @return int 
 */
int	average_nbr(t_stack *stack)
{
	int		total;
	int		size;
	t_list	*tmp;

	size = stack_size(stack);
	total = 0;
	tmp = stack->values;
	while (tmp)
	{
		total += tmp->content;
		tmp = tmp->next;
	}
	return (total / size);
}

/**
 * @brief Prints each stack
 * 
 * @param stacks 
 */
void	show_stacks(t_stacks *stacks)
{
	t_list		*value_a;
	t_list		*value_b;

	ft_printf("Stack a: ");
	if (stacks->stack_a)
	{
		value_a = stacks->stack_a->values;
		while (value_a)
		{
			ft_printf("%i ", value_a->content);
			value_a = value_a->next;
		}
	}
	ft_printf("\nStack b: ");
	if (stacks->stack_b)
	{
		value_b = stacks->stack_b->values;
		while (value_b)
		{
			ft_printf("%i ", value_b->content);
			value_b = value_b->next;
		}
	}
	ft_printf("\n");
}

/**
 * @brief Returns stack size
 * 
 * @param stack 
 * @return int 
 */
int	stack_size(t_stack *stack)
{
	int			size;
	t_list		*current;

	size = 0;
	if (stack)
	{
		current = stack->values;
		while (stack->values)
		{
			stack->values = stack->values->next;
			size++;
		}
		stack->values = current;
	}
	return (size);
}
