/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalounic <yalounic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 06:48:00 by yalounic          #+#    #+#             */
/*   Updated: 2024/03/21 09:36:55 by yalounic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_split_sep(char c, char sep)
{
	return (c == sep || c == '\0');
}

static int	ft_split_search(const char *s, char c)
{
	int	j;

	j = 0;
	while (!ft_split_sep(s[j], c))
		j++;
	return (j);
}

static int	ft_split_size(const char *s, char c)
{
	int	size;
	int	i;

	size = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (!ft_split_sep(s[i], c) && ft_split_sep(s[i + 1], c))
		{
			size++;
		}
		i++;
	}
	return (size);
}

static char	*ft_split_copy(const char *s, int start, int size)
{
	char	*word;
	int		i;

	word = (char *)ft_calloc(size + 1, 1);
	i = 0;
	while (i < size)
	{
		word[i] = s[start + i];
		i++;
	}
	return (word);
}

char	**ft_split(const char *s, char c)
{
	char	**words;
	int		size;
	int		i;
	int		j;
	int		k;

	size = ft_split_size(s, c);
	words = (char **)malloc(sizeof(char *) * (size + 1));
	i = 0;
	k = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			j = ft_split_search(s + i, c);
			words[k++] = ft_split_copy(s, i, j);
			if (ft_checkint(words[k - 1]) == 0)
				return (ft_freeifbad(k, words));
			i += j;
		}
	}
	words[size] = NULL;
	return (words);
}
