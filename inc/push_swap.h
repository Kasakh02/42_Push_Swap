/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:30:27 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/01/26 17:46:19 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include "../src/Libft/inc/libft.h"

# define YES 1
# define NO 0

typedef struct s_vector
{
	int	*vector;
	int	size;
	int	used_size;
}				t_vector;

typedef struct s_stacks
{
	t_vector	stack_a;
	t_vector	stack_b;
}				t_stacks;

void		sort_rest_nbr(t_stacks *stacks, int size);
int			get_max_index(t_vector *stack_b);
void		get_max_nbr(t_stacks *stacks);
int			get_min_index(t_vector *stack_a);
void		get_min_nbr(t_stacks *stacks);
void		sort_5(t_stacks *stacks);
int			search_index(t_stacks *stacks, int key_number);
void		move_to_top(t_stacks *stacks, int index);
void		push_index(t_stacks *stacks, int key_number);
void		sort_100(t_stacks *stacks);
void		sort_500(t_stacks *stacks);
void		push_stack(int *vector, int used_size);
void		pop_stack(int *vector, int used_size);
void		pa(t_stacks *stacks, int print);
void		pb(t_stacks *stacks, int print);
void		rra(t_vector *stack_a, int print);
void		rrb(t_vector *stack_b, int print);
void		rrr(t_stacks *stacks, int print);
void		swap_a_b(t_vector *vector, int print, char stack);
void		ss(t_stacks *stacks, int print);
void		ra(t_vector *stack_a, int print);
void		rb(t_vector *stack_b, int print);
void		rr(t_stacks *stacks, int print);
void		swap(int *xp, int *yp);
int			*init_list(t_vector *stack_a);
int			*sort_array(t_vector *stack_a);
void		sort_rest(t_stacks *stacks);
void		sort_more_100(t_stacks *stacks);
void		get_min_nbr_10(t_stacks *stacks);
void		sort_10(t_stacks *stacks);
void		sort_3(t_vector *stack_a);
int			is_nbr(char *number);
int			is_duplicate(t_stacks *stacks, int number);
int			is_sorted(t_vector *vector);
int			count_nbr(char *string);
int			put_err(t_stacks *stacks, char *message, int ret);
char		**init_stacks(char *string, t_stacks *stacks);
t_stacks	store_nbr(char *string);
int			av_size(char **av);
char		*av_to_string(char **av);
int			find_key_nbr(int *sorted_list, int size,
				int divided, int chunks);
int			main(int ac, char **av);

#endif