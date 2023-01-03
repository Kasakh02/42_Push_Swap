/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42lisboa.pt>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 14:34:37 by hcorrea-          #+#    #+#             */
/*   Updated: 2022/11/04 12:35:53 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int			i;
	const char	*pos_ini;

	pos_ini = str;
	i = ft_strlen(str);
	str = (str + i);
	while (str != pos_ini && (unsigned char)c != *str)
		str--;
	if (*str == (unsigned char)c)
		return ((char *)str);
	return (0);
}

/*int	main ()
{
	char *str = "Oi, tudo bem. Eespero que sim.?";
	printf("Ultimo 'o' encontrado: %s", ft_strrchr(str, 'o'));
}*/
