/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalounic <yalounic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:35:42 by yalounic          #+#    #+#             */
/*   Updated: 2024/02/04 17:15:00 by yalounic         ###   ########.fr       */
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

void				ft_sb(t_stack *stack, int i);
void				ft_sa(t_stack *stack, int i);
void				push(t_pile **pile, int valeur);
t_pile				*new_pile_element(int valeur);
void				print_stack(t_pile **stack);
void				dell_value(t_pile **stack, int value);
void				free_stack(t_pile **stack);
void				ft_ss(t_stack *stack);
void				ft_pa(t_stack *stack);
void				ft_pb(t_stack *stack);
void				ft_ra(t_stack *stack, int i);
void				ft_rb(t_stack *stack, int i);
void				ft_rr(t_stack *stack);
void				ft_rra(t_stack *stack, int i);
void				ft_rrb(t_stack *stack, int i);
void				ft_rrr(t_stack *stack);
void				ft_sort_small(t_stack *stack);
void				ft_sort_five(t_stack *stack);
