/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalounic <yalounic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:03:36 by yalounic          #+#    #+#             */
/*   Updated: 2024/02/01 17:01:06 by yalounic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_stack *stack, int i)
{
    t_pile *last = stack->pile_a;
    t_pile *before_last = NULL;
    
    if (stack->pile_a == NULL)
        return;
    while (last->next != NULL)
    {
        before_last = last;
        last = last->next;
    }
    before_last->next = NULL;
    last->next = stack->pile_a;
    stack->pile_a = last;
	if (i == 0)
    	printf("rra\n");
}

void    ft_rrb(t_stack *stack, int i)
{
    t_pile *last = stack->pile_b;
    t_pile *before_last = NULL;
    
    if (stack->pile_b == NULL)
        return;
    while (last->next != NULL)
    {
        before_last = last;
        last = last->next;
    }
    before_last->next = NULL;
    last->next = stack->pile_b;
    stack->pile_b = last;
    if (i == 0)
    	printf("rrb\n");
}

void	ft_rrr(t_stack *stack)
{
	ft_rra(stack, 1);
	ft_rrb(stack, 1);
	printf("rrr\n");
}
