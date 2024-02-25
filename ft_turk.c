/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turk.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalounic <yalounic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:43:22 by yalounic          #+#    #+#             */
/*   Updated: 2024/02/25 16:06:09 by yalounic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_turkish(t_stack *stack, int val)
{
	int	lastpos;
	int	posnode;

	lastpos = ft_pos_last(stack);
	posnode = ft_pos_node(stack, val);
	if (stack->pile_a->valeur == val)
	{
		ft_pb(stack);
	}
	else if (lastpos / 2 >= posnode)
	{
		while (stack->pile_a->valeur != val)
		{
			ft_ra(stack, 0);
		}
		ft_pb(stack);
	}
	else if (lastpos / 2 < posnode)
	{
		while (stack->pile_a->valeur != val)
		{
			ft_rra(stack, 0);
		}
		ft_pb(stack);
	}
	if (stack->pile_b->valeur < stack->pile_b->next->valeur)
		ft_rb(stack, 0);
    /*printf("a\n");
	print_stack(&stack->pile_a);
	printf("b\n");
	print_stack(&stack->pile_b);*/
}
