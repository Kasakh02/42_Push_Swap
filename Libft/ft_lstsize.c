/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42lisboa.pt>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 09:54:25 by hcorrea-          #+#    #+#             */
/*   Updated: 2022/11/04 11:48:59 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		i++;
		lst = lst->next;
	}	
	return (i);
}

/*int main()
{
	t_list *s1 = ft_lstnew("oi");
	s1->next = ft_lstnew("tudo");
	s1->next->next = ft_lstnew("bem");
	printf("Numero de elementos da lista: %i", ft_lstsize(s1));
}*/
