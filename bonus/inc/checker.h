/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:35:06 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/01/13 13:44:42 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdalign.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>
#include "../../Libft/inc/libft.h"
#include "../../Printf/inc/ft_printf.h"
#include "../../42_Get_Next_Line/get_next_line.h"

#ifndef CHECKER_H
# define CHECKER_H

typedef struct m_list
{
	int				nbr;
	struct m_list	*next;
}					t_checker;

void		swap(t_checker *stack);
void		sa(t_checker **stack_a);
void		sb(t_checker **stack_a);
void		ss(t_checker **stack_a, t_checker **stack_b);

void		push(t_checker **src, t_checker **dest);
void		pa(t_checker **stack_a, t_checker **stack_b);
void		pb(t_checker **stack_a, t_checker **stack_b);

void		rotate(t_checker **stack);
void		ra(t_checker **stack_a);
void		rb(t_checker **stack_b);
void		rr(t_checker **stack_a, t_checker **stack_b);

void		rev_rotate(t_checker **stack);
void		rra(t_checker **stack_a);
void		rrb(t_checker **stack_b);
void		rrr(t_checker **stack_a, t_checker **stack_b);

t_checker	*new_stack(long int content);
t_checker	*fill_stack(int argc, char **argv);
t_checker	*end_stack(t_checker *stack);
t_checker	*before_end_stack(t_checker *stack);
void		stack_add_end(t_checker **stack, t_checker *new);

void		do_instruction(char *str, t_checker **stack_a, t_checker **stack_b);
int			main(int argc, char **argv);

#endif