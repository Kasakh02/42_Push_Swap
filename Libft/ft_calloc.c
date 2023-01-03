/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42lisboa.pt>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:19:19 by hcorrea-          #+#    #+#             */
/*   Updated: 2022/11/04 11:24:03 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	size_t	total_size;
	void	*result;

	total_size = nitems * size;
	result = malloc(total_size);
	if (!result)
		return (0);
	ft_memset(result, 0, total_size);
	return (result);
}
