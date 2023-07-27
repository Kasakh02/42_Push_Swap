/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:59:21 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/07/25 13:12:05 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	exceptions(int *nb)
{
	int	len;

	len = 0;
	if (*nb < 0)
	{
		ft_put_c('-');
		*nb *= -1;
		len++;
	}
	if (*nb == -2147483648)
	{
		ft_put_c('2');
		*nb = 147483648;
		len++;
	}
	return (len);
}

int	ft_put_nbr(int nb)
{
	int	size;
	int	test;
	int	len;

	size = 1;
	len = 0;
	len += exceptions(&nb);
	test = nb / 10;
	while (test > 0)
	{
		test = test / 10;
		size *= 10;
	}
	test = nb;
	while (size)
	{
		ft_put_c((char)((test / size)) + '0');
		test %= size;
		size /= 10;
		len++;
	}
	return (len);
}
