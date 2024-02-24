/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalounic <yalounic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:35:42 by yalounic          #+#    #+#             */
/*   Updated: 2024/02/24 17:06:16 by yalounic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_stack
{
	struct s_pile	*pile_tmpa;
	struct s_pile	*pile_tmpb;
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
int					ft_test_sort(t_stack *stack);
char				**ft_split(const char *s, char c);
int					ft_atoi(const char *str);
void				ft_fixthis(t_stack *stack);
int					ft_find_firstnum(t_stack *stack, int chunk);
int					ft_int_lasta(t_stack *stack);
int					ft_int_lastb(t_stack *stack);
void				ft_fill_tmp(t_stack *stack);
int					ft_pos_node(t_stack *stack, int node);
int					ft_pos_last(t_stack *stack);
int	ft_sort_lbig(t_stack *stack);
void	ft_pbtmp(t_stack *stack);
void	ft_patmp(t_stack *stack);
void	ft_ratmp(t_stack *stack);
void	ft_rbtmp(t_stack *stack);
void	ft_rratmp(t_stack *stack);
void	ft_rrbtmp(t_stack *stack);
