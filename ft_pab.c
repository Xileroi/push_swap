/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalounic <yalounic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:09:51 by yalounic          #+#    #+#             */
/*   Updated: 2024/02/24 17:01:20 by yalounic         ###   ########.fr       */
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
	printf("pa\n");
}

void	ft_patmp(t_stack *stack)
{
	t_pile	*tmp;
	t_pile	*tmp2;

	if (stack->pile_tmpb == NULL)
		return ;
	tmp = stack->pile_tmpb;
	tmp2 = stack->pile_tmpb->next;
	stack->pile_tmpb = tmp2;
	tmp->next = stack->pile_tmpa;
	stack->pile_tmpa = tmp;
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
	printf("pb\n");
}

void	ft_pbtmp(t_stack *stack)
{
	t_pile	*tmp;
	t_pile	*tmp2;

	if (stack->pile_tmpa == NULL)
		return ;
	tmp = stack->pile_tmpa;
	tmp2 = stack->pile_tmpa->next;
	stack->pile_tmpa = tmp2;
	tmp->next = stack->pile_tmpb;
	stack->pile_tmpb = tmp;
}
