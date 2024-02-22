/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_cents.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalounic <yalounic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 02:52:30 by yalounic          #+#    #+#             */
/*   Updated: 2024/02/22 19:21:42 by yalounic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sort_lbig(t_stack *stack)
{
	ft_pb(stack);
	ft_pb(stack);
    ft_find_cheapest(stack);
}

int	ft_turkish_tmp(t_stack *stack, int val)
{
	int	lastpos;
	int	posnode;
	int	i;

	lastpos = ft_pos_last(stack);
	posnode = ft_pos_node(stack);
	i = 0;
	ft_fill_tmp(stack)
	if (lastpos / 2 <= posnode)
	{
		while (stack->pile_tmpa->valeur != val)
		{
			ft_ra(stack, 0);
			i++;
		}
	}
	else if (lastpos / 2 > posnode)
	{
		while (stack->pile_tmpa->valeur != val)
		{
			ft_rra(stack, 0);
			i++;
		}
	}
	return (i);
}

int	ft_find_cheapest(t_stack *stack)
{
	int	i;
	int	tmpi
	int	val;
	int	tmpval
	
	while (stack->pile_a->next != NULL)
	{
		
	}
	return (val); //return valeur a push
}



/*
Trouver le nombre avec le moins de points possible, rb/rrb ra/rra en fonction de la pos et comparer a chaque fois
cheap: i = nbr de mouvements
*/
