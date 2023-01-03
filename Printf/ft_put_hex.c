/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42lisboa.pt>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:12:53 by hcorrea-          #+#    #+#             */
/*   Updated: 2022/11/22 14:52:15 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_hex(unsigned int nbr, char var)
{
	int		len;
	char	*base_lower;
	char	*base_upper;

	len = 0;
	base_lower = "0123456789abcdef";
	base_upper = "0123456789ABCDEF";
	if (nbr >= 16)
	{
		len += ft_put_hex(nbr / 16, var);
		len += ft_put_hex(nbr % 16, var);
	}
	else
	{
		if (var == 'x')
			len += write(1, &base_lower[nbr], 1);
		else
			len += write(1, &base_upper[nbr], 1);
	}
	return (len);
}
