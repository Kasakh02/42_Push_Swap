/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42lisboa.pt>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:34:49 by hcorrea-          #+#    #+#             */
/*   Updated: 2022/12/06 15:39:57 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "Libft/libft.h"

int	ft_isnumber(char *nbr)
{
	int	i;

	i = 0;
	while (i < ft_strlen(nbr))
	{
		if (!ft_isdigit(nbr[i]))
			return (0);
	}
	return (1);
}

int	ft_isallnum(va_list ap)
{
	
}