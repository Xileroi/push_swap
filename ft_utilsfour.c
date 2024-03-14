/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilsfour.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalounic <yalounic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 15:11:11 by yalounic          #+#    #+#             */
/*   Updated: 2024/03/14 17:26:06 by yalounic         ###   ########.fr       */
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
