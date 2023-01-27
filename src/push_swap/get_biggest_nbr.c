/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_biggest_nbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:26:53 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/01/26 17:46:06 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	sort_rest_nbr(t_stacks *stacks, int size)
{
	if (!is_sorted(&stacks->stack_a))
	{
		while (stacks->stack_a.used_size >= 5)
		{
			get_min_nbr_10(stacks);
			pb(stacks, YES);
		}
		sort_5(stacks);
		while (stacks->stack_a.used_size != size)
			pa(stacks, YES);
	}
}

int	find_key_nbr(int *sorted_list, int size, int divided, int chunks)
{
	int	key_munber;

	key_munber = sorted_list[(size * divided) / chunks];
	return (key_munber);
}

int	get_max_index(t_vector *stack_b)
{
	int	i;
	int	b_index;

	i = 0;
	b_index = i;
	while (i < stack_b->used_size)
	{
		if (stack_b->vector[b_index] < stack_b->vector[i])
			b_index = i;
		i++;
	}
	return (b_index);
}

void	get_max_nbr(t_stacks *stacks)
{
	int	b_index;

	b_index = get_max_index(&stacks->stack_b);
	while (b_index != 0)
	{
		if (b_index <= (stacks->stack_b.used_size / 2))
			rb(&stacks->stack_b, YES);
		else
			rra(&stacks->stack_b, YES);
		b_index = get_max_index(&stacks->stack_b);
	}
}
