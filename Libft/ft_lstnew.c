/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42lisboa.pt>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:59:20 by hcorrea-          #+#    #+#             */
/*   Updated: 2022/11/24 11:08:05 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*result;

	result = (t_list *)malloc(sizeof(t_list));
	if (!result)
		return (NULL);
	result->content = content;
	result->next = NULL;
	return (result);
}

/*int	main()
{
	int number = 1234;
	char *string = "Kasakh";
	t_list *lststr = ft_lstnew(string);
	t_list *lstnbr = ft_lstnew(&number);
	char *str = lststr->content;
	int nbr = *(int *)lstnbr->content;
	printf("Primeiro elemento da lista (String): %s.\n", str);
	printf("Primeiro elemento da lista (Numero): %i.", nbr);
}*/