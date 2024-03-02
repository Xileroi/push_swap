/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalounic <yalounic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:03:36 by yalounic          #+#    #+#             */
/*   Updated: 2024/03/02 15:14:17 by yalounic         ###   ########.fr       */
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

void	ft_rratmp(t_stack *stack)
{
	t_pile	*last;
	t_pile	*before_last;

	last = stack->pile_tmpa;
	before_last = NULL;
	if (stack->pile_tmpa == NULL)
		return ;
	while (last->next != NULL)
	{
		before_last = last;
		last = last->next;
	}
	before_last->next = NULL;
	last->next = stack->pile_tmpa;
	stack->pile_tmpa = last;
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

void	ft_rrbtmp(t_stack *stack)
{
	t_pile	*last;
	t_pile	*before_last;

	last = stack->pile_tmpb;
	before_last = NULL;
	if (stack->pile_tmpb == NULL)
		return ;
	while (last->next != NULL)
	{
		before_last = last;
		last = last->next;
	}
	before_last->next = NULL;
	last->next = stack->pile_tmpb;
	stack->pile_tmpb = last;
}

void	ft_rrr(t_stack *stack)
{
	ft_rra(stack, 1);
	ft_rrb(stack, 1);
	write(1, "rrr\n", 4);
}
