/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:33:24 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/01/13 17:49:57 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

void	print_stack(t_checker **stack, char flag)
{
	ft_printf("\nStack_%c = [ ", flag);
	while ((*stack) != NULL)
	{
		ft_printf("%i ", (*stack)->nbr);
		(*stack) = (*stack)->next;
	}
	ft_printf("]\n");
}

void	free_stack(t_checker **stack)
{
	t_checker	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

void	do_instruction(char *str, t_checker **stack_a, t_checker **stack_b)
{
	if (strcmp("sa", str) == 0)
	{
		ft_printf("\nsa\n");
		sa(stack_a);
	}
	if (strcmp("sb", str) == 0)
		sb(stack_a);
	if (strcmp("ss", str) == 0)
		ss(stack_a, stack_b);
	/*if (ft_strncmp("pa", str, ft_strlen(str)))
		pa(stack_a, stack_b);
	if (ft_strncmp("pb", str, ft_strlen(str)))
		pb(stack_a, stack_b);
	if (ft_strncmp("ra", str, ft_strlen(str)))
		ra(stack_a);
	if (ft_strncmp("rb", str, ft_strlen(str)))
		rb(stack_a);
	if (ft_strncmp("rr", str, ft_strlen(str)))
		rr(stack_a, stack_b);
	if (ft_strncmp("rra", str, ft_strlen("rra")))
		rra(stack_a);
	if (ft_strncmp("rrb", str, ft_strlen("rrb")))
		rrb(stack_a);
	if (ft_strncmp("rrr", str, ft_strlen("rrr")))
		rrr(stack_a, stack_b);*/
}

int	main(int argc, char **argv)
{
	t_checker	*stack_a;
	t_checker	*stack_b;

	stack_b = NULL;
	stack_a = fill_stack(argc, argv);
	char *str = get_next_line(0);
	do_instruction(str, &stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_a);
}
