/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_3_handle_5.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalabrad <dalabrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:35:18 by dalabrad          #+#    #+#             */
/*   Updated: 2024/05/30 16:24:45 by dalabrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Function returns true if a given stack is sorted from lower
 * values to higher values returns false if not sorted.
*/
bool	ft_stack_sorted(t_stack_node *node)
{
	if (!node)
		return (true);
	while (node->next)
	{
		if (node->value > node->next->value)
			return (false);
		node = node->next;
	}
	return (true);
}

/*
 * Functions returns a pointer to the node with the highest value.
*/
static t_stack_node	*ft_find_highest(t_stack_node *node)
{
	int				highest;
	t_stack_node	*highest_node;

	if (!node)
		return (NULL);
	highest = INT_MIN;
	highest_node = NULL;
	while (node)
	{
		if (node->value > highest)
		{
			highest = node->value;
			highest_node = node;
		}
		node = node->next;
	}
	return (highest_node);
}

/*
 * Functions sorts a stack of 3 nodes. 
 * I use the parameter (a) instead of (stack) because the sorting of
 * 3 nodes is always going to occur in the stack a of push_swap!!!
 * Thus I  only use the ra, rra and sa functions.
 * 		~ If 1st node is highest => ra 
 * 			(biggest to the bottom)
 * 		~ Else if 2nd node is highest => rra 
 * 			(bottom node to top => highgest drops to bottom)
 * 		~ Else highest is in bottom
 * 		~ Now that highest is in bottom I have to check 
 * 		  the two remaining nodes to sort them.
*/
void	ft_sort_three(t_stack_node **a)
{
	t_stack_node	*highest_node;

	if (!a || !*a || ft_stack_size(*a) != 3)
		return ;
	highest_node = ft_find_highest(*a);
	if (*a == highest_node)
		ft_ra(a, false);
	else if ((*a)->next == highest_node)
		ft_rra(a, false);
	if ((*a)->value > (*a)->next->value)
		ft_sa(a, false);
}

/*
 * Function to handle a stack of 5 nodes before
 * the main algorithm in push_swap_command
*/
void	ft_handle_five(t_stack_node **a, t_stack_node **b)
{
	if (!a || !*a || ft_stack_size(*a) != 5)
		return ;
	while (ft_stack_size(*a) > 3)
	{
		ft_init_nodes(*a, *b);
		ft_finish_rotation(a, ft_find_smallest(*a), 'a');
		ft_pb(b, a, false);
	}
}
