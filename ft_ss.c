/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ss.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalounic <yalounic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:35:36 by yalounic          #+#    #+#             */
/*   Updated: 2024/02/25 14:40:58 by yalounic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack *stack, int i)
{
	int		tmp_valeur;
	t_pile	*tmp;

	if (stack->pile_a == NULL)
		return ;
	tmp = stack->pile_a;
	tmp_valeur = tmp->valeur;
	tmp->valeur = tmp->next->valeur;
	tmp->next->valeur = tmp_valeur;
	if (i == 0)
		printf("sa\n");
}

void	ft_sb(t_stack *stack, int i)
{
	int		tmp_valeur;
	t_pile	*tmp;

	if (stack->pile_b == NULL)
		return ;
	tmp = stack->pile_b;
	tmp_valeur = tmp->valeur;
	tmp->valeur = tmp->next->valeur;
	tmp->next->valeur = tmp_valeur;
	if (i == 0)
		printf("sb\n");
}

void	ft_sbtmp(t_stack *stack)
{
	int		tmp_valeur;
	t_pile	*tmp;

	if (stack->pile_tmpb == NULL)
		return ;
	tmp = stack->pile_tmpb;
	tmp_valeur = tmp->valeur;
	tmp->valeur = tmp->next->valeur;
	tmp->next->valeur = tmp_valeur;
}

void	ft_ss(t_stack *stack)
{
	ft_sa(stack, 1);
	ft_sb(stack, 1);
	printf("ss\n");
}
