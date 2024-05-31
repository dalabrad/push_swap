/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalabrad <dalabrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 18:29:23 by dalabrad          #+#    #+#             */
/*   Updated: 2024/05/31 20:01:47 by dalabrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * This function transform the case argc = 2: 
 * 		~ ORIGINAL INPUT: argv[1] = "n1 n2 n3 n4 ..."
 * 		~ AFTER FUNCTION: argv[1] = "n1", argv[2] = "n2" ...
*/
static char	**ft_transform_argv(char *argv1)
{
	char	*tmp;
	char	**rtrn;

	tmp = ft_strjoin("./push_swap ", argv1);
	rtrn = ft_split(tmp, ' ');
	free(tmp);
	tmp = NULL;
	return (rtrn);
}

static bool	ft_valid_line(char *line)
{
	if (!ft_strncmp(line, "pa\n", ft_strlen(line))
		|| !ft_strncmp(line, "pb\n", ft_strlen(line))
		|| !ft_strncmp(line, "ra\n", ft_strlen(line))
		|| !ft_strncmp(line, "rb\n", ft_strlen(line))
		|| !ft_strncmp(line, "rr\n", ft_strlen(line))
		|| !ft_strncmp(line, "rra\n", ft_strlen(line))
		|| !ft_strncmp(line, "rrb\n", ft_strlen(line))
		|| !ft_strncmp(line, "rrr\n", ft_strlen(line))
		|| !ft_strncmp(line, "sa\n", ft_strlen(line))
		|| !ft_strncmp(line, "sb\n", ft_strlen(line))
		|| !ft_strncmp(line, "ss\n", ft_strlen(line)))
		return (true);
	else
	{
		write (2, "Error\n", 7);
		return (false);
	}
}

static void	ft_line_command(char *line, t_stack_node **a, t_stack_node **b)
{
	if (!ft_strncmp(line, "pa\n", ft_strlen(line)))
		ft_pa(a, b, true);
	else if (!ft_strncmp(line, "pb\n", ft_strlen(line)))
		ft_pb(b, a, true);
	else if (!ft_strncmp(line, "ra\n", ft_strlen(line)))
		ft_ra(a, true);
	else if (!ft_strncmp(line, "rb\n", ft_strlen(line)))
		ft_rb(b, true);
	else if (!ft_strncmp(line, "rr\n", ft_strlen(line)))
		ft_rr(a, b, true);
	else if (!ft_strncmp(line, "rra\n", ft_strlen(line)))
		ft_rra(a, true);
	else if (!ft_strncmp(line, "rrb\n", ft_strlen(line)))
		ft_rrb(b, true);
	else if (!ft_strncmp(line, "rrr\n", ft_strlen(line)))
		ft_rrr(a, b, true);
	else if (!ft_strncmp(line, "sa\n", ft_strlen(line)))
		ft_sa(a, true);
	else if (!ft_strncmp(line, "sb\n", ft_strlen(line)))
		ft_sb(b, true);
	else if (!ft_strncmp(line, "ss\n", ft_strlen(line)))
		ft_ss(a, b, true);
}

static void	ft_print_result_free(t_stack_node **a, t_stack_node **b)
{
	if (ft_stack_sorted(*a) && ft_stack_size(*b) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_free_stack(a);
	a = NULL;
	if (*b)
	{
		ft_free_stack(b);
		b = NULL;
	}
}

int	main(int argc, char **argv)
{
	char			*line;
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_transform_argv(argv[1]);
	ft_stack_init(&a, argv, 2 == argc);
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		ft_line_command(line, &a, &b);
		if (!ft_valid_line(line))
			return (free(line), line = NULL, 1);
		free(line);
		line = NULL;
	}
	ft_print_result_free(&a, &b);
	return (0);
}
