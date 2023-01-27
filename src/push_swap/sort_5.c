/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:28:45 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/01/26 17:31:40 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	get_min_index(t_vector *stack_a)
{
	int	i;
	int	s_index;

	i = 0;
	s_index = i;
	while (i < stack_a->used_size)
	{
		if (stack_a->vector[s_index] > stack_a->vector[i])
			s_index = i;
		i++;
	}
	return (s_index);
}

void	get_min_nbr(t_stacks *stacks)
{
	int	s_index;

	s_index = get_min_index(&stacks->stack_a);
	while (s_index != 0)
	{
		if (s_index <= 2)
			ra(&stacks->stack_a, YES);
		else
			rra(&stacks->stack_a, YES);
		s_index = get_min_index(&stacks->stack_a);
	}
}

void	sort_5(t_stacks *stacks)
{
	int	i;

	i = 0;
	if (!is_sorted(&stacks->stack_a))
	{
		if (stacks->stack_a.used_size == 5)
		{
			get_min_nbr(stacks);
			pb(stacks, YES);
			i++;
		}
		if (stacks->stack_a.used_size == 4)
		{
			get_min_nbr(stacks);
			pb(stacks, YES);
			i++;
		}
		sort_3(&stacks->stack_a);
		while (i > 0)
		{
			pa(stacks, YES);
			i--;
		}
	}
}
