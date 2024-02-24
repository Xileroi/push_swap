/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_cents.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalounic <yalounic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 02:52:30 by yalounic          #+#    #+#             */
/*   Updated: 2024/02/24 17:07:22 by yalounic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_turkish_tmp(t_stack *stack, int val)
{
	int	lastpos;
	int	posnode;
	int	i;

	lastpos = ft_pos_last(stack);
	posnode = ft_pos_node(stack, val);
	i = 0;
	ft_fill_tmp(stack);
	if (stack->pile_tmpa->valeur == val)
		return (1);
	if (lastpos / 2 >= posnode)
	{
		while (stack->pile_tmpa->valeur != val)
		{
			ft_ratmp(stack);
			i++;
		}
	}
	else if (lastpos / 2 < posnode)
	{
		while (stack->pile_tmpa->valeur != val)
		{
			ft_rratmp(stack);
			i++;
		}
	}
	return (i);
}

int	ft_find_cheapest(t_stack *stack)
{
	int	i;
	int		tmp_valeur;
	t_pile	*tmp;
	int	tmpval;

	i = 1000;
	tmp = stack->pile_a;
	tmp_valeur = tmp->valeur;
	while (tmp->next != NULL)
	{
		if (i > ft_turkish_tmp(stack, tmp_valeur))
		{
			i = ft_turkish_tmp(stack, tmp_valeur);
			tmpval = tmp_valeur;
			tmp = stack->pile_a;
			tmp_valeur = tmp->valeur;
		}
	}
	return (tmp_valeur); //return valeur a push
}

int	ft_sort_lbig(t_stack *stack)
{
	ft_pb(stack);
	ft_pb(stack);
    ft_find_cheapest(stack);
}

/*
Trouver le nombre avec le moins de points possible, rb/rrb ra/rra en fonction de la pos et comparer a chaque fois
cheap: i = nbr de mouvements
*/
