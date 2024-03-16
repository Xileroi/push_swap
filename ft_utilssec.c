/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilssec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalounic <yalounic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:00:10 by yalounic          #+#    #+#             */
/*   Updated: 2024/03/15 22:02:27 by yalounic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*copy_pile(t_pile *original)
{
	t_pile	*copy;
	t_pile	*tmp;
	t_pile	*node;
	t_pile	*new_node;

	copy = NULL;
	tmp = NULL;
	node = original;
	while (node != NULL)
	{
		new_node = malloc(sizeof(t_pile));
		new_node->valeur = node->valeur;
		new_node->next = NULL;
		if (copy == NULL)
		{
			copy = new_node;
			tmp = copy;
		}
		else
		{
			tmp->next = new_node;
			tmp = tmp->next;
		}
		node = node->next;
	}
	free(node);
	return (copy);
}

void	ft_fill_tmp(t_stack *stack)
{
	if (stack->pile_tmpa != NULL)
		free_stack(&(stack->pile_tmpa));
	if (stack->pile_tmpb != NULL)
		free_stack(&(stack->pile_tmpb));
	stack->pile_tmpa = NULL;
    stack->pile_tmpb = NULL;
	stack->pile_tmpa = copy_pile(stack->pile_a);
	stack->pile_tmpb = copy_pile(stack->pile_b);
}

int	ft_pos_node(t_stack *stack, int node)
{
	int		i;
	t_pile	*tmp;

	tmp = stack->pile_a;
	i = 0;
	while (tmp->valeur != node)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int	ft_pos_last(t_stack *stack)
{
	int		i;
	t_pile	*tmp;

	tmp = stack->pile_a;
	i = 0;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int ft_sizea(t_stack *stack)
{
	int		i;
	t_pile	*tmp;

	tmp = stack->pile_a;
	i = 0;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
