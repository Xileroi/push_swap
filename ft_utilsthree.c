/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilsthree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalounic <yalounic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:44:51 by yalounic          #+#    #+#             */
/*   Updated: 2024/03/01 18:05:09 by yalounic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_intmax(t_stack *stack)
{
    int max;
    t_pile *tmp;

    tmp = stack->pile_a;
    max = tmp->valeur;
    while (tmp != NULL)
    {
        if (tmp->valeur > max)
            max = tmp->valeur;
        tmp = tmp->next;
    }
    return (max);
}

int ft_intmin(t_stack *stack)
{
    int min;
    t_pile *tmp;

    tmp = stack->pile_a;
    min = tmp->valeur;
    while (tmp != NULL)
    {
        if (tmp->valeur < min)
            min = tmp->valeur;
        tmp = tmp->next;
    }
    return (min);
}

void    ft_pushmix(t_stack *stack)
{
    int max;
    int min;
    int i;

    max = ft_intmax(stack);
    min = ft_intmin(stack);
    i = 0;
    while (i != 2)
    {
        if (stack->pile_a->valeur == max)
        {
            ft_pb(stack);
            i++;
        }
        else if (stack->pile_a->valeur == min)
        {
            ft_pb(stack);
            i++;
        }
        ft_ra(stack, 0);
    }
}
