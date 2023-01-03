/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42lisboa.pt>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:24:06 by hcorrea-          #+#    #+#             */
/*   Updated: 2022/11/04 11:25:23 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*result;

	result = (char *)malloc(ft_strlen(s1) + 1);
	if (!result)
		return (0);
	ft_memcpy(result, s1, ft_strlen(s1) + 1);
	return (result);
}
