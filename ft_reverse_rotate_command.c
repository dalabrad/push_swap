/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate_command.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalabrad <dalabrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:05:15 by dalabrad          #+#    #+#             */
/*   Updated: 2024/05/27 15:06:32 by dalabrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 *
 * Function reverse rotates the stack (1 -> 2 -> 3 -> End of Stack) =>
 * reverse_rotate => ( 3 -> 1 -> 2 -> End of Stack)
 * Sends the bottom node to the top.
 * 
*/
static void	ft_reverse_rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;
	int				size;

	size = ft_stack_size(*stack);
	if (!stack || !*stack || size == 1)
		return ;
	last_node = ft_last_node(*stack);
	last_node->prev->next = NULL;
	last_node->next = *stack;
	(*stack)->prev = last_node;
	last_node->prev = NULL;
	*stack = last_node;
}

/*
 *	REVERSE ROTATE A (RRA):
*/
void	ft_rra(t_stack_node **a, bool checker)
{
	ft_reverse_rotate(a);
	if (!checker)
		ft_printf("rra\n");
}

/*
 *	REVERSE ROTATE B (RRB):
*/
void	ft_rrb(t_stack_node **b, bool checker)
{
	ft_reverse_rotate(b);
	if (!checker)
		ft_printf("rrb\n");
}

/*
 *	REVERSE ROTATE A and B (RRR):
*/
void	ft_rrr(t_stack_node **a, t_stack_node **b, bool checker)
{
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
	if (!checker)
		ft_printf("rrr\n");
}
