/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilsthree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalounic <yalounic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:44:51 by yalounic          #+#    #+#             */
/*   Updated: 2024/03/14 16:51:23 by yalounic         ###   ########.fr       */
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
	int	i;

	max = ft_intmax(stack);
	min = ft_intmin(stack);
	i = 0;
	while (i != 2)
	{
		if (stack->pile_a->valeur == max)
		{
			ft_pb(stack);
			i++;
		}
		else if (stack->pile_a->valeur == min)
		{
			ft_pb(stack);
			i++;
		}
		else
			ft_ra(stack, 0);
	}
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
