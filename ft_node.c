/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalounic <yalounic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 21:05:54 by yalounic          #+#    #+#             */
/*   Updated: 2024/03/21 10:19:38 by yalounic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_findnode(t_stack *stack, int chunk)
{
	int		min;
	t_pile	*tmp;
	int		count;

	tmp = stack->pile_a;
	min = 0;
	count = 0;
	while (tmp != NULL)
	{
		if (tmp->rpos >= min && tmp->rpos <= chunk)
			return (tmp->valeur);
		count++;
		tmp = tmp->next;
	}
	return (tmp->valeur);
}

int	ft_findlnode(t_stack *stack, int chunk)
{
	int		min;
	t_pile	*tmp;
	t_pile	*tmp2;
	int		count;

	tmp = stack->pile_a;
	min = 0;
	count = 0;
	while (tmp != NULL)
	{
		if (tmp->rpos >= min && tmp->rpos <= chunk)
			tmp2 = tmp;
		count++;
		tmp = tmp->next;
	}
	return (tmp2->valeur);
}

void	ft_pushbcorr(t_stack *stack, int val)
{
	if (stack->pile_b == NULL)
		ft_pb(stack);
	else if (val > ft_maxstack(&stack->pile_b))
		ft_pb(stack);
	else if (val < ft_minstack(&stack->pile_b))
		ft_pb(stack);
	else
		ft_pushcorrl(stack, val);
}

int	ft_sizeb(t_stack *stack)
{
	int		i;
	t_pile	*tmp;

	tmp = stack->pile_b;
	i = 0;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	ft_sortbig(t_stack *stack)
{
	int	chunk;
	int	i;

	chunk = 19;
	i = -1;
	while (stack->pile_a != NULL && ft_sizea(stack) > 1)
	{
		if (stack->pile_a->rpos >= chunk)
		{
			while (stack->pile_a->rpos >= chunk)
				ft_ra(stack, 0);
		}
		ft_pb(stack);
		i++;
		if (i == chunk - 3)
			chunk = chunk + 20;
	}
	ft_pb(stack);
	ft_finalmoves(stack);
	return ;
}
