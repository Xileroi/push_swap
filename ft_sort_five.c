/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalounic <yalounic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:36:13 by yalounic          #+#    #+#             */
/*   Updated: 2024/02/22 18:48:13 by yalounic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rsa(t_stack *stack)
{
	ft_rra(stack, 0);
	ft_sa(stack, 0);
	ft_ra(stack, 0);
	ft_ra(stack, 0);
}

static void	ft_spsp(t_stack *stack)
{
	ft_sa(stack, 0);
	ft_pb(stack);
	ft_sa(stack, 0);
	ft_pa(stack);
}

static void	ft_first_check(t_stack *stack)
{
	if (ft_test_sort(stack) == 1)
		return ;
	if (stack->pile_a->valeur < stack->pile_a->next->next->valeur
		&& stack->pile_a->valeur > stack->pile_a->next->valeur)
		ft_sa(stack, 0);
	else if (stack->pile_a->valeur < stack->pile_a->next->next->next->valeur
		&& stack->pile_a->next->next->next->valeur
		> stack->pile_a->next->next->valeur)
		ft_rsa(stack);
	else if (stack->pile_a->valeur > stack->pile_a->next->next->next->valeur)
		ft_ra(stack, 0);
	return ;
}

static void	ft_last_check(t_stack *stack)
{
	if (ft_test_sort(stack) == 1)
		return ;
	if (stack->pile_a->valeur > stack->pile_a->next->next->next->next->valeur)
		ft_ra(stack, 0);
	else if (stack->pile_a->valeur > stack->pile_a->next->valeur
		&& stack->pile_a->valeur > stack->pile_a->next->next->next->valeur)
		ft_rsa(stack);
	else if (stack->pile_a->valeur > stack->pile_a->next->next->valeur
		&& stack->pile_a->next->next->valeur
		< stack->pile_a->next->next->next->valeur)
		ft_spsp(stack);
	else if (stack->pile_a->valeur > stack->pile_a->next->valeur)
		ft_sa(stack, 0);
	if (stack->pile_a->valeur > stack->pile_a->next->next->next->next->valeur)
		ft_ra(stack, 0);
}

void	ft_sort_five(t_stack *stack)
{
	ft_pb(stack);
	ft_pb(stack);
	if (stack->pile_b->valeur > stack->pile_b->next->valeur)
		ft_sb(stack, 0);
	if (ft_test_sort(stack) == 0)
		ft_sort_small(stack);
	if (stack->pile_b->valeur > stack->pile_a->next->valeur
		&& stack->pile_b->valeur < stack->pile_a->next->next->valeur)
		ft_fixthis(stack);
	else
		ft_pa(stack);
	ft_first_check(stack);
	ft_pa(stack);
	ft_last_check(stack);
	return ;
}
