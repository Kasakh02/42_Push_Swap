/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:29:26 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/01/26 17:35:32 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	search_index(t_stacks *stacks, int key_number)
{
	int	i;

	i = 0;
	while (i < stacks->stack_a.used_size)
	{
		if (stacks->stack_a.vector[i] <= key_number)
			return (i);
		i++;
	}
	return (-1);
}

void	move_to_top(t_stacks *stacks, int index)
{
	int	divid;

	divid = stacks->stack_a.used_size / 2;
	while (index != 0)
	{
		if (index <= divid)
		{
			ra(&stacks->stack_a, YES);
			index--;
		}
		else
		{
			rra(&stacks->stack_a, YES);
			index++;
			if (index == stacks->stack_a.used_size)
				break ;
		}
	}
}

void	push_index(t_stacks *stacks, int key_number)
{
	int	index;

	index = search_index(stacks, key_number);
	while (index != -1)
	{
		move_to_top(stacks, index);
		pb(stacks, YES);
		index = search_index(stacks, key_number);
	}
}

void	sort_100(t_stacks *stacks)
{
	int	i;
	int	key_number;
	int	*sorted_list;

	i = 1;
	sorted_list = sort_array(&stacks->stack_a);
	while (i != 4)
	{
		key_number = find_key_nbr(sorted_list,
				stacks->stack_a.size, i, 4);
		push_index(stacks, key_number);
		i++;
	}
	free (sorted_list);
	sort_rest(stacks);
	while (stacks->stack_b.used_size != 0)
	{
		get_max_nbr(stacks);
		pa(stacks, YES);
	}
}

void	sort_500(t_stacks *stacks)
{
	int	i;
	int	key_number;
	int	*sorted_list;

	i = 1;
	sorted_list = sort_array(&stacks->stack_a);
	while (i != 8)
	{
		key_number = find_key_nbr(sorted_list,
				stacks->stack_a.size, i, 8);
		push_index(stacks, key_number);
		i++;
	}
	free (sorted_list);
	sort_more_100(stacks);
	while (stacks->stack_b.used_size != 0)
	{
		get_max_nbr(stacks);
		pa(stacks, YES);
	}
}
