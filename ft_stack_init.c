/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalabrad <dalabrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 10:42:10 by dalabrad          #+#    #+#             */
/*   Updated: 2024/05/23 15:24:04 by dalabrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol(const char *str)
{
	long	n;
	int		sign;

	n = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		n = n * 10 + (*str - '0');
		str++;
	}
	return (sign * n);
}

/*
 * Create the stack with the command line values
 * Checks are embedded in the creation itslef
 * 		~ Duplicate values
 * 		~ INT Overflow|Underflow
 * 		~ Syntax errors
 *
 * Flag is useful cause if true, i have the argv in the HEAP to free (argc = 2)
 * Starts in argv[1] because argv[0] = ./NAME_EXECUTABLE
*/
void	ft_stack_init(t_stack_node **a, char **argv, bool flag_argc_2)
{
	long	nbr;
	int		i;

	i = 1;
	while (argv[i])
	{
		if (ft_error_syntax(argv[i]))
			ft_error_free(a, argv, flag_argc_2);
		nbr = ft_atol(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			ft_error_free(a, argv, flag_argc_2);
		if (ft_error_repetition(*a, (int)nbr))
			ft_error_free(a, argv, flag_argc_2);
		ft_append_node(a, (int)nbr);
		i++;
	}
	if (flag_argc_2)
		ft_free_tab(argv);
}
