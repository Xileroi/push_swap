/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_cents.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalounic <yalounic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 02:52:30 by yalounic          #+#    #+#             */
/*   Updated: 2024/03/02 15:28:37 by yalounic         ###   ########.fr       */
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
	if (stack->pile_tmpa->valeur == val)
		ft_tmpbfindpeer(stack, val);
	else if (lastpos / 2 >= posnode)
	{
		while (stack->pile_tmpa->valeur != val)
		{
			ft_ratmp(stack);
			i++;
		}
		ft_tmpbfindpeer(stack, val);
	}
	else if (lastpos / 2 < posnode)
	{
		while (stack->pile_tmpa->valeur != val)
		{
			ft_rratmp(stack);
			i++;
		}
		ft_tmpbfindpeer(stack, val);
	}
	return (i);
}

int	ft_find_cheapest(t_stack *stack)
{
	int		i;
	int		tmp_valeur;
	t_pile	*tmp;
	int		tmpval;
	int		tmp_i;

	i = 1000;
	ft_fill_tmp(stack);
	tmp = stack->pile_tmpa;
	tmp_valeur = tmp->valeur;
	while (tmp != NULL)
	{
		ft_fill_tmp(stack);
		tmp_i = ft_turkish_tmp(stack, tmp_valeur);
		if (i > tmp_i)
		{
			i = tmp_i;
			tmpval = tmp_valeur;
		}
		tmp = tmp->next;
		if (tmp != NULL)
		{
			tmp_valeur = tmp->valeur;
		}
	}
	return (tmpval);
}

int	ft_sort_lbig(t_stack *stack)
{
	int	tmp_valeur;

	ft_pushmix(stack);
	if (stack->pile_b->valeur < stack->pile_b->next->valeur)
		ft_rb(stack, 0);
	while (ft_size(&(stack->pile_a)) > 3)
	{
		tmp_valeur = ft_find_cheapest(stack);
		free_stack(&(stack->pile_tmpa));
		free_stack(&(stack->pile_tmpb));
		ft_turkish(stack, tmp_valeur);
	}
	ft_sort_small(stack);
	if (ft_int_lastb(stack) > stack->pile_b->valeur)
		ft_rrb(stack, 0);
	ft_pa(stack);
	while (stack->pile_b != NULL)
	{
		if (stack->pile_b->valeur < ft_int_lasta(stack)
			&& stack->pile_b->next != NULL)
			ft_rra(stack, 0);
		else
			ft_pa(stack);
	}
	if (ft_int_lasta(stack) > stack->pile_a->valeur
		&& ft_int_lasta(stack) < stack->pile_a->next->valeur)
	{
		ft_rra(stack, 0);
		ft_sa(stack, 0);
	}
	return (0);
}

/*
Trouver le nombre avec le moins de points possible,
	rb/rrb ra/rra en fonction de la pos et comparer a chaque fois
cheap: i = nbr de mouvements
*/
