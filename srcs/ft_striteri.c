/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagno-r <amagno-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 18:58:24 by amagno-r          #+#    #+#             */
/*   Updated: 2025/04/12 19:07:23 by amagno-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	char	*t;

	if (!s)
		return ;
	t = s;
	while (*t)
	{
		(*f)(t - s, t);
		t++;
	}
}
