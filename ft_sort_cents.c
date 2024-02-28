/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_cents.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalounic <yalounic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 02:52:30 by yalounic          #+#    #+#             */
/*   Updated: 2024/02/28 20:01:57 by yalounic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_turkish_tmp(t_stack *stack, int val)
{
	int	lastpos;
	int	posnode;
	int	i;

	lastpos = ft_pos_last(stack);
	posnode = ft_pos_node(stack, val);
	i = 0;
	/*printf("\n\na\n");
	print_stack(&stack->pile_tmpa);
	printf("\nb\n");
	print_stack(&stack->pile_tmpb);*/
	if (stack->pile_tmpa->valeur == val)
	{
		ft_tmpbfindpeer(stack, val);
		i++;
	}
	else if (lastpos / 2 >= posnode)
	{
		while (stack->pile_tmpa->valeur != val)
		{
			ft_ratmp(stack);
			i++;
		}
		ft_tmpbfindpeer(stack, val);
		i++;
	}
	else if (lastpos / 2 < posnode)
	{
		while (stack->pile_tmpa->valeur != val)
		{
			ft_rratmp(stack);
			i++;
		}
		ft_tmpbfindpeer(stack, val);
	}
	return (i);
}

	/*printf("\n\na\n");
	print_stack(&stack->pile_a);
	printf("b\n");
	print_stack(&stack->pile_b);*/

int	ft_find_cheapest(t_stack *stack)
{
    int	i;
    int		tmp_valeur;
    t_pile	*tmp;
    int	tmpval;
    int tmp_i;

    i = 1000;
    ft_fill_tmp(stack);
    tmp = stack->pile_tmpa;
    tmp_valeur = tmp->valeur;
    while (tmp != NULL)
    {
        tmp_i = ft_turkish_tmp(stack, tmp_valeur);
        if (i > tmp_i)
        {
            i = tmp_i;
            tmpval = tmp_valeur;
        }
        tmp = tmp->next;
        if (tmp != NULL)
        {
            tmp_valeur = tmp->valeur;
        }
    }
    return (tmpval); //return valeur a push
}

int	ft_sort_lbig(t_stack *stack)
{
	int tmp_valeur;

	ft_pb(stack);
	ft_pb(stack);
	if(stack->pile_b->valeur < stack->pile_b->next->valeur)
		ft_rb(stack, 0);
	while (ft_size(&(stack->pile_a)) > 3)
	{
		tmp_valeur = ft_find_cheapest(stack);
		free_stack(&(stack->pile_tmpa));
		free_stack(&(stack->pile_tmpb));
		ft_turkish(stack, tmp_valeur);
	}
	ft_sort_small(stack);
	/*while (stack->pile_b->valeur < ft_int_last(&(stack->pile_b)))
		ft_rb(stack, 0);*/
	/*while (ft_test_sort(stack) == 0 || stack->pile_b != NULL)
	{
		ft_pa(stack);
		if (stack->pile_a->valeur < stack->pile_b->valeur
			&& stack->pile_a->next->valeur > stack->pile_b->valeur)
			{
				ft_ra(stack, 0);
				ft_pa(stack);
			}
		else
			ft_ra(stack, 0);
	}*/
	printf("\n\na\n");
	print_stack(&stack->pile_a);
	printf("b\n");
	print_stack(&stack->pile_b);
	return (0);
}

/*
Trouver le nombre avec le moins de points possible, rb/rrb ra/rra en fonction de la pos et comparer a chaque fois
cheap: i = nbr de mouvements
*/
