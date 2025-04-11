/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagno-r <amagno-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:44:28 by amagno-r          #+#    #+#             */
/*   Updated: 2025/04/10 20:34:14 by amagno-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	src_len;
	size_t	dest_len;

		
	src_len = ft_strlen((char *)src);
	if(!dest && !size)
		return (src_len);
	dest_len = ft_strlen((char *)dest);
	i = dest_len - 1;
	j = -1;
	if(!size)
		return (src_len);
	while(src[++j] && (++i < (size - 1)))	
		dest[i] = src[j];
	if(size)
		dest[++i] = 0;
	if(size <= dest_len)
			return (src_len + size);
	else
		return (src_len + dest_len);
}
