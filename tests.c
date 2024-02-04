/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalounic <yalounic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:03:11 by yalounic          #+#    #+#             */
/*   Updated: 2024/02/04 17:59:22 by yalounic         ###   ########.fr       */
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

/*int add_maillon(t_pile **stack, int value)
{
	t_pile	*tmp;
	t_pile	*maillon;
	t_pile	*newElement;
	t_pile	*newelement;
	t_pile	*newelement;

	tmp = *stack;
	while (tmp != NULL && tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	maillon = malloc(sizeof(t_pile));
	if (maillon == NULL)
	{
		return (-1);
	}
	maillon->valeur = value;
	maillon->next = NULL;
	tmp->next = maillon;
}*/
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
			printf("\nKO\n");
			return (0);
		}
		tmp = tmp->next;
		tmp_valeur = tmp->valeur;
	}
	return (1);
}

int	main(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->pile_a = NULL;
	stack->pile_b = NULL;
	if (stack == NULL)
	{
		free(stack);
		return (0);
	}
	push(&(stack->pile_a), 0);
	push(&(stack->pile_a), 3);
	push(&(stack->pile_a), 1);
	push(&(stack->pile_a), 2);
	push(&(stack->pile_a), 4);
	if (ft_test_sort(stack) == 1)
		return 0;
	printf("a\n");
	print_stack(&(stack->pile_a));
	printf("\n-----------------\n\n");
	ft_sort_five(stack);
	printf("\n-----------------\n\na\n");
	print_stack(&(stack->pile_a));
	ft_test_sort(stack);
	free_stack(&(stack->pile_a));
	free_stack(&(stack->pile_b));
	free(stack);
	return (0);
}
