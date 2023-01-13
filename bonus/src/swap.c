/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:10:42 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/01/13 10:15:09 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

void	swap(t_checker *stack)
{
	long int	tmp;

	if (stack == NULL || stack->next == NULL)
		return ;
	tmp = stack->nbr;
	stack->nbr = stack->next->nbr;
	stack->next->nbr = tmp;
}

void	sa(t_checker **stack_a)
{
	swap(*stack_a);
}

void	sb(t_checker **stack_a)
{
	swap(*stack_a);
}

void	ss(t_checker **stack_a, t_checker **stack_b)
{
	swap(*stack_a);
	swap(*stack_b);
}
