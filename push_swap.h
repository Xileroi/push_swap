/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalounic <yalounic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:35:42 by yalounic          #+#    #+#             */
/*   Updated: 2024/01/25 18:49:04 by yalounic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_stack
{
	struct s_pile	*pile_a;
	struct s_pile	*pile_b;
}					t_stack;

typedef struct s_pile
{
	int				valeur;
	struct s_pile	*next;
}					t_pile;

void				ft_sb(t_pile **stack);
void				ft_sa(t_pile **stack);
void				push(t_pile **pile, int valeur);
t_pile				*new_pile_element(int valeur);
void				print_stack(t_pile **stack);
void				dell_value(t_pile **stack, int value);
void				free_stack(t_pile **stack);
void				ft_ss(t_stack *stack);
