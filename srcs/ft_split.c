/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagno-r <amagno-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 16:44:36 by amagno-r          #+#    #+#             */
/*   Updated: 2025/04/11 17:34:59 by amagno-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_count_words(char *str, const char sep)
{
	size_t i;
	int	words;

	i = 0;
	words = (str[0] != sep) || !str[0];
	while(str[i])
	{
		if(str[i] == sep && str[i + 1] != sep && str[i + 1])
			words++;
		i++;
	}
	return (words);
}

static	char *ft_get_word(char *start, const char sep, size_t *index)
{
	size_t	i;
	char	*ret;

	i = 0;
	while(start[i] != sep && start[i])
		i++;
	*index += i;
	return (ft_substr(start, 0, i));
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	word;
	char	*str;
	char	**ret;

	i = 0;
	word = 0;
	str = (char *) s;
	ret = (char **)malloc(ft_count_words(str, c) * sizeof(char *));
	if(!ret)
		return (NULL);
	while(str[i])
	{
		if(str[i] != c && str[i])
			ret[word] = ft_get_word(&str[i], c, &i);
		if(!str[i])
			break;
		i++;
	}
	return (ret);
}

#include <stdio.h>
int main(int argc, char **argv)
{
	char **split = ft_split(argv[1], ' ');
	printf("%s\n", split[1]);
}

