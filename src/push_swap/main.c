/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:27:14 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/01/27 10:01:07 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	main(int ac, char **av)
{
	t_stacks	stacks;
	char		*string;

	ac--;
	if (ac == 0)
		return (0);
	string = av_to_string(av);
	stacks = store_nbr(string);
	if (is_sorted(&stacks.stack_a))
		return (put_err(&stacks, "Stack already sorted!", 0));
	if (stacks.stack_a.size == 2)
		swap_a_b(&stacks.stack_a, YES, 'a');
	if (stacks.stack_a.size == 3)
		sort_3(&stacks.stack_a);
	if (stacks.stack_a.size == 5 || stacks.stack_a.size == 4)
		sort_5(&stacks);
	if (stacks.stack_a.size > 5 && stacks.stack_a.size <= 10)
		sort_10(&stacks);
	if (stacks.stack_a.size > 10 && stacks.stack_a.size <= 100)
		sort_100(&stacks);
	if (stacks.stack_a.size > 100)
		sort_500(&stacks);
	return (put_err(&stacks, NULL, 0));
}
