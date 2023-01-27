/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:24:10 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/01/26 17:37:48 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	swap(int *xp, int *yp)
{
	int	temp;

	temp = *xp;
	*xp = *yp;
	*yp = temp;
}

int	*init_list(t_vector *stack_a)
{
	int	i;
	int	*sorted_list;

	i = 0;
	sorted_list = malloc(sizeof(int) * stack_a->size);
	while (i < stack_a->size)
	{
		sorted_list[i] = stack_a->vector[i];
		i++;
	}
	return (sorted_list);
}

int	*sort_array(t_vector *stack_a)
{
	int	i;
	int	j;
	int	min_index;
	int	*sorted_list;

	i = 0;
	sorted_list = init_list(stack_a);
	while (i < stack_a->size - 1)
	{
		min_index = i;
		j = i + 1;
		while (j < stack_a->size)
		{
			if (sorted_list[j] < sorted_list[min_index])
				min_index = j;
			j++;
		}
		swap(&sorted_list[min_index], &sorted_list[i]);
		i++;
	}
	return (sorted_list);
}

void	sort_rest(t_stacks *stacks)
{
	if (stacks->stack_a.used_size == 2)
	{
		if (!is_sorted(&stacks->stack_a))
			swap_a_b(&stacks->stack_a, YES, 'a');
	}
	if (stacks->stack_a.used_size == 3)
		sort_3(&stacks->stack_a);
	if (stacks->stack_a.used_size == 5 || stacks->stack_a.used_size == 4)
		sort_5(stacks);
	if (stacks->stack_a.used_size > 5)
		sort_rest_nbr(stacks, stacks->stack_a.used_size);
}

void	sort_more_100(t_stacks *stacks)
{
	if (stacks->stack_a.used_size == 2)
	{
		if (!is_sorted(&stacks->stack_a))
			swap_a_b(&stacks->stack_a, YES, 'a');
	}
	else if (stacks->stack_a.used_size == 3)
		sort_3(&stacks->stack_a);
	else if (stacks->stack_a.used_size == 5 || stacks->stack_a.used_size == 4)
		sort_5(stacks);
	else if (stacks->stack_a.used_size > 5 && stacks->stack_a.used_size <= 10)
		sort_rest_nbr(stacks, stacks->stack_a.used_size);
	else if (stacks->stack_a.used_size > 10)
		sort_100(stacks);
}
