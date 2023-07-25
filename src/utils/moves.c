/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 19:32:23 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/07/25 12:48:06 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/**
 * @brief Shows moves and uses ss, rr and rrr if it's needed
 * to reduce moves count
 * 
 * @param stacks 
 */
void	show_moves(t_stacks *stacks)
{
	int	i;

	i = 0;
	while (i < stacks->moves_count)
	{
		ft_printf("%s\n", stacks->moves[i]);
		i++;
	}
}
