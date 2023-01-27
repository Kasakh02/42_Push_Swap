/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:28:24 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/01/26 17:46:34 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	sort_3(t_vector *stack_a)
{
	int	*tmp;

	tmp = stack_a->vector;
	if (is_sorted(stack_a))
		return ;
	if (tmp[0] > tmp[1] && tmp[0] < tmp[2] && tmp[1] < tmp[2])
		swap_a_b(stack_a, YES, 'a');
	else if (tmp[0] > tmp[1] && tmp[1] > tmp[2])
	{
		swap_a_b(stack_a, YES, 'a');
		rra(stack_a, YES);
	}
	else if (tmp[0] > tmp[1] && tmp[0] > tmp[2] && tmp[1] < tmp[2])
		ra(stack_a, YES);
	else if (tmp[0] < tmp[1] && tmp[1] > tmp[2] && tmp[0] < tmp[2])
	{
		swap_a_b(stack_a, YES, 'a');
		ra(stack_a, YES);
	}
	else if (tmp[0] < tmp[1] && tmp[1] > tmp[2] && tmp[0] > tmp[2])
		rra(stack_a, YES);
}
