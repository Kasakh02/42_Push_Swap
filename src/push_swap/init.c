/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 14:18:05 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/07/22 19:45:53 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/**
 * @brief Checks if nbr already exists in stack
 * 
 * @param stack 
 * @param nbr 
 * @return int 
 */
int	is_duplicate(t_stack *stack, int nbr)
{
	t_list	*tmp;

	tmp = stack->values;
	while (tmp)
	{
		if (tmp->content == nbr)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

/**
 * @brief Checks if a given string is a valid number
 * 
 * @param nbr 
 * @return int 
 */
int	is_number(char *nbr)
{
	int	i;

	i = 0;
	while (nbr[i] == ' ' || nbr[i] == '\t')
		i++;
	if (nbr[i] == '-' || nbr[i] == '+')
		i++;
	if (nbr[i] == '\0')
		return (0);
	while (nbr[i])
	{
		if (nbr[i] < '0' || nbr[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/**
 * @brief Checks if all arguments are numbers, if duplicates are inserted
 * and if only int numbers are present
 * 
 * @param stack 
 * @param arg 
 * @return int 
 */
int	check(t_stack *stack, char *arg)
{
	long long int	nbr;

	if (!is_number(arg))
	{
		ft_printf("Only numbers accepted!\n");
		return (0);
	}
	nbr = ft_atoi(arg);
	if (nbr < -2147483648 || nbr > 2147483647)
	{
		ft_printf("Number %s is too long!\nPlease " \
			"insert a number between -2147483648 and 2147483647\n", arg);
		return (0);
	}
	if (is_duplicate(stack, nbr))
	{
		ft_printf("Duplicates found: %i already exists in the stack!\n", nbr);
		return (0);
	}
	return (1);
}

/**
 * @brief Initializes stack a with argv and stack b to NULL
 * 
 * @param argc 
 * @param argv 
 * @return t_stacks* 
 */
t_stacks	*init_stacks(int argc, char **argv)
{
	t_stacks	*stacks;
	int			i;

	i = 1;
	stacks = malloc(sizeof(t_stacks));
	stacks->stack_a = malloc(sizeof(t_stack));
	stacks->stack_a->values = NULL;
	stacks->stack_b = malloc(sizeof(t_stack));
	stacks->stack_b->values = NULL;
	stacks->moves = malloc(sizeof(char *) * 10000);
	stacks->moves_count = 0;
	while (i < argc)
	{
		if (!check(stacks->stack_a, argv[i]))
		{
			free_stacks(stacks);
			return (NULL);
		}
		ft_lstadd_back(&stacks->stack_a->values, ft_lstnew(ft_atoi(argv[i])));
		i++;
	}
	return (stacks);
}
