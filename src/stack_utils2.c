/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:24:40 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/01/13 17:00:10 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_issorted(t_stack *stack_a)
{
	while (stack_a && stack_a->next)
	{
		if (stack_a->nbr > stack_a->next->nbr)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

int	get_size_stack(t_stack *stack_a)
{
	int	i;

	i = 0;
	while (stack_a)
	{
		i++;
		stack_a = stack_a->next;
	}
	return (i);
}

void	init_index(t_stack *stack_a, int stack_size)
{
	t_stack	*tmp;
	t_stack	*highest;
	int		value;

	while (--stack_size > 0)
	{
		tmp = stack_a;
		value = INT_MIN;
		highest = NULL;
		while (tmp)
		{
			if (tmp->nbr == INT_MIN && tmp->index == 0)
				tmp->index = 1;
			if (tmp->nbr > value && tmp->index == 0)
			{
				value = tmp->nbr;
				highest = tmp;
				tmp = stack_a;
			}
			else
				tmp = tmp->next;
		}
		if (highest != NULL)
			highest->index = stack_size;
	}
}

void	do_move(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		cost_rrr(a, b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		cost_rr(a, b, &cost_a, &cost_b);
	cost_ra(a, &cost_a);
	cost_rb(b, &cost_b);
	pa(a, b);
}
