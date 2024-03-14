/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turk.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalounic <yalounic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:43:22 by yalounic          #+#    #+#             */
/*   Updated: 2024/03/14 17:43:20 by yalounic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_tmpbfindpeer(t_stack *stack, int val)
{
	t_pile	*tmp;
	int		i;

	tmp = stack->pile_tmpb;
	i = 0;
	while (tmp != NULL)
	{
		if (tmp->valeur > val && tmp->next->valeur < val)
		{
			ft_rbtmp(stack);
			i++;
			ft_pbtmp(stack);
			return (i);
		}
		else if (i > ft_pos_last(stack))
		{
			ft_pbtmp(stack);
			i++;
			return (i);
		}
		ft_rbtmp(stack);
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	ft_bfindpeer(t_stack *stack, int val)
{
	int		i;
	t_pile	*tmp;

	tmp = stack->pile_b;
	i = 0;
	while (tmp != NULL)
	{
		if (tmp->valeur > val && tmp->next->valeur < val)
		{
			ft_rb(stack, 0);
			ft_pb(stack);
			return ;
		}
		else if (i > ft_pos_last(stack))
		{
			ft_pb(stack);
			return ;
		}
		ft_rb(stack, 0);
		i++;
		tmp = tmp->next;
	}
	return ;
}

int	ft_int_last(t_pile **stack)
{
	int		tmp_valeur;
	t_pile	*tmp;

	tmp = *stack;
	tmp_valeur = tmp->valeur;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		tmp_valeur = tmp->valeur;
	}
	return (tmp_valeur);
}

void	ft_turkish(t_stack *stack)
{
	int val;

	val = stack->pile_a->valeur;
	ft_bfindpeer(stack, val);
	/*int	lastpos;
	int	posnode;

	lastpos = ft_pos_last(stack);
	posnode = ft_pos_node(stack, val);
	if (stack->pile_a->valeur == val)
	{
		ft_bfindpeer(stack, val);
	}
	else if (lastpos / 2 >= posnode)
	{
		while (stack->pile_a->valeur != val)
		{
			ft_ra(stack, 0);
		}
		ft_bfindpeer(stack, val);
	}
	else if (lastpos / 2 < posnode)
	{
		while (stack->pile_a->valeur != val)
		{
			ft_rra(stack, 0);
		}
		ft_bfindpeer(stack, val);
	}*/
}
