/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalounic <yalounic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 21:05:54 by yalounic          #+#    #+#             */
/*   Updated: 2024/03/18 22:36:31 by yalounic         ###   ########.fr       */
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
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (stack->pile_b == NULL)
		ft_pb(stack);
	else if (val > ft_maxstack(&stack->pile_b))
		ft_pb(stack);
	else if (val < ft_minstack(&stack->pile_b))
		ft_pb(stack);
	else
	{
		while (j != 1)
		{
			if (stack->pile_b->valeur > val
				&& stack->pile_b->next->valeur < val)
			{
				ft_rb(stack, 0);
				ft_pb(stack);
				j = 1;
			}
			else
			{
				ft_rb(stack, 0);
				i++;
			}
		}
		while (i > 0)
		{
			ft_rrb(stack, 0);
			i--;
		}
		return ;
	}
}

int ft_sizeb(t_stack *stack)
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
	int	max;
	int	i;

	chunk = 19;
	i = -1;
	while (stack->pile_a != NULL && ft_sizea(stack) > 1)
	{
		while (stack->pile_a->rpos > chunk)
			ft_ra(stack, 0);
		ft_pb(stack);
		i++;
		if (i == chunk - 3)
			chunk = chunk + 20;
	}
	ft_pb(stack);

	while (stack->pile_b != NULL)
	{
		max = ft_maxstack(&stack->pile_b);
		if (ft_sizeb(stack) / 2 >= ft_pos_nodeb(stack, max))
		{
			while (stack->pile_b->valeur != max)
				ft_rb(stack, 0);
			ft_pa(stack);
		}
		else if (ft_sizeb(stack) / 2 < ft_pos_nodeb(stack, max))
		{
			while (stack->pile_b->valeur != max)
				ft_rrb(stack, 0);
			ft_pa(stack);
		}
	}
	return ;
}

/*lnode = ft_findlnode(stack, chunk);
		node = ft_findnode(stack, chunk);
		if (ft_sizea(stack) / 2 >= ft_pos_node(stack, node))
		{
			while (stack->pile_a->valeur != node)
				ft_ra(stack, 0);
			ft_pushbcorr(stack, node);
			i++;
		}
		if (ft_sizea(stack) / 2 < ft_pos_node(stack, lnode))
		{
			while (stack->pile_a->valeur != lnode)
				ft_rra(stack, 0);
			ft_pushbcorr(stack, lnode);
			i++;
		}*/
