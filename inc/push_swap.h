/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:30:27 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/01/13 13:44:03 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdalign.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>
#include "../Printf/inc/ft_printf.h"
#include "../Libft/inc/libft.h"

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct h_list
{
	int				nbr;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct h_list	*next;
}					t_stack;

t_stack	*new_stack(long int content);
t_stack	*fill_stack(int argc, char **argv);
t_stack	*end_stack(t_stack *stack);
t_stack	*before_end_stack(t_stack *stack);
void	stack_add_end(t_stack **stack, t_stack *new);

int		ft_issorted(t_stack *stack_a);
int		get_size_stack(t_stack *stack_a);
void	init_index(t_stack *stack_a, int stack_size);
void	do_move(t_stack **a, t_stack **b, int cost_a, int cost_b);

void	cost_rrr(t_stack **a, t_stack **b, int *cost_a, int *cost_b);
void	cost_rr(t_stack **a, t_stack **b, int *cost_a, int *cost_b);
void	cost_ra(t_stack **a, int *cost);
void	cost_rb(t_stack **b, int *cost);

void	get_position(t_stack **stack);
int		get_lowest_index_position(t_stack **stack);
int		get_target(t_stack **a, int b_idx, int target_idx, int target_pos);
void	get_target_position(t_stack **a, t_stack **b);

void	sort_3(t_stack **stack_a);
void	sort_4(t_stack **stack_a, t_stack **stack_b);

void	push_all_save_three(t_stack **stack_a, t_stack **stack_b);
void	shift_stack(t_stack **stack_a);
void	sort(t_stack **stack_a, t_stack **stack_b);

void	get_cost(t_stack **stack_a, t_stack **stack_b);
void	do_cheapest_move(t_stack **stack_a, t_stack **stack_b);

void	swap(t_stack *stack);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_a);
void	ss(t_stack **stack_a, t_stack **stack_b);

void	push(t_stack **src, t_stack **dest);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);

void	rotate(t_stack **stack);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);

void	rev_rotate(t_stack **stack);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

int		check_doubles(char **argv);
int		valid_input(int argc, char **argv);
int		ft_isnumber(char *nbr);

int		ft_issign(char c);
int		strcmp(const char *str, const char *str2);

void	free_stack(t_stack **stack);
void	exit_error(t_stack **stack_a, t_stack **stack_b);
int		is_sorted(t_stack *stack);
void	print_stack(t_stack **stack, char flag);
int		ft_abs(int nb);

int		main(int argc, char **argv);

#endif