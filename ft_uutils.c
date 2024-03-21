/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalounic <yalounic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 22:11:55 by yalounic          #+#    #+#             */
/*   Updated: 2024/03/21 09:56:03 by yalounic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_start(t_stack *stack)
{
	if (ft_test_sort(stack) == 1)
	{
		ft_freeall(stack);
		return ;
	}
	else if (ft_sizea(stack) == 2)
		ft_sa(stack, 0);
	else if (ft_sizea(stack) == 3)
		ft_sort_small(stack);
	else if (ft_sizea(stack) == 5)
		ft_sort_five(stack);
	else
		ft_sortbig(stack);
	ft_freeall(stack);
}

void	ft_finalmoves(t_stack *stack)
{
	int	max;

	while (stack->pile_b != NULL)
	{
		max = ft_maxstack(&stack->pile_b);
		if (ft_sizeb(stack) / 2 >= ft_pos_nodeb(stack, max))
		{
			while (stack->pile_b->valeur != max)
				ft_rb(stack, 0);
			ft_pa(stack);
		}
		else if (ft_sizeb(stack) / 2 < ft_pos_nodeb(stack, max))
		{
			while (stack->pile_b->valeur != max)
				ft_rrb(stack, 0);
			ft_pa(stack);
		}
	}
}

void	ft_pushcorrl(t_stack *stack, int val)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j != 1)
	{
		if (stack->pile_b->valeur > val && stack->pile_b->next->valeur < val)
		{
			ft_rb(stack, 0);
			ft_pb(stack);
			j = 1;
		}
		else
		{
			ft_rb(stack, 0);
			i++;
		}
	}
	while (i > 0)
	{
		ft_rrb(stack, 0);
		i--;
	}
	return ;
}
