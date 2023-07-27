/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigSort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 14:45:04 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/07/25 17:02:01 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/**
 * @brief Rotates stack a till it gets ordered
 * 
 * @param stacks 
 */
void	last_rotate(t_stacks *stacks)
{
	int	max;
	int	i;
	int	total_rotations;

	max = get_max(stacks->stack_a);
	i = get_index(stacks->stack_a->values, max) + 1;
	total_rotations = stack_size(stacks->stack_a) - i;
	if (i < total_rotations)
	{
		while (i--)
			rotate(stacks->stack_a, "ra", stacks);
	}
	else
	{
		while (total_rotations--)
			reverse(stacks->stack_a, "rra", stacks);
	}
}

/**
 * @brief Puts both the number in question (stack a) and it;s best friend
 * (stack b) in top of each stack, the pushes the one in a to b
 * 
 * @param stacks 
 */
void	make_moves(t_utils *friend, t_stacks *stacks)
{
	put_top_a(stacks, friend->final_bf);
	put_top_b(stacks, friend->final_nbr);
	pa(stacks, 1);
}

/**
 * @brief Initialize all friend info
 * 
 * @param stacks 
 */
t_list	*set_friend(t_utils *friend, t_stacks *stacks)
{
	friend->best = INT_MAX;
	friend->index_nbr = 0;
	friend->size_a = stack_size(stacks->stack_a);
	friend->size_b = stack_size(stacks->stack_b);
	return (stacks->stack_b->values);
}

/**
 * @brief Get the cost of moving the best friend and the number
 * in question to first position of each stack
 * 
 * @param stacks 
 */
void	get_cost_best_friend(t_stacks *stacks)
{
	t_utils	friend;
	t_list	*tmp;

	tmp = set_friend(&friend, stacks);
	while (stacks->stack_b->values)
	{
		friend.index_bf = get_best_friend(stacks->stack_a,
				stacks->stack_b->values->content);
		if (friend.index_bf != -1)
		{
			friend.cost_bf = get_cost_up(friend.size_a, friend.index_bf);
			friend.cost_nbr = get_cost_up(friend.size_b, friend.index_nbr);
			if ((friend.cost_bf + friend.cost_nbr) < friend.best
				&& (friend.cost_bf + friend.cost_nbr) >= 0)
			{
				friend.final_nbr = friend.index_nbr;
				friend.final_bf = friend.index_bf;
				friend.best = friend.cost_bf + friend.cost_nbr;
			}
		}
		stacks->stack_b->values = stacks->stack_b->values->next;
		friend.index_nbr++;
	}
	stacks->stack_b->values = tmp;
	make_moves(&friend, stacks);
}

/**
 * @brief Sorts more than 10 numbers
 * 
 * @param stacks 
 */
void	big_sort(t_stacks *stacks)
{
	int	average;

	average = average_nbr(stacks->stack_a);
	while (stack_size(stacks->stack_a) > 5)
	{
		if (stacks->stack_a->values->content > average)
			rotate(stacks->stack_a, "ra", stacks);
		else
		{
			pb(stacks, 1);
			average = average_nbr(stacks->stack_a);
		}
	}
	sort_54(stacks);
	while (stack_size(stacks->stack_b) > 0)
		get_cost_best_friend(stacks);
	last_rotate(stacks);
}
