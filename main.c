/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalabrad <dalabrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:16:32 by dalabrad          #+#    #+#             */
/*   Updated: 2024/05/23 15:15:15 by dalabrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int				i;
	char			*tmp;
	t_stack_node	*a;
	t_stack_node	*b;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
	{
		tmp = ft_strjoin("./push_swap ", argv[1]);
		argv = ft_split(tmp, ' ');
		i = 0;
		while (argv[i])
		{
			ft_printf("argv[%d] = '%s'\n", i, argv[i]);
			i++;
		}
		free(tmp);
		tmp = NULL;
	}
	a = NULL;
	i = 0;
	while (argv[i])
	{
		ft_printf("Argv[%d] = '%s'\n", i, argv[i]);
		i++;
	}
	ft_stack_init(&a, argv, argc == 2);
	i = 1;
	b = a;
	while (a)
	{
		ft_printf("Number [%d] = %d\n", i, a->value);
		a = a->next;
		i++;
	}
	ft_free_stack(&b);
}
