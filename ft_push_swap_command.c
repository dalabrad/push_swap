/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_command.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalabrad <dalabrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:57:04 by dalabrad          #+#    #+#             */
/*   Updated: 2024/05/31 12:53:49 by dalabrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Rotates both stacks until:
 * 		~ Cheapest_node->target_node reaches top in stack a
 * 		~ Cheapest_node tops in stack b
*/
static void	ft_rotate_both(t_stack_node **a, t_stack_node **b,
					t_stack_node *cheapest_node)
{
	if (!a || !*a || !b || !*b || !cheapest_node)
		return ;
	while (*a != cheapest_node->target_node && *b != cheapest_node)
		ft_rr(a, b, false);
	ft_set_index(*a);
	ft_set_index(*b);
}

/*
 * Reverse rotates both stacks until:
 * 		~ Cheapest_node->target_node reaches top in stack a
 * 		~ Cheapest_node tops in stack b
*/
static void	ft_reverse_rotate_both(t_stack_node **a, t_stack_node **b,
					t_stack_node *cheapest_node)
{
	if (!a || !*a || !b || !*b || !cheapest_node)
		return ;
	while (*a != cheapest_node->target_node && *b != cheapest_node)
		ft_rrr(a, b, false);
	ft_set_index(*a);
	ft_set_index(*b);
}

/*
 * Finish rotating the stacks individually, needs :
 * 		~ t_node_stack	**stack = &a or &b 
 * 		~ t_node_stack	*top_node = node that should end on top
 * 			- cheapest_node->target_node (a stack)
 * 			- cheapest_node              (b stack)
 * 		~ char stack_name = a or b
*/
void	ft_finish_rotation(t_stack_node **stack, t_stack_node *top_node,
					char stack_name)
{
	if (!stack || !*stack || !top_node
		|| (stack_name < 'a' && stack_name > 'b'))
		return ;
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ft_ra(stack, false);
			else
				ft_rra(stack, false);
		}
		else
		{
			if (top_node->above_median)
				ft_rb(stack, false);
			else
				ft_rrb(stack, false);
		}
	}
}

/*
 * Push the cheapest_node from 'b' to the top of target_node in 'a'
 * with the metadata available in the node
 * 		1) Make the target nodes emerge on top of both stacks:
 * 		   cheapest_node tops b and cheapest_node->target_node tops a
 * 		2) PUSH A (pa)
*/
static void	ft_push_nodes(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	if (!a || !*a || !b || !*b)
		return ;
	cheapest_node = ft_find_cheapest(*b);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		ft_rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		ft_reverse_rotate_both(a, b, cheapest_node);
	ft_finish_rotation(b, cheapest_node, 'b');
	ft_finish_rotation(a, cheapest_node->target_node, 'a');
	ft_pa(a, b, false);
}

/*
 * ~Algorithm that pushes all nodes in B until having 3 in A
 * ~For every configuration choose the "cheapest_node"
 * ~Push everything back in A in order
*/
void	ft_push_swap(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*smallest_node;
	int				size_a;

	if (!a || !*a)
		return ;
	size_a = ft_stack_size(*a);
	if (size_a == 5)
		ft_handle_five(a, b);
	else
		while (size_a-- > 3)
			ft_pb(b, a, false);
	ft_sort_three(a);
	while (*b)
	{
		ft_init_nodes(*a, *b);
		ft_push_nodes(a, b);
	}
	ft_set_index(*a);
	smallest_node = ft_find_smallest(*a);
	if (smallest_node->above_median)
		while (*a != smallest_node)
			ft_ra(a, false);
	else
		while (*a != smallest_node)
			ft_rra(a, false);
}
