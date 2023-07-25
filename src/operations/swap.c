/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 14:43:46 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/07/24 12:49:36 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/**
 * @brief Swap function, writes sa or sb depending on the msg
 * 
 * @param stack 
 * @param msg 
 */
void	swap(t_stack *stack, char *msg, t_stacks *stacks)
{
	int	tmp;

	tmp = stack->values->content;
	stack->values->content = stack->values->next->content;
	stack->values->next->content = tmp;
	stacks->moves[stacks->moves_count++] = msg;
}
