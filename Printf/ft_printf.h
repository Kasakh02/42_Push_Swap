/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42lisboa.pt>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 09:44:23 by hcorrea-          #+#    #+#             */
/*   Updated: 2022/11/10 16:26:29 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

int		ft_var(char var, va_list ap);
int		ft_put_c(int c);
int		ft_put_s(char *str);
int		ft_put_p(unsigned long nbr);
int		ft_put_nbr(int nbr);
int		ft_put_hex(unsigned int nbr, char var);
int		ft_put_u(unsigned int nbr);
char	*ft_strchr(const char *str, int c);
int		ft_printf(const char *str, ...);

#endif