/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalabrad <dalabrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:21:23 by dalabrad          #+#    #+#             */
/*   Updated: 2024/06/05 13:11:34 by dalabrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Returns the maximum value of the two ints introduced*/
int	ft_max(int n, int m)
{
	if (n > m)
		return (n);
	return (m);
}

/*	
 * Returns true if node of b and its target in a are both 
 * on top or above the median.
 */
bool	ft_both_ab_median(t_stack_node *b)
{
	if (b->above_median == b->target_node->above_median)
		return (true);
	return (false);
}

/*
 * Prints a stack:
 * n[0] = value_1 -> ... -> End of the Stack. 
*/
void	ft_print_stack(t_stack_node	*node)
{
	unsigned int	i;

	i = 0;
	if (!node)
	{
		ft_printf("Empty stack\n");
		return ;
	}
	while (node)
	{
		ft_printf("n[%u] = %d --> ", i, node->value);
		node = node->next;
		i++;
	}
	ft_printf("End of Stack.\n");
}

/*
 * Prints a Stack in reverse:
 * End of the Stack. <- ... <- n[0] = value_1
*/
void	ft_print_stack_reverse(t_stack_node	*node)
{
	unsigned int	size;

	size = ft_stack_size(node);
	if (!node)
	{
		ft_printf("Empty stack\n");
		return ;
	}
	while (node->next)
	{
		node = node->next;
	}
	ft_printf("End of Stack.");
	while (node)
	{
		ft_printf(" <-- n[%d] = %d", size - 1, node->value);
		node = node->prev;
		size--;
	}
	ft_printf("\n");
}
