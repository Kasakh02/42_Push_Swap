/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:30:09 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/01/13 16:59:03 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_3(t_stack **stack_a)
{
	if ((*stack_a)->nbr > (*stack_a)->next->nbr \
	&& (*stack_a)->next->nbr > (*stack_a)->next->next->nbr)
	{
		sa(stack_a);
		rra(stack_a);
	}
	if ((*stack_a)->nbr > (*stack_a)->next->nbr \
	&& (*stack_a)->next->nbr < (*stack_a)->next->next->nbr \
	&& (*stack_a)->nbr > (*stack_a)->next->next->nbr)
		ra(stack_a);
	if ((*stack_a)->nbr > (*stack_a)->next->nbr \
	&& (*stack_a)->next->nbr < (*stack_a)->next->next->nbr)
		sa(stack_a);
	if ((*stack_a)->nbr < (*stack_a)->next->nbr \
	&& (*stack_a)->next->nbr > (*stack_a)->next->next->nbr \
	&& (*stack_a)->nbr < (*stack_a)->next->next->nbr)
	{
		sa(stack_a);
		ra(stack_a);
	}
	if ((*stack_a)->nbr < (*stack_a)->next->nbr \
	&& (*stack_a)->next->nbr > (*stack_a)->next->next->nbr)
		rra(stack_a);
}

int	get_pos_min(t_stack **stack_a, t_stack *min)
{
	int	i;

	i = 0;
	while ((*stack_a)->nbr != min->nbr)
	{
		i++;
		(*stack_a) = (*stack_a)->next;
	}
	return (i);
}

void	sort_4(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*min;
	t_stack	*tmp;
	int		pos;

	tmp = *stack_a;
	min = tmp;
	while (tmp)
	{
		if (tmp->nbr < min->nbr)
			min = tmp;
		tmp = tmp->next;
	}
	tmp = (*stack_a);
	pos = get_pos_min(&tmp, min);
	while ((*stack_a)->nbr != min->nbr)
	{
		if (pos >= get_size_stack(*stack_a) / 2 \
		&& pos < get_size_stack(*stack_a))
			rra(stack_a);
		else
			ra(stack_a);
	}
	pb(stack_a, stack_b);
	sort_3(stack_a);
	pa(stack_a, stack_b);
}
