/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalabrad <dalabrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:38:31 by dalabrad          #+#    #+#             */
/*   Updated: 2024/06/05 12:59:39 by dalabrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Set the current position (index) of every node in
 * the current state-configuration given the first one
 * and the above_median bool parameter of the struct.
 * Sets:
 *      ~ node->index (int)
 *      ~ node->above_median (bool)
 *         (node previous or = to the middle index)
 *      
*/
void	ft_set_index(t_stack_node *node)
{
	int	i;
	int	center_index;

	if (!node)
		return ;
	center_index = ft_stack_size(node) / 2;
	i = 0;
	while (node)
	{
		node->index = i;
		if (i <= center_index)
			node->above_median = true;
		else
			node->above_median = false;
		node = node->next;
		i++;
	}
}

/*
 *	Sets the best match:
 *   | "The Smallest-bigger value" |
 *
 *  if no node is Bigger, best_match is the Smallest node.
 *  With this function every node in b gets its target node in a
*/
static void	ft_set_target_node(t_stack_node *a,
							t_stack_node *b)
{
	t_stack_node	*tmp_a;
	t_stack_node	*target_node;
	long			best_match;

	while (b)
	{
		best_match = LONG_MAX;
		tmp_a = a;
		while (tmp_a)
		{
			if (tmp_a->value > b->value && tmp_a->value < best_match)
			{
				target_node = tmp_a;
				best_match = tmp_a->value;
			}
			tmp_a = tmp_a->next;
		}
		if (best_match == LONG_MAX)
			b->target_node = ft_find_smallest(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

/*
 * Set the prices to push the node
 * from b -> a
 * The price checks for the relative positions in the stack
 * for every node, setting the respective price
 * 		~ If node->above_median calculates the 
 * 		  cost of doing rotation = node->index
 * 		~ If !(node->above_median) calculates the cost of doing 
 * 		  reverse rotation = size_of_stack - node->index
 * Is important to set beforehand:
 * 		~ (bool) node->above_median.
 * 		~ (t_stack_node *) node->target_node.
*/
void	ft_set_price(t_stack_node *a, t_stack_node *b)
{
	int	s_a;
	int	s_b;

	if (!b || !a)
		return ;
	s_a = ft_stack_size(a);
	s_b = ft_stack_size(b);
	while (b)
	{
		if (ft_both_ab_median(b) && b->above_median == true)
			b->push_price = ft_max(b->index, b->target_node->index);
		else if (ft_both_ab_median(b) && b->above_median == false)
			b->push_price = ft_max(s_b - b->index, s_a - b->target_node->index);
		else
		{
			b->push_price = b->index;
			if (!(b->above_median))
				b->push_price = s_b - b->index;
			if (b->target_node->above_median)
				b->push_price += b->target_node->index;
			else
				b->push_price += s_a - b->target_node->index;
		}
		b = b->next;
	}
}

/*
 * Flag the cheapest node in the current
 * stacks configurations
*/
void	ft_set_cheapest(t_stack_node *b)
{
	long			cheapest_price;
	t_stack_node	*cheapest_node;

	if (!b)
		return ;
	cheapest_price = LONG_MAX;
	while (b)
	{
		b->cheapest = false;
		if (b->push_price < cheapest_price)
		{
			cheapest_price = b->push_price;
			cheapest_node = b;
		}
		b = b->next;
	}
	cheapest_node->cheapest = true;
}

/*
 * All the necessary values to make the push
 * 		~Relative Positions (Index)
 * 		~Target node, the b node to make emerge
 * 		~Price for every configuration
 * 		~Cheapest in the current configuration
*/
void	ft_init_nodes(t_stack_node *a, t_stack_node *b)
{
	ft_set_index(a);
	ft_set_index(b);
	ft_set_target_node(a, b);
	ft_set_price(a, b);
	ft_set_cheapest(b);
}
