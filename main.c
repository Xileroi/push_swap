/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalounic <yalounic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:03:11 by yalounic          #+#    #+#             */
/*   Updated: 2024/03/01 19:22:01 by yalounic         ###   ########.fr       */
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

void	dell_value(t_pile **stack, int value)
{
	t_pile	*tmp;
	t_pile	*del;

	tmp = *stack;
	while (tmp != NULL && tmp->next != NULL && tmp->next->valeur != value)
	{
		tmp = tmp->next;
	}
	if (tmp->next == NULL)
	{
		if (tmp->valeur == value)
		{
			free(tmp);
			*stack = NULL;
		}
		else
			return ;
	}
	del = tmp->next;
	tmp->next = tmp->next->next;
	free(del);
}

void	print_stack(t_pile **stack)
{
	t_pile	*tmp;

	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->valeur);
		tmp = tmp->next;
	}
}

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

int	ft_maxstack(t_pile **stack)
{
	int		tmp_valeur;
	t_pile	*tmp;

	tmp = *stack;
	tmp_valeur = tmp->valeur;
	while (tmp->next != NULL)
	{
		if (tmp_valeur < tmp->next->valeur)
		{
			tmp_valeur = tmp->next->valeur;
		}
		tmp = tmp->next;
	}
	return (tmp_valeur);
}

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
	free_stack(&(stack->pile_a));
	free_stack(&(stack->pile_b));
	free(stack);
	return (0);
}
