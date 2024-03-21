/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalounic <yalounic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:09:51 by yalounic          #+#    #+#             */
/*   Updated: 2024/03/21 08:32:24 by yalounic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_stack *stack)
{
	t_pile	*tmp;
	t_pile	*tmp2;

	if (stack->pile_b == NULL)
		return ;
	tmp = stack->pile_b;
	tmp2 = stack->pile_b->next;
	stack->pile_b = tmp2;
	tmp->next = stack->pile_a;
	stack->pile_a = tmp;
	write(1, "pa\n", 3);
}

void	ft_pb(t_stack *stack)
{
	t_pile	*tmp;
	t_pile	*tmp2;

	if (stack->pile_a == NULL)
		return ;
	tmp = stack->pile_a;
	tmp2 = stack->pile_a->next;
	stack->pile_a = tmp2;
	tmp->next = stack->pile_b;
	stack->pile_b = tmp;
	write(1, "pb\n", 3);
}

void	*ft_memset(void *pointer, int value, size_t count)
{
	unsigned char	c;
	size_t			i;

	c = value;
	i = 0;
	while (i < count)
	{
		((unsigned char *)pointer)[i] = c;
		i++;
	}
	return (pointer);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*s;

	s = NULL;
	if (!nmemb || !size)
		s = (unsigned char *)malloc(1);
	else
	{
		if (nmemb <= 2147483647 / size)
		{
			s = (unsigned char *)malloc(nmemb * size);
			if (!s)
				return (NULL);
			ft_memset(s, 0, nmemb * size);
		}
	}
	return (s);
}
