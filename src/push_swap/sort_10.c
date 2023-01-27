/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_10.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:29:05 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/01/26 17:32:36 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	get_min_nbr_10(t_stacks *stacks)
{
	int	s_index;

	s_index = get_min_index(&stacks->stack_a);
	while (s_index != 0)
	{
		if (s_index <= 5)
			ra(&stacks->stack_a, YES);
		else
			rra(&stacks->stack_a, YES);
		s_index = get_min_index(&stacks->stack_a);
	}
}

void	sort_10(t_stacks *stacks)
{
	if (!is_sorted(&stacks->stack_a))
	{
		while (stacks->stack_a.used_size != 5)
		{
			get_min_nbr_10(stacks);
			pb(stacks, YES);
		}
		sort_5(stacks);
		while (stacks->stack_a.used_size != stacks->stack_a.size)
			pa(stacks, YES);
	}
}
