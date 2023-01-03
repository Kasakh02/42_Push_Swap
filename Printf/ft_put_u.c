/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42lisboa.pt>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:05:09 by hcorrea-          #+#    #+#             */
/*   Updated: 2022/11/22 15:41:28 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_u(unsigned int nbr)
{
	int	len;

	len = 0;
	if (nbr >= 10)
	{
		len += ft_put_u(nbr / 10);
		len += ft_put_u(nbr % 10);
	}
	else
		len += ft_put_c(nbr + 48);
	return (len);
}
