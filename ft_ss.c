/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ss.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalounic <yalounic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:35:36 by yalounic          #+#    #+#             */
/*   Updated: 2024/03/21 09:15:36 by yalounic         ###   ########.fr       */
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
		write(1, "sa\n", 3);
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
		write(1, "sb\n", 3);
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
	write(1, "ss\n", 3);
}

void	ft_error(t_stack *stack, int i)
{
	if (i == 1)
		ft_putstr("Error\n");
	ft_freeall(stack);
	exit(1);
}
