/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalabrad <dalabrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:16:32 by dalabrad          #+#    #+#             */
/*   Updated: 2024/05/24 14:16:29 by dalabrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char			*tmp;
	t_stack_node	*a;
	t_stack_node	*b;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
	{
		tmp = ft_strjoin("./push_swap ", argv[1]);
		argv = ft_split(tmp, ' ');
		free(tmp);
		tmp = NULL;
	}
	a = NULL;
	b = NULL;
	ft_stack_init(&a, argv, argc == 2);
	ft_printf("Stack a:\n");
	ft_print_stack(a);
	ft_printf("\nStack b:\n");
	ft_print_stack(b);
	ft_printf("\n--------------------\n\n");
	ft_pb(&b, &a, false);
	ft_printf("\n--------------------\n\n");
	ft_printf("\nStack a after pb:\n");
	ft_print_stack(a);
	ft_printf("\nStack b after pb:\n");
	ft_print_stack(b);
	ft_free_stack(&a);
	ft_free_stack(&b);
	a = NULL;
	b = NULL;
	ft_printf("\n=====================================================\n");
	ft_stack_init(&b, argv, argc == 2);
	ft_printf("Stack a:\n");
	ft_print_stack(a);
	ft_printf("\nStack b:\n");
	ft_print_stack(b);
	ft_printf("\n--------------------\n\n");
	ft_pa(&a, &b, false);
	ft_printf("\n--------------------\n\n");
	ft_printf("\nStack a after pb:\n");
	ft_print_stack(a);
	ft_printf("\nStack b after pb:\n");
	ft_print_stack(b);
	ft_free_stack(&a);
	ft_free_stack(&b);
	a = NULL;
	b = NULL;
	return (0);
}
