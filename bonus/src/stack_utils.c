/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:41:07 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/01/13 17:37:57 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

t_checker	*new_stack(long int nbr)
{
	t_checker	*result;

	result = (t_checker *)malloc(sizeof(t_checker));
	if (!result)
		return (NULL);
	result->nbr = nbr;
	result->next = NULL;
	return (result);
}

t_checker	*fill_stack(int argc, char **argv)
{
	t_checker	*stack_a;
	long int	nbr;
	int			i;

	stack_a = NULL;
	nbr = 0;
	i = 1;
	while (i < argc)
	{
		nbr = ft_atoi(argv[i]);
		if (i == 1)
			stack_a = new_stack(nbr);
		else
			stack_add_end(&stack_a, new_stack(nbr));
		i++;
	}
	return (stack_a);
}

t_checker	*end_stack(t_checker *stack)
{
	while (stack && stack->next)
		stack = stack->next;
	return (stack);
}

t_checker	*before_end_stack(t_checker *stack)
{
	while (stack && stack->next && stack->next->next)
		stack = stack->next;
	return (stack);
}

void	stack_add_end(t_checker **stack, t_checker *new)
{
	t_checker	*tail;

	if (!new)
		return ;
	if (!(*stack))
	{
		*stack = new;
		return ;
	}
	tail = end_stack(*stack);
	tail->next = new;
}
