/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalounic <yalounic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:03:11 by yalounic          #+#    #+#             */
/*   Updated: 2024/03/02 15:40:33 by yalounic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*new_pile_element(int valeur)
{
	t_pile	*newelement;

	newelement = (t_pile *)malloc(sizeof(t_pile));
	if (newelement == NULL)
	{
		return (NULL);
	}
	newelement->valeur = valeur;
	newelement->next = NULL;
	return (newelement);
}

void	push(t_pile **pile, int valeur)
{
	t_pile	*newelement;

	newelement = new_pile_element(valeur);
	if (newelement == NULL)
	{
		return ;
	}
	newelement->next = *pile;
	*pile = newelement;
}

int	ft_test_sort(t_stack *stack)
{
	int		tmp_valeur;
	t_pile	*tmp;

	tmp = stack->pile_a;
	tmp_valeur = tmp->valeur;
	while (tmp->next != NULL)
	{
		if (tmp->valeur > tmp->next->valeur)
		{
			return (0);
		}
		tmp = tmp->next;
		tmp_valeur = tmp->valeur;
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
		{
			tmp_valeur = tmp->next->valeur;
		}
		tmp = tmp->next;
	}
	return (tmp_valeur);
}

// INTAX MIN, int, doubles

int	main(int argc, char **argv)
{
	int		i;
	t_stack	*stack;

	i = 0;
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
	while (argv[i])
		i++;
	i -= 1;
	while (i != 0)
	{
		push(&(stack->pile_a), ft_atoi(argv[i]));
		i--;
	}
	if (ft_test_sort(stack) == 1)
		return (0);
	else if (argc == 4)
		ft_sort_small(stack);
	else if (argc == 6)
		ft_sort_five(stack);
	else
		ft_sort_lbig(stack);
	if (ft_test_sort(stack) == 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&(stack->pile_a));
	free_stack(&(stack->pile_b));
	free(stack);
	return (0);
}

/*
The grade depends on how efficient the program's sorting process is.
    Sorting 3 values: no more than 3 actions.
    Sorting 5 values: no more than 12 actions.
    Sorting 100 values: rating from 1 to 5 points depending on the number of actions:
        5 points for less than 700 actions
        4 points for less than 900
        3 points for less than 1100
        2 points for less than 1300
        1 point for less than 1500
    Sorting 500 values: rating from 1 to 5 points depending on the number of actions:
        5 points for less than 5500 actions
        4 points for less than 7000
        3 points for less than 8500
        2 points for less than 10000
        1 point for less than 11500
*/
