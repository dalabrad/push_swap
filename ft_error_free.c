/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalabrad <dalabrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 13:10:17 by dalabrad          #+#    #+#             */
/*   Updated: 2024/05/31 16:47:29 by dalabrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Function to free a tab
*/
void	ft_free_tab(char **tab)
{
	int	i;

	if (!tab || !*tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
}

/*
 * Function to free a stack
*/
void	ft_free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

/*
 * Function to free a stack (a), and the tab (argv) 
 * if flag_argc_2 = (argc == 2) = TRUE. Then wites a
 * stderror : "Error\n" and executes exit(1) to end 
 * the main with a return (1)
*/
void	ft_error_free(t_stack_node **a, char **argv, bool flag_argc_2)
{
	ft_free_stack(a);
	if (flag_argc_2)
		ft_free_tab(argv);
	write(2, "Error\n", 7);
	exit (1);
}

/*
 * Checks if the string of argv[i] is valid 
 * (first character can be +,- or all digits) 
 * for push_swap.
*/
bool	ft_error_syntax(char *str)
{
	if (!str)
		return (true);
	if (*str == '+' || *str == '-')
		str++;
	if (!*str)
		return (true);
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (true);
		str++;
	}
	return (false);
}

/*
 * Checks if the new number is already in the stack.
*/
bool	ft_error_repetition(t_stack_node *a, int nbr)
{
	if (!a)
		return (false);
	while (a)
	{
		if (a->value == nbr)
			return (true);
		a = a->next;
	}
	return (false);
}
