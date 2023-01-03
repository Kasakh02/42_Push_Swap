/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_var.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42lisboa.pt>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 09:48:23 by hcorrea-          #+#    #+#             */
/*   Updated: 2022/11/10 13:11:53 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_var(char var, va_list ap)
{
	int	len;

	len = 0;
	if (var == 'c')
		len += ft_put_c(va_arg(ap, int));
	else if (var == 's')
		len += ft_put_s(va_arg(ap, char *));
	else if (var == 'p')
		len += ft_put_p(va_arg(ap, unsigned long));
	else if (var == 'd' || var == 'i')
		len += ft_put_nbr(va_arg(ap, int));
	else if (var == 'u')
		len += ft_put_u(va_arg(ap, unsigned int));
	else if (var == 'x' || var == 'X')
		len += ft_put_hex(va_arg(ap, unsigned int), var);
	else if (var == '%')
		len += ft_put_c('%');
	return (len);
}
