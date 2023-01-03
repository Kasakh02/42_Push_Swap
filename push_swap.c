/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42lisboa.pt>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:24:55 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/01/03 15:10:14 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	valid_input (char **argv, int argc)
{
	
}

int	main(char **argv, int argc)
{
	if (argc < 2 || !valid_input(argv, argc))
	{
		ft_printf("Error\n");
		exit (1);
	}

	t_list	*stack_a;
	t_list	*stack_b;
	
	stack_a = new_stack(argv[0]);
}