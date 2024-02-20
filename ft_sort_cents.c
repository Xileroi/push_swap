/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_cents.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalounic <yalounic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 02:52:30 by yalounic          #+#    #+#             */
/*   Updated: 2024/02/20 17:21:12 by yalounic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sort_lbig(t_stack *stack)
{
	ft_pb(stack);
	ft_pb(stack);
    ft_find_cheapest(stack);
}



/*
Trouver le nombre avec le moins de points possible, rb/rrb en fonction de la pos et comparer a chaque fois
cheap: i = nbr de mouvements
*/
