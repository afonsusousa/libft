/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagno-r <amagno-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 22:01:24 by amagno-r          #+#    #+#             */
/*   Updated: 2025/04/12 19:08:02 by amagno-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	unsigned int		src_len;

	if(!s)
		return (0);
	src_len = (unsigned int )ft_strlen((char *)s);
	if(start >= src_len)
		return ((char *)ft_calloc(1, 1));
	if(start + len > src_len)
		len -= len - start;
	ret = (char *)malloc(len + 1);
	if(!ret)
		return (NULL);
	ft_strlcpy(ret, (char *)&s[start], len + 1);
	return (ret);
}
