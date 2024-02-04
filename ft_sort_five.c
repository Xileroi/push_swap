/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalounic <yalounic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:36:13 by yalounic          #+#    #+#             */
/*   Updated: 2024/02/04 17:34:26 by yalounic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_five(t_stack *stack)
{
    ft_pb(stack);
    ft_pb(stack);
	if (stack->pile_b->valeur > stack->pile_b->next->valeur)
		ft_sb(stack, 0);
	ft_sort_small(stack);
	ft_pa(stack);
	if (stack->pile_a->valeur > stack->pile_a->next->next->next->valeur)
		ft_ra(stack, 0);
	else
		ft_sort_small(stack);
	ft_pa(stack);
	if (stack->pile_a->valeur > stack->pile_a->next->next->next->next->valeur)
		ft_ra(stack, 0);
	else
	{
		ft_sa(stack, 0);
		ft_pb(stack);
		ft_sa(stack, 0);
		ft_pa(stack);
	}
    return ;
}
