/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalabrad <dalabrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:16:32 by dalabrad          #+#    #+#             */
/*   Updated: 2024/05/30 17:20:23 by dalabrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_transform_argv(char *argv1)
{
	char	*tmp;
	char	**rtrn;

	tmp = ft_strjoin("./push_swap ", argv1);
	rtrn = ft_split(tmp, ' ');
	free(tmp);
	tmp = NULL;
	return (rtrn);
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_transform_argv(argv[1]);
	ft_stack_init(&a, argv, 2 == argc);
	if (!ft_stack_sorted(a))
	{
		if (ft_stack_size(a) == 2)
			ft_sa(&a, false);
		else if (ft_stack_size(a) == 3)
			ft_sort_three(&a);
		else
			ft_push_swap(&a, &b);
	}
	ft_free_stack(&a);
	a = NULL;
	ft_printf("END\n");
	return (0);
}
