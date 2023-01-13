/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:24:55 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/01/13 17:06:51 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	choose_sort(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_issorted(*stack_a))
	{
		ft_printf("Stack already sorted\n");
		exit(1);
	}
	if (get_size_stack(*stack_a) == 2)
		sa(stack_a);
	if (get_size_stack(*stack_a) == 3)
		sort_3(stack_a);
	if (get_size_stack(*stack_a) == 4)
		sort_4(stack_a, stack_b);
	if (get_size_stack(*stack_a) > 4)
		sort(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;

	if (argc < 2)
		return (0);
	stack_b = NULL;
	stack_a = fill_stack(argc, argv);
	stack_size = get_size_stack(stack_a);
	init_index(stack_a, stack_size + 1);
	if (!valid_input(argc, argv))
		exit_error(&stack_a, NULL);
	choose_sort(&stack_a, &stack_b);
	print_stack(&stack_a, 'a');
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
