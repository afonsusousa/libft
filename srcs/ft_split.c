/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagno-r <amagno-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 16:44:36 by amagno-r          #+#    #+#             */
/*   Updated: 2025/04/11 19:19:00 by amagno-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_count_words(const char *str, const char sep)
{
	size_t i;
	int	words;

	i = 0;
	words = (str[0] != sep) && (str[0] != 0);
	while(str[i])
	{
		if(str[i] == sep && str[i + 1] != sep && str[i + 1])
			words++;
		i++;
	}
	return (words);
}

static	int ft_strlen_sep(const char *start, const char sep)
{
	int	i;
	
	i = 0;
	while(start[i] != sep && start[i])
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	word;
	size_t	word_len;
	char	**ret;

	i = 0;
	word = 0;
	if(!s)
		return (0);
	ret = (char **)ft_calloc(ft_count_words(s, c) + 1, sizeof(char *));
	if(!ret)
		return (NULL);
	while(s[i])
	{
		word_len = 0;
		if(s[i] != c && s[i])
		{
			word_len = ft_strlen_sep(&s[i], c);
			ret[word++] = ft_substr(s, i, word_len);
			i += word_len;
		}
		else
			i++;
	}
	return (ret);
}

/*
#include <stdio.h>
int main(int argc, char **argv)
{
	char **split = ft_split("\0aa\0bbb", '\0');
	for(int i = 0; i < ft_count_words("\0aa\0bbb", '\0'); i++)
		printf("letra qualquer %s\n", split[i]);
//	char **split = ft_split(argv[1], argv[2][0]);
//	for(int i = 0; i < ft_count_words(argv[1], argv[2][0]); i++)
//		printf("%s\n", split[i]);
}
*/
