/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42lisboa.pt>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 09:33:20 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/01/12 11:43:49 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		total_len;

	total_len = 0;
	i = 0;
	va_start(ap, str);
	while (str && str[i])
	{
		if (str[i] == '%' && ft_strchr("cspdiuxX%", str[i + 1]))
		{
			i++;
			total_len += ft_var(str[i], ap);
		}
		else
			total_len += ft_put_c(str[i]);
		i++;
	}
	va_end(ap);
	return (total_len);
}

/*int	main()
{
	char *str = "Hello World!";
	int a = 1; int b = 2; int c = 3;
	int decimal = 1.23; int decimal2 = 1;
	
	(void)str;
	ft_printf("Without extras.\n");
	ft_printf("With string: %s\n", str);
	ft_printf("With character: %c.\n", 'K');
	ft_printf("With numbers: %ist number, %ind number, \
	%ird number.\n", a, b, c);
	printf("With decimal numbers: %d (with commas), \
	%d (without commas).\n", decimal, decimal2);
	ft_printf("With pointer: 0 = %p 456 = %p 15 = %p.\n", 0, 456, 15);
	ft_printf("With percent sign: %%.\n");
	ft_printf("With hex numbers (lowercase): 123 = %x.\n", 123);
	ft_printf("With hex numbers (uppercase): 123 = %X.\n", 123);
	ft_printf("With unsigned int: -1 = %u -9 = %u -123 = %u\n", -1, -9, -123);
}*/