/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilsfour.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalounic <yalounic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 15:11:11 by yalounic          #+#    #+#             */
/*   Updated: 2024/03/21 10:22:19 by yalounic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_pile **stack)
{
	t_pile	*tmp;
	t_pile	*tmp_del;

	tmp = *stack;
	while (tmp != NULL)
	{
		tmp_del = tmp;
		tmp = tmp->next;
		free(tmp_del);
	}
	*stack = NULL;
}

int	ft_pos_nodeb(t_stack *stack, int node)
{
	int		i;
	t_pile	*tmp;

	tmp = stack->pile_b;
	i = 0;
	while (tmp->valeur != node)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int	ft_intminb(t_stack *stack)
{
	int		min;
	t_pile	*tmp;

	tmp = stack->pile_b;
	min = tmp->valeur;
	while (tmp != NULL)
	{
		if (tmp->valeur < min)
			min = tmp->valeur;
		tmp = tmp->next;
	}
	return (min);
}

int	ft_pos_lastb(t_stack *stack)
{
	int		i;
	t_pile	*tmp;

	tmp = stack->pile_b;
	i = 0;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	ft_find_rpos(t_stack *stack, int lmin)
{
	int		min;
	int		rpos;
	t_pile	*tmp;
	t_pile	*tmp2;

	tmp = stack->pile_a;
	tmp2 = stack->pile_a;
	rpos = -1;
	while (rpos < ft_pos_last(stack))
	{
		min = ft_maxstack(&(stack->pile_a));
		while (tmp != NULL)
		{
			if (tmp->valeur < min && tmp->valeur > lmin)
				min = tmp->valeur;
			tmp = tmp->next;
		}
		while (tmp2->valeur != min)
			tmp2 = tmp2->next;
		tmp2->rpos = ++rpos;
		lmin = min;
		tmp = stack->pile_a;
		tmp2 = stack->pile_a;
	}
}
