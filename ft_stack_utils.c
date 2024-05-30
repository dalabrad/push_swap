/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalabrad <dalabrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:06:59 by dalabrad          #+#    #+#             */
/*   Updated: 2024/05/30 11:37:16 by dalabrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 *
 * Function returns the last node of a linked list
 * 
*/
t_stack_node	*ft_last_node(t_stack_node *node)
{
	if (!node)
		return (NULL);
	while (node->next)
		node = node->next;
	return (node);
}

/*
 *
 * Function appends a node->value = nbr to the stack
 * 
*/
void	ft_append_node(t_stack_node **stack, int nbr)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (!stack)
		return ;
	node = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	node->next = NULL;
	node->value = nbr;
	if (!*stack)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = ft_last_node(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

/*
 *
 * Functions returns the size (number of nodes) of
 * the stack given the first node.
 * 
*/
int	ft_stack_size(t_stack_node *node)
{
	int	size;

	if (!node)
		return (0);
	size = 0;
	while (node)
	{
		size++;
		node = node->next;
	}
	return (size);
}

/*
 *
 * Functions returns the pointer to the node
 * with the smallest value.
 * 
*/
t_stack_node	*ft_find_smallest(t_stack_node *node)
{
	t_stack_node	*smallest_node;
	long			smallest_value;

	if (!node)
		return (NULL);
	smallest_value = LONG_MAX;
	while (node)
	{
		if (node->value < smallest_value)
		{
			smallest_node = node;
			smallest_value = node->value;
		}
		node = node->next;
	}
	return (smallest_node);
}

t_stack_node	*ft_find_cheapest(t_stack_node *node)
{
	if (!node)
		return (NULL);
	while (node)
	{
		if (node->cheapest)
			return (node);
		node = node->next;
	}
	return (NULL);
}
