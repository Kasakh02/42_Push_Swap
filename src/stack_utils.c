/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:41:07 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/01/13 17:04:57 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack	*new_stack(long int nbr)
{
	t_stack	*result;

	result = (t_stack *)malloc(sizeof(t_stack));
	if (!result)
		return (NULL);
	result->nbr = nbr;
	result->index = 0;
	result->pos = -1;
	result->target_pos = -1;
	result->cost_a = -1;
	result->cost_b = -1;
	result->next = NULL;
	return (result);
}

t_stack	*fill_stack(int argc, char **argv)
{
	t_stack		*stack_a;
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

t_stack	*end_stack(t_stack *stack)
{
	while (stack && stack->next)
		stack = stack->next;
	return (stack);
}

t_stack	*before_end_stack(t_stack *stack)
{
	while (stack && stack->next && stack->next->next)
		stack = stack->next;
	return (stack);
}

void	stack_add_end(t_stack **stack, t_stack *new)
{
	t_stack	*tail;

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
