/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:13:38 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/01/13 11:35:13 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

void push(t_checker **src, t_checker **dest)
{
	t_checker *tmp;
	
	if (*src == NULL) {
		return;
	}
	tmp = *src;
	*src = (*src)->next;
	tmp->next = NULL;

	if (*dest == NULL) {
		*dest = tmp;
	} else {
		tmp->next = *dest;
		*dest = tmp;
	}
}

void	pa(t_checker **stack_a, t_checker **stack_b)
{
	push(stack_b, stack_a);
}

void	pb(t_checker **stack_a, t_checker **stack_b)
{
	push(stack_a, stack_b);
}
