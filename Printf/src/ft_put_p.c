/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42lisboa.pt>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:17:18 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/01/12 11:43:57 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	to_hex(unsigned long nbr)
{
	int		len;
	char	*base;

	len = 0;
	base = "0123456789abcdef";
	if (nbr >= 16)
	{
		len += to_hex(nbr / 16);
		len += to_hex(nbr % 16);
	}
	else
		len += write(1, &base[nbr], 1);
	return (len);
}

int	ft_put_p(unsigned long nbr)
{
	int	len;

	len = 0;
	if (!nbr)
	{
		len += write(1, "(nil)", 5);
		return (len);
	}
	len += write(1, "0x", 2) + to_hex(nbr);
	return (len);
}
