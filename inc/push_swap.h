/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 13:57:19 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/07/24 19:09:31 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include "../Libft/inc/libft.h"

typedef struct s_stack
{
	t_list	*values;
}	t_stack;

typedef struct s_stacks
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**moves;
	int		moves_count;
}	t_stacks;

typedef struct s_utils
{
	int		index_nbr;
	int		index_bf;
	int		cost_nbr;
	int		cost_bf;
	int		final_nbr;
	int		final_bf;
	int		best;
	int		size_a;
	int		size_b;
}	t_utils;

/***** OPERATIONS *****/

/*    swap.c    */
void		swap(t_stack *stack, char *msg, t_stacks *stacks);
/*    rotate.c    */
void		reverse(t_stack *stack, char *msg, t_stacks *stacks);
void		rotate(t_stack *stack, char *msg, t_stacks *stacks);
/*    push.c    */
void		pb(t_stacks *stacks, int flag);
void		pa(t_stacks *stacks, int flag);

/***** PUSH_SWAP *****/

/*    init.c    */
t_stacks	*init_stacks(int argc, char **argv);
/*    main.c    */
int			is_sorted(t_stack *stack);
void		select_sort(t_stacks *stacks);

/***** SORTS *****/

/*    smallSort.c    */
void		sort_3(t_stacks *stacks);
void		sort_54(t_stacks *stacks);
void		sort_10(t_stacks *stacks);
/*    smallSortUtils.c    */
int			second_half(t_stack *stack, int nbr);
int			smallest_nbr(t_stacks *stacks);
/*    bigSort.c    */
void		big_sort(t_stacks *stacks);
/*    bigSortUtils.c    */
int			get_cost_up(int size, int i);
int			get_best_friend(t_stack *stack, int content);
void		put_top_a(t_stacks *stacks, int final);
void		put_top_b(t_stacks *stacks, int final);

/***** UTILS *****/

/*    stack.c    */
int			get_max(t_stack *stack);
int			get_index(t_list *stack, int max);
int			average_nbr(t_stack *stack);
int			stack_size(t_stack *stack);
void		show_stacks(t_stacks *stacks);
/*    free.c    */
void		free_stacks(t_stacks *stacks);
/*    moves.c    */
void		show_moves(t_stacks *stacks);

#endif