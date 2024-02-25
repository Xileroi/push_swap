/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilssec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalounic <yalounic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:00:10 by yalounic          #+#    #+#             */
/*   Updated: 2024/02/25 16:03:33 by yalounic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*copy_pile(t_pile *original)
{
    t_pile *copy = NULL;
    t_pile *tmp = NULL;
    t_pile *node = original;

    while (node != NULL)
    {
        t_pile *new_node = malloc(sizeof(t_pile));
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
    return (copy);
}

void	ft_fill_tmp(t_stack *stack)
{
    stack->pile_tmpa = copy_pile(stack->pile_a);
    stack->pile_tmpb = copy_pile(stack->pile_b);
}

int	ft_pos_node(t_stack *stack, int node)
{
	int		tmp_valeur;
	int		i;
	t_pile	*tmp;

	tmp = stack->pile_a;
	tmp_valeur = tmp->valeur;
	i = 0;
	while (tmp->valeur != node)
	{
		tmp = tmp->next;
		tmp_valeur = tmp->valeur;
		i++;
	}
	return (i);
}

int	ft_pos_last(t_stack *stack)
{
	int		tmp_valeur;
	int		i;
	t_pile	*tmp;

	tmp = stack->pile_a;
	tmp_valeur = tmp->valeur;
	i = 0;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		tmp_valeur = tmp->valeur;
		i++;
	}
	return (i);
}

int	ft_size(t_pile **stack)
{
	t_pile	*tmp;
	int		i;

	tmp = *stack;
	while (tmp != NULL)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
