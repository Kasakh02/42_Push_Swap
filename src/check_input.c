/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:34:49 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/01/13 11:33:49 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_isnumber(char *nbr)
{
	size_t	i;

	i = 0;
	if (ft_issign(nbr[i]))
		i++;
	while (nbr[i] && ft_isdigit(nbr[i]))
		i++;
	if (nbr[i] != '\0' && !ft_isdigit(nbr[i]))
		return (0);
	return (1);
}

int	check_doubles(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 1;
		while (argv[j])
		{
			if (j != i && !strcmp(argv[i], argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_iszero(char *str)
{
	int	i;

	i = 0;
	if (ft_issign(str[i]))
		i++;
	while (str[i] && str[i] == '0')
		i++;
	if (str[i] != '\0')
		return (0);
	return (1);
}

int	check_range(int argc, char **argv)
{
	int			i;
	long int	nbr;

	i = 0;
	while (i < argc)
	{
		nbr = ft_atoi(argv[i]);
		if (nbr < INT_MIN || nbr > INT_MAX)
			return (1);
		i++;
	}
	return (0);
}

int	valid_input(int argc, char **argv)
{
	int		i;
	int		nbr_zeros;

	nbr_zeros = 0;
	i = 1;
	while (argv[i])
	{
		if (!ft_isnumber(argv[i]))
			return (0);
		nbr_zeros += ft_iszero(argv[i]);
		i++;
	}
	if (nbr_zeros > 1)
		return (0);
	if (check_doubles(argv))
		return (0);
	if (check_range(argc, argv))
		return (0);
	return (1);
}
