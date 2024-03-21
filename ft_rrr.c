/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalounic <yalounic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:03:36 by yalounic          #+#    #+#             */
/*   Updated: 2024/03/21 09:13:59 by yalounic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_stack *stack, int i)
{
	t_pile	*last;
	t_pile	*before_last;

	last = stack->pile_a;
	before_last = NULL;
	if (stack->pile_a == NULL)
		return ;
	while (last->next != NULL)
	{
		before_last = last;
		last = last->next;
	}
	before_last->next = NULL;
	last->next = stack->pile_a;
	stack->pile_a = last;
	if (i == 0)
		write(1, "rra\n", 4);
}

void	ft_rrb(t_stack *stack, int i)
{
	t_pile	*last;
	t_pile	*before_last;

	last = stack->pile_b;
	before_last = NULL;
	if (stack->pile_b == NULL)
		return ;
	while (last->next != NULL)
	{
		before_last = last;
		last = last->next;
	}
	before_last->next = NULL;
	last->next = stack->pile_b;
	stack->pile_b = last;
	if (i == 0)
		write(1, "rrb\n", 4);
}

void	ft_rrr(t_stack *stack)
{
	ft_rra(stack, 1);
	ft_rrb(stack, 1);
	write(1, "rrr\n", 4);
}

int	ft_parse_double(t_stack *stack)
{
	t_pile	*tmp;
	t_pile	*tmp2;

	tmp = stack->pile_a;
	while (tmp != NULL)
	{
		tmp2 = tmp->next;
		while (tmp2 != NULL)
		{
			if (tmp->valeur == tmp2->valeur)
				return (1);
			if (tmp->valeur > 2147483647)
				return (1);
			if (tmp->valeur <= -2147483648)
				return (1);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (0);
}
