/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalounic <yalounic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:32:44 by yalounic          #+#    #+#             */
/*   Updated: 2024/03/19 21:17:30 by yalounic         ###   ########.fr       */
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
		write(1, "ra\n", 3);
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
		write(1, "rb\n", 3);
}

void	ft_rr(t_stack *stack)
{
	ft_ra(stack, 1);
	ft_rb(stack, 1);
	write(1, "rr\n", 3);
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_freeall(t_stack *stack)
{
	t_pile	*tmp;
	t_pile	*tmp2;

	tmp = stack->pile_a;
	while (tmp)
	{
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
	tmp = stack->pile_b;
	while (tmp)
	{
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
	free(stack);
}
