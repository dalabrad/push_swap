/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalabrad <dalabrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:40:09 by dalabrad          #+#    #+#             */
/*   Updated: 2024/05/24 15:31:19 by dalabrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 *
 *	Funtion that swaps the value of the two first nodes of the stack. 
 * 
*/
static void	ft_swap(t_stack_node **stack)
{
	t_stack_node	*first_node;
	t_stack_node	*second_node;

	if (!*stack || !stack || ft_stack_size(*stack) == 1)
		return ;
	first_node = *stack;
	second_node = (*stack)->next;
	first_node->prev = second_node;
	first_node->next = second_node->next;
	second_node->prev = NULL;
	second_node->next = first_node;
	if (first_node->next)
		first_node->next->prev = first_node;
	*stack = second_node;
}

/*
 *	SWAP A (SA):
*/
void	ft_sa(t_stack_node	**a, bool checker)
{
	ft_swap(a);
	if (!checker)
		ft_printf("sa\n");
}

/*
 *	SWAP B (SB):
*/
void	ft_sb(t_stack_node	**b, bool checker)
{
	ft_swap(b);
	if (!checker)
		ft_printf("sb\n");
}

/*
 *	SWAP A and B (SSs):
*/
void	ft_ss(t_stack_node	**a, t_stack_node	**b, bool checker)
{
	ft_swap(a);
	ft_swap(b);
	if (!checker)
		ft_printf("ss\n");
}
