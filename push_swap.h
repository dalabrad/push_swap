/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalabrad <dalabrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:10:54 by dalabrad          #+#    #+#             */
/*   Updated: 2024/05/27 14:55:48 by dalabrad         ###   ########.fr       */
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
	int					current_position;
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

//-----------------------------------------------------------------------------
//test utils : delete before finishing the project
void			ft_print_stack(t_stack_node	*node);
void			ft_print_stack_reverse(t_stack_node	*node);
//-----------------------------------------------------------------------------
#endif