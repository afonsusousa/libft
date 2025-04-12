/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagno-r <amagno-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 21:18:57 by amagno-r          #+#    #+#             */
/*   Updated: 2025/04/12 21:42:09 by amagno-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*ret;

	while(lst)
	{
		temp = ft_lstnew(lst->content);
		if (!(*f)(temp))
			(*del)(temp);
		else
			ft_lstadd_back(&ret, (*f)(temp));
		lst = lst->next;
	}
	return (ret);
}
