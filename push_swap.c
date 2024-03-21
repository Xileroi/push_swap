/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalounic <yalounic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:03:11 by yalounic          #+#    #+#             */
/*   Updated: 2024/03/21 12:14:27 by yalounic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*new_pile_element(int valeur)
{
	t_pile	*newelement;

	newelement = (t_pile *)malloc(sizeof(t_pile));
	if (newelement == NULL)
		return (NULL);
	newelement->valeur = valeur;
	newelement->next = NULL;
	return (newelement);
}

void	push(t_pile **pile, int valeur)
{
	t_pile	*newelement;

	newelement = new_pile_element(valeur);
	if (newelement == NULL)
		return ;
	newelement->rpos = 0;
	newelement->next = *pile;
	*pile = newelement;
}

int	ft_test_sort(t_stack *stack)
{
	t_pile	*tmp;

	tmp = stack->pile_a;
	while (tmp->next != NULL)
	{
		if (tmp->valeur > tmp->next->valeur)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	ft_minstack(t_pile **stack)
{
	int		tmp_valeur;
	t_pile	*tmp;

	tmp = *stack;
	tmp_valeur = tmp->valeur;
	while (tmp->next != NULL)
	{
		if (tmp_valeur > tmp->next->valeur)
			tmp_valeur = tmp->next->valeur;
		tmp = tmp->next;
	}
	return (tmp_valeur);
}

int	main(int argc, char **argv)
{
	t_stack	*stack;

	if (argc <= 1)
		return (0);
	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == NULL)
	{
		free(stack);
		return (0);
	}
	stack->pile_a = NULL;
	stack->pile_b = NULL;
	if (argc == 2)
		ft_parse(stack, argv[1]);
	else
		ft_nparse(stack, argv);
	if (ft_parse_double(stack) == 1)
		ft_error(stack, 1);
	ft_find_rpos(stack, -1);
	ft_start(stack);
	return (0);
}
