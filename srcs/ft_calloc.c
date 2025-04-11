/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagno-r <amagno-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 01:32:03 by amagno-r          #+#    #+#             */
/*   Updated: 2025/04/11 19:25:47 by amagno-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t n, size_t size)
{
	size_t	total;
	void 	*ret;

	total = n * size;
	if (total / size != n)
		return (malloc(1));
	ret = malloc(total);
	if (!ret)
		return (NULL);
	return (ft_bzero(ret, total));
}
