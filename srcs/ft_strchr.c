/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagno-r <amagno-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:00:41 by amagno-r          #+#    #+#             */
/*   Updated: 2025/04/10 19:31:43 by amagno-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char *ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			break;
		s++;
	}
	if(!c || *s == c)
		return ((char *)s); 
	else
		return (NULL);
}
