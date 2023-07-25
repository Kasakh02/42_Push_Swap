/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 14:54:40 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/07/24 12:45:56 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/**
 * @brief Sorts 3 numbers
 * 
 * @param stack 
 */
void	sort_3(t_stacks *stacks)
{
	if (!is_sorted(stacks->stack_a))
	{
		if (stacks->stack_a->values->content
			> stacks->stack_a->values->next->content
			&& stacks->stack_a->values->next->next->content
			> stacks->stack_a->values->content)
			swap(stacks->stack_a, "sa", stacks);
		else if (stacks->stack_a->values->content
			< stacks->stack_a->values->next->next->content)
		{
			swap(stacks->stack_a, "sa", stacks);
			rotate(stacks->stack_a, "ra", stacks);
		}
		else if (stacks->stack_a->values->next->next->content
			> stacks->stack_a->values->next->content)
			rotate(stacks->stack_a, "ra", stacks);
		else if (stacks->stack_a->values->content
			< stacks->stack_a->values->next->content)
			reverse(stacks->stack_a, "ra", stacks);
		else
		{
			rotate(stacks->stack_a, "ra", stacks);
			swap(stacks->stack_a, "sa", stacks);
		}
	}
}

/**
 * @brief Sorts 4 or 5 numbers
 * 
 * @param stacks 
 */
void	sort_54(t_stacks *stacks)
{
	int	i;

	i = 0;
	if (!is_sorted(stacks->stack_a))
	{
		if (stack_size(stacks->stack_a) == 5)
		{
			smallest_nbr(stacks);
			pb(stacks, 1);
			i++;
		}
		if (stack_size(stacks->stack_a) == 4)
		{
			smallest_nbr(stacks);
			pb(stacks, 1);
			i++;
		}
		sort_3(stacks);
		while (i > 0)
		{
			pa(stacks, 1);
			i--;
		}
	}
}

/**
 * @brief Sorts [5 - 10] numbers
 * 
 * @param stacks 
 */
void	sort_10(t_stacks *stacks)
{
	int	i;

	i = 0;
	if (!is_sorted(stacks->stack_a))
	{
		while (stack_size(stacks->stack_a) != 5)
		{
			smallest_nbr(stacks);
			pb(stacks, 1);
			i++;
		}
		sort_54(stacks);
		while (i > 0)
		{
			pa(stacks, 1);
			i--;
		}
	}
}
