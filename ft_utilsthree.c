/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilsthree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalounic <yalounic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:44:51 by yalounic          #+#    #+#             */
/*   Updated: 2024/03/14 20:38:55 by yalounic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_intmax(t_stack *stack)
{
	int		max;
	t_pile	*tmp;

	tmp = stack->pile_a;
	max = tmp->valeur;
	while (tmp != NULL)
	{
		if (tmp->valeur > max)
			max = tmp->valeur;
		tmp = tmp->next;
	}
	return (max);
}

int	ft_intmin(t_stack *stack)
{
	int		min;
	t_pile	*tmp;

	tmp = stack->pile_a;
	min = tmp->valeur;
	while (tmp != NULL)
	{
		if (tmp->valeur < min)
			min = tmp->valeur;
		tmp = tmp->next;
	}
	return (min);
}

void	ft_pushmix(t_stack *stack)
{
	int	max;
	int	min;

	max = ft_intmax(stack);
	min = ft_intmin(stack);
	if (ft_pos_last(stack) / 2 >= ft_pos_node(stack, max))
	{
		while (stack->pile_a->valeur != max)
			ft_ra(stack, 0);
	}
	else if (ft_pos_last(stack) / 2 < ft_pos_node(stack, max))
	{
		while (stack->pile_a->valeur != max)
			ft_rra(stack, 0);
	}
	ft_pb(stack);
	if (ft_pos_last(stack) / 2 >= ft_pos_node(stack, min))
	{
		while (stack->pile_a->valeur != min)
			ft_ra(stack, 0);
	}
	else if (ft_pos_last(stack) / 2 < ft_pos_node(stack, min))
	{
		while (stack->pile_a->valeur != min)
			ft_rra(stack, 0);
	}
	ft_pb(stack);
}

int	ft_maxstack(t_pile **stack)
{
	int		tmp_valeur;
	t_pile	*tmp;

	tmp = *stack;
	tmp_valeur = tmp->valeur;
	while (tmp->next != NULL)
	{
		if (tmp_valeur < tmp->next->valeur)
		{
			tmp_valeur = tmp->next->valeur;
		}
		tmp = tmp->next;
	}
	return (tmp_valeur);
}

void	dell_value(t_pile **stack, int value)
{
	t_pile	*tmp;
	t_pile	*del;

	tmp = *stack;
	while (tmp != NULL && tmp->next != NULL && tmp->next->valeur != value)
	{
		tmp = tmp->next;
	}
	if (tmp->next == NULL)
	{
		if (tmp->valeur == value)
		{
			free(tmp);
			*stack = NULL;
		}
		else
			return ;
	}
	del = tmp->next;
	tmp->next = tmp->next->next;
	free(del);
}
