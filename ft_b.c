/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_b.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalounic <yalounic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:35:40 by yalounic          #+#    #+#             */
/*   Updated: 2024/01/25 18:36:09 by yalounic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sb(t_pile **stack)
{
	int		tmp_valeur;
	t_pile	*tmp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = *stack;
	tmp_valeur = tmp->valeur;
	tmp->valeur = tmp->next->valeur;
	tmp->next->valeur = tmp_valeur;
	printf("sb\n");
}
