/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 13:57:10 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/07/25 12:44:30 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/**
 * @brief Checks if stack is sorted, returns 0 if it's not and 1 otherwise
 * 
 * @param stack 
 * @return int 
 */
int	is_sorted(t_stack *stack)
{
	t_list	*tmp;

	tmp = stack->values;
	while (tmp)
	{
		if (tmp->next)
		{
			if (tmp->content > tmp->next->content)
				return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}

/**
 * @brief Sorts the stack a, calling respective sorting algorithm. If stack 
 * is already sorted it exits
 * 
 * @param stacks 
 */
void	select_sort(t_stacks *stacks)
{
	int	size;

	if (is_sorted(stacks->stack_a))
	{
		ft_printf("Stack already sorted!\n");
		return ;
	}
	size = stack_size(stacks->stack_a);
	if (size == 2)
		swap(stacks->stack_a, "sa", stacks);
	else if (size == 3)
		sort_3(stacks);
	else if (size == 4 || size == 5)
		sort_54(stacks);
	else if (size > 5 && size <= 10)
		sort_10(stacks);
	else
		big_sort(stacks);
	show_moves(stacks);
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	if (argc < 2)
		ft_printf("Push_Swap usage: ./push_swap [numbers]\n");
	else
	{
		stacks = init_stacks(argc, argv);
		if (!stacks)
			return (0);
		select_sort(stacks);
		free_stacks(stacks);
	}
}
