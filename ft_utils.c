/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalounic <yalounic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 06:30:04 by yalounic          #+#    #+#             */
/*   Updated: 2024/03/19 22:19:34 by yalounic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	i;
	int	res;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (sign * res);
}

static void	ft_raf(t_stack *stack, int i)
{
	if (i == 0)
	{
		ft_sb(stack, 0);
		ft_rra(stack, 0);
		ft_pa(stack);
		ft_pa(stack);
		ft_ra(stack, 0);
		ft_ra(stack, 0);
		ft_ra(stack, 0);
	}
	else
	{
		ft_rra(stack, 0);
		ft_sb(stack, 0);
		ft_pa(stack);
		ft_pa(stack);
		ft_ra(stack, 0);
		ft_ra(stack, 0);
		ft_ra(stack, 0);
	}
}

void	ft_fixthis(t_stack *stack)
{
	if (stack->pile_a->valeur > stack->pile_b->valeur
		&& stack->pile_a->valeur > stack->pile_b->next->valeur)
	{
		ft_raf(stack, 0);
		return ;
	}
	else if (stack->pile_a->next->next->valeur > stack->pile_b->valeur
		&& stack->pile_a->next->next->valeur > stack->pile_b->next->valeur)
	{
		ft_raf(stack, 1);
		return ;
	}
	if (stack->pile_b->valeur > stack->pile_a->next->next->valeur
		&& stack->pile_b->valeur < stack->pile_a->next->next->next->valeur)
		ft_fixthis(stack);
	ft_rra(stack, 0);
	ft_pa(stack);
	ft_ra(stack, 0);
	ft_ra(stack, 0);
}

int	ft_int_lasta(t_stack *stack)
{
	int		tmp_valeur;
	t_pile	*tmp;

	tmp = stack->pile_a;
	tmp_valeur = tmp->valeur;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		tmp_valeur = tmp->valeur;
	}
	return (tmp_valeur);
}

int	ft_int_lastb(t_stack *stack)
{
	int		tmp_valeur;
	t_pile	*tmp;

	tmp = stack->pile_b;
	tmp_valeur = tmp->valeur;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		tmp_valeur = tmp->valeur;
	}
	return (tmp_valeur);
}
