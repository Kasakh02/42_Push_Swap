/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:29:51 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/01/26 17:42:09 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

char	**init_stacks(char *string, t_stacks *stacks)
{
	int		size;
	char	**numbers;

	numbers = ft_split(string, ' ');
	size = count_nbr(string);
	stacks->stack_a.vector = (int *)malloc(sizeof(int) * size);
	stacks->stack_b.vector = (int *)malloc(sizeof(int) * size);
	stacks->stack_a.size = size;
	stacks->stack_b.size = size;
	stacks->stack_a.used_size = 0;
	stacks->stack_b.used_size = 0;
	free (string);
	return (numbers);
}

t_stacks	store_nbr(char *string)
{
	t_stacks			stacks;
	char				**numbers;
	long long			number;
	int					i;

	i = 0;
	numbers = init_stacks(string, &stacks);
	while (numbers[i])
	{
		if (!is_nbr(numbers[i]))
			exit(put_err(&stacks, "Only numbers!", 0));
		number = ft_atoi(numbers[i]);
		if (number < -2147483648 || number > 2147483647)
			exit(put_err(&stacks, "Long number inserted!", 0));
		if (!is_duplicate(&stacks, number))
			exit(put_err(&stacks, "Duplicates found!", 0));
		stacks.stack_a.vector[i] = number;
		stacks.stack_a.used_size++;
		free(numbers[i]);
		i++;
	}
	free(numbers);
	return (stacks);
}

int	av_size(char **av)
{
	int	size;
	int	i;

	i = 0;
	size = 0;
	while (av[i])
		size += ft_strlen(av[i++]) + 1;
	return (size);
}

int	check_arg(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (ft_isdigit(av[i]))
			return (1);
		i++;
	}
	return (0);
}

char	*av_to_string(char **av)
{
	char	*string;
	char	*tmp;
	int		i;

	i = 1;
	string = (char *)malloc(1);
	while (av[i])
	{
		if (!check_arg(av[i]))
			exit(put_err(NULL, "Only numbers", 0));
		else
		{
			tmp = ft_strjoin(string, av[i]);
			free(string);
			string = ft_strjoin(tmp, " ");
			free (tmp);
			i++;
		}
	}
	return (string);
}
