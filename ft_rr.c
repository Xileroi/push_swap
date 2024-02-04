/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalounic <yalounic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:32:44 by yalounic          #+#    #+#             */
/*   Updated: 2024/02/04 17:47:45 by yalounic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stack *stack, int i)
{
	t_pile	*tmp;
	t_pile	*tmp2;

	if (stack->pile_a == NULL)
		return ;
	tmp = stack->pile_a;
	tmp2 = stack->pile_a->next;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = stack->pile_a;
	stack->pile_a = tmp2;
	tmp->next->next = NULL;
	if (i == 0)
		printf("ra\n");
}

void	ft_rb(t_stack *stack, int i)
{
	t_pile	*tmp;
	t_pile	*tmp2;

	if (stack->pile_b == NULL)
		return ;
	tmp = stack->pile_b;
	tmp2 = stack->pile_b->next;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = stack->pile_b;
	stack->pile_b = tmp2;
	tmp->next->next = NULL;
	if (i == 0)
		printf("rb\n");
}

void	ft_rr(t_stack *stack)
{
	ft_ra(stack, 1);
	ft_rb(stack, 1);
	printf("rr\n");
}
