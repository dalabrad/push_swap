/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalabrad <dalabrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:10:54 by dalabrad          #+#    #+#             */
/*   Updated: 2024/06/05 13:07:29 by dalabrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdbool.h>
# include <limits.h>

typedef struct s_stack_node
{
	int					value;
	int					index;
	int					final_index;
	int					push_price;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

//	ft_stack_init.c

void			ft_stack_init(t_stack_node **a, char **argv, bool flag_argc_2);

//	ft_error_free.c

void			ft_free_tab(char **tab);
void			ft_free_stack(t_stack_node **stack);
void			ft_error_free(t_stack_node **a, char **argv, bool flag_argc_2);
bool			ft_error_syntax(char *str);
bool			ft_error_repetition(t_stack_node *a, int nbr);

//	ft_stack_utils.c

t_stack_node	*ft_last_node(t_stack_node *node);
void			ft_append_node(t_stack_node **stack, int nbr);
int				ft_stack_size(t_stack_node *node);
t_stack_node	*ft_find_smallest(t_stack_node *node);
t_stack_node	*ft_find_cheapest(t_stack_node *node);

//	ft_push_command.c

void			ft_pa(t_stack_node **a, t_stack_node **b, bool checker);
void			ft_pb(t_stack_node **b, t_stack_node **a, bool checker);

//	ft_swap_command.c

void			ft_sa(t_stack_node	**a, bool checker);
void			ft_sb(t_stack_node	**b, bool checker);
void			ft_ss(t_stack_node	**a, t_stack_node	**b, bool checker);

//ft_rotate_command.c

void			ft_ra(t_stack_node **a, bool checker);
void			ft_rb(t_stack_node **b, bool checker);
void			ft_rr(t_stack_node **a, t_stack_node **b, bool checker);

//ft_reverse_rotate_command.c

void			ft_rra(t_stack_node **a, bool checker);
void			ft_rrb(t_stack_node **b, bool checker);
void			ft_rrr(t_stack_node **a, t_stack_node **b, bool checker);

//ft_sort_3_handle_5.c

bool			ft_stack_sorted(t_stack_node *node);
void			ft_sort_three(t_stack_node **a);
void			ft_handle_five(t_stack_node **a, t_stack_node **b);

//ft_push_swap_init.c

void			ft_set_index(t_stack_node *stack);
void			ft_set_price(t_stack_node *a, t_stack_node *b);
void			ft_set_cheapest(t_stack_node *b);
void			ft_init_nodes(t_stack_node *a, t_stack_node *b);

//ft_push_swap_utils.c 

int				ft_max(int n, int m);
bool			ft_both_ab_median(t_stack_node *b);
void			ft_print_stack(t_stack_node	*node);
void			ft_print_stack_reverse(t_stack_node	*node);

//ft_push_swap_command.c

void			ft_finish_rotation(t_stack_node **stack, t_stack_node *top_node,
					char stack_name);
void			ft_push_swap(t_stack_node **a, t_stack_node **b);

#endif