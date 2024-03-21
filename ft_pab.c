/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalounic <yalounic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:09:51 by yalounic          #+#    #+#             */
/*   Updated: 2024/03/19 20:34:12 by yalounic         ###   ########.fr       */
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
