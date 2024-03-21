/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_alpha.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalounic <yalounic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 21:52:31 by yalounic          #+#    #+#             */
/*   Updated: 2024/03/21 09:44:27 by yalounic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] != '\0' && s2[i] != '\0') && (s1[i] == s2[i]))
		i++;
	if (s1[i] == s2[i])
		return (0);
	else
		return (s1[i] - s2[i]);
}

int	ft_isalpha(int c)
{
	if ((c >= 58 && c <= 126) || (c >= 33 && c <= 42) || (c == 44) || (c == 46)
		|| (c == 47))
		return (1);
	return (0);
}

int	ft_checkint(char *str)
{
	if (ft_strlen(str) > 11)
		return (0);
	if (ft_strlen(str) == 11 && str[0] != '-')
		return (0);
	if (ft_strlen(str) == 11 && str[0] == '-')
	{
		if (ft_strcmp(str, "-2147483648") > 0)
			return (0);
	}
	if (ft_strlen(str) == 10 && str[0] == '-')
	{
		if (ft_strcmp(str, "-2147483648") > 0)
			return (0);
	}
	if (ft_strlen(str) == 10 && str[0] != '-')
	{
		if (ft_strcmp(str, "2147483647") > 0)
			return (0);
	}
	return (1);
}

int	ft_alpha_check(char **argv, int i)
{
	int	j;

	while (argv[i])
	{
		j = 0;
		while ((argv[i][j]) != '\0')
		{
			if (ft_isalpha(argv[i][j]))
				return (0);
			j++;
		}
		if (ft_strlen(argv[i]) == 1 && ft_isdigit(argv[i][0]) == 0)
			return (0);
		if (ft_checkint(argv[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}
