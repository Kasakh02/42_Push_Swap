/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 14:06:43 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/07/27 11:38:12 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
 * @brief Executes moves (reverse rotate)
 * 
 * @param op 
 * @param stacks 
 */
void	execute_operation2(char *op, t_stacks *stacks)
{
	if (ft_strcmp(op, "rra\n") == 0)
		reverse(stacks->stack_a, NULL, stacks);
	else if (ft_strcmp(op, "rrb\n") == 0)
		reverse(stacks->stack_b, NULL, stacks);
	else if (ft_strcmp(op, "rrr\n") == 0)
	{
		reverse(stacks->stack_a, NULL, stacks);
		reverse(stacks->stack_b, NULL, stacks);
	}
	else if (ft_strcmp(op, "pa\n") == 0)
		pa(stacks, 0);
	else if (ft_strcmp(op, "pb\n") == 0)
		pb(stacks, 0);
}

/**
 * @brief Executes moves (swap and rotate)
 * 
 * @param op 
 * @param stacks 
 */
void	execute_operation(char *op, t_stacks *stacks)
{
	if (ft_strcmp(op, "sa\n") == 0)
		swap(stacks->stack_a, NULL, stacks);
	else if (ft_strcmp(op, "sb\n") == 0)
		swap(stacks->stack_b, NULL, stacks);
	else if (ft_strcmp(op, "ss\n") == 0)
	{
		swap(stacks->stack_a, NULL, stacks);
		swap(stacks->stack_b, NULL, stacks);
	}
	else if (ft_strcmp(op, "ra\n") == 0)
		rotate(stacks->stack_a, NULL, stacks);
	else if (ft_strcmp(op, "rb\n") == 0)
		rotate(stacks->stack_b, NULL, stacks);
	else if (ft_strcmp(op, "rr\n") == 0)
	{
		rotate(stacks->stack_a, NULL, stacks);
		rotate(stacks->stack_b, NULL, stacks);
	}
	else
		execute_operation2(op, stacks);
}

/**
 * @brief Reads each instruction's line
 * 
 * @param stacks 
 */
void	read_operations(t_stacks *stacks)
{
	char	*buff;

	buff = get_next_line(0);
	while (buff)
	{
		execute_operation(buff, stacks);
		free(buff);
		buff = get_next_line(0);
	}
	free(buff);
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	if (argc > 1)
	{
		stacks = init_stacks(argc, argv);
		if (!stacks)
			return (0);
		read_operations(stacks);
		if (is_sorted(stacks->stack_a))
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	}
	else
		ft_printf("Checker usage: ./checker [numbers]\n");
}
