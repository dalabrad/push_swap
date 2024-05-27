/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalabrad <dalabrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:56:59 by dalabrad          #+#    #+#             */
/*   Updated: 2024/05/27 14:50:53 by dalabrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 *
 * Function rotates the stack (1 -> 2 -> 3 -> End of Stack) =>
 * rotate => ( 2 -> 3 -> 1 -> End of Stack)
 * Sends the node on top to the bottom.
 * 
*/
static void	ft_rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;
	int				size;

	size = ft_stack_size(*stack);
	if (!stack || !*stack || size == 1)
		return ;
	last_node = ft_last_node(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

/*
 *	ROTATE A (RA):
*/
void	ft_ra(t_stack_node **a, bool checker)
{
	ft_rotate(a);
	if (!checker)
		ft_printf("ra\n");
}

/*
 *	ROTATE B (RB):
*/
void	ft_rb(t_stack_node **b, bool checker)
{
	ft_rotate(b);
	if (!checker)
		ft_printf("rb\n");
}

/*
 *	ROTATE A and B (RR):
*/
void	ft_rr(t_stack_node **a, t_stack_node **b, bool checker)
{
	ft_rotate(a);
	ft_rotate(b);
	if (!checker)
		ft_printf("rr\n");
}
