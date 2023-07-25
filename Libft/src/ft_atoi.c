/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:32:29 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/07/21 12:34:35 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long int	ft_atoi(const char *str)
{
	int				i;
	long long int	result;
	int				signal;

	i = 0;
	result = 0;
	signal = 1;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signal = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * signal);
}
