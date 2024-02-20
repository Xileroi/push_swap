/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilssec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalounic <yalounic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:00:10 by yalounic          #+#    #+#             */
/*   Updated: 2024/02/20 17:11:19 by yalounic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_fill_tmp(t_stack *stack)
{
	stack->pile_tmpa = stack->pile_a;
	stack->pile_tmpb = stack->pile_b;
}
