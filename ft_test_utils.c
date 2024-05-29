/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalabrad <dalabrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:02:11 by dalabrad          #+#    #+#             */
/*   Updated: 2024/05/24 15:21:53 by dalabrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stack(t_stack_node	*node)
{
	unsigned int	i;

	i = 1;
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
		ft_printf(" <-- n[%d] = %d", size, node->value);
		node = node->prev;
		size--;
	}
	ft_printf("\n");
}