/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalounic <yalounic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:03:11 by yalounic          #+#    #+#             */
/*   Updated: 2024/02/10 05:13:44 by yalounic         ###   ########.fr       */
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
			return (0);
		}
		tmp = tmp->next;
		tmp_valeur = tmp->valeur;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int		i = 0;
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
	while (argv[i])
		i++;
	i -= 1;
	while (i != 0)
	{
		push(&(stack->pile_a), ft_atoi(argv[i]));
		i--;
	}
	//print_stack(stack);
	if (ft_test_sort(stack) == 1)
	{
		return (0);
		//printf("Already sorted\n");
	}
	else
		ft_sort_small(stack);
	/*if (ft_test_sort(stack) == 0)
	{
		printf("Pas bon\n");
	}*/
	//print_stack(stack);
	free_stack(&(stack->pile_a));
	free_stack(&(stack->pile_b));
	free(stack);
	return (0);
}
