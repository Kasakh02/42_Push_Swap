/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:36:34 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/01/13 11:33:43 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_issign(char c)
{
	if (c == '+' || c == '-')
		return (1);
	else
		return (0);
}

int	strcmp(const char *str, const char *str2)
{
	int	i;
	int	j;

	i = 0;
	j = i;
	if (str[i] == '+')
	{
		if (str2[j] != '+')
			i++;
	}
	else
	{
		if (str2[j] == '+')
		{
			j++;
		}
	}
	while (str[i] && str2[j] && str[i] == str2[j])
	{
		i++;
		j++;
	}
	return ((unsigned char)str[i] - (unsigned char)str2[j]);
}
