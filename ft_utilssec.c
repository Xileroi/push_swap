/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilssec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalounic <yalounic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:00:10 by yalounic          #+#    #+#             */
/*   Updated: 2024/02/22 19:14:24 by yalounic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_fill_tmp(t_stack *stack)
{
	if (stack->pile_tmpa != NULL)
		free(stack->pile_tmpa);
	stack->pile_tmpa = stack->pile_a;
	if (stack->pile_tmpb != NULL)
		free(stack->pile_tmpb);
	stack->pile_tmpb = stack->pile_b;
}

int	ft_pos_node(t_stack *stack, int node)
{
	int		tmp_valeur;
	int		i;
	t_pile	*tmp;

	tmp = stack->pile_a;
	tmp_valeur = tmp->valeur;
	i = 0;
	while (tmp->next != node)
	{
		tmp = tmp->next;
		tmp_valeur = tmp->valeur;
		i++;
	}
	return (i);
}

int	ft_pos_last(t_stack *stack)
{
	int		tmp_valeur;
	int		i;
	t_pile	*tmp;

	tmp = stack->pile_a;
	tmp_valeur = tmp->valeur;
	i = 0;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		tmp_valeur = tmp->valeur;
		i++;
	}
	return (i);
}
