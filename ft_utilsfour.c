/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilsfour.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalounic <yalounic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 15:11:11 by yalounic          #+#    #+#             */
/*   Updated: 2024/03/02 15:12:15 by yalounic         ###   ########.fr       */
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
