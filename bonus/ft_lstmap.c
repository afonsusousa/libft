/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagno-r <amagno-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 21:18:57 by amagno-r          #+#    #+#             */
/*   Updated: 2025/04/12 22:27:54 by amagno-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*ret;

	ret = NULL;
	while(lst)
	{
		temp = ft_lstnew((*f)(lst->content));
		if (!temp)
			ft_lstdelone(temp, del);
		else
			ft_lstadd_back(&ret, temp);
		lst = lst->next;
	}
	return (ret);
}
