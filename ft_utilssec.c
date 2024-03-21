/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilssec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalounic <yalounic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:00:10 by yalounic          #+#    #+#             */
/*   Updated: 2024/03/19 22:18:48 by yalounic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	ft_sizea(t_stack *stack)
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

int	ft_int_last(t_pile **stack)
{
	int		tmp_valeur;
	t_pile	*tmp;

	tmp = *stack;
	tmp_valeur = tmp->valeur;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		tmp_valeur = tmp->valeur;
	}
	return (tmp_valeur);
}

void	ft_parse(t_stack *stack, char *str)
{
	char	**tab;
	int		i;

	tab = ft_split(str, ' ');
	i = 0;
	while (tab[i] != NULL)
	{
		push(&stack->pile_a, ft_atoi(tab[i]));
		i++;
	}
	ft_free_tab(tab);
}
