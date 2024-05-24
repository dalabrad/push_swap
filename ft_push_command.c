/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalabrad <dalabrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:36:08 by dalabrad          #+#    #+#             */
/*   Updated: 2024/05/24 14:03:59 by dalabrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 *
 *	Funtion that push the first node of the stack src into dest 
 * 
*/
static void	ft_push(t_stack_node **dest, t_stack_node **src)
{
	t_stack_node	*node_to_push;

	if (!*src)
		return ;
	node_to_push = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	node_to_push->prev = NULL;
	if (!*dest)
	{
		*dest = node_to_push;
		node_to_push->next = NULL;
	}
	else
	{
		node_to_push->next = *dest;
		node_to_push->next->prev = node_to_push;
		*dest = node_to_push;
	}
}

/*
 *	PUSH A (PA):
 *  ========
 *	Funtion that push the first node of the stack b into the top of the stack a 
 * 
*/
void	ft_pa(t_stack_node **a, t_stack_node **b, bool checker)
{
	ft_push(a, b);
	if (!checker)
		ft_printf("pa\n");
}

/*
 *	PUSH B (PB):
 *  ========
 *	Funtion that push the first node of the stack a into the top of the stack b 
 * 
*/
void	ft_pb(t_stack_node **b, t_stack_node **a, bool checker)
{
	ft_push(b, a);
	if (!checker)
		ft_printf("pb\n");
}
