/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalounic <yalounic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:45:40 by yalounic          #+#    #+#             */
/*   Updated: 2024/02/04 16:35:27 by yalounic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_small(t_stack *stack)
{
	if (stack->pile_a->valeur > stack->pile_a->next->valeur)
	{
		if (stack->pile_a->next->valeur > stack->pile_a->next->next->valeur)
		{
			ft_sa(stack, 0);
			ft_rra(stack, 0);
		}
		else if (stack->pile_a->valeur > stack->pile_a->next->next->valeur)
			ft_ra(stack, 0);
		else
			ft_sa(stack, 0);
		return ;
	}
	else if (stack->pile_a->valeur < stack->pile_a->next->valeur)
	{
		if (stack->pile_a->valeur > stack->pile_a->next->next->valeur)
			ft_rra(stack, 0);
		else if (stack->pile_a->next->valeur
			> stack->pile_a->next->next->valeur)
		{
			ft_sa(stack, 0);
			ft_ra(stack, 0);
		}
		return ;
	}
}
