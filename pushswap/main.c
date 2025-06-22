/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <amile-ge@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 11:58:49 by amile-ge          #+#    #+#             */
/*   Updated: 2024/02/25 13:12:37 by amile-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc < 1)
		return (0);
	if (ft_check_args(argc, argv) == 1)
	{
		(write(2, "Error\n", 6));
		return (0);
	}
	ft_initstack(&stack_a);
	ft_initstack(&stack_b);
	fill_stack_a(&stack_a, argv);
	fill_index(&stack_a);
	if (check_if_ordered(&stack_a) == 0)
	{
		free_stacks(&stack_a, &stack_b);
		return (0);
	}
	ordenar(&stack_a, &stack_b, argc);
	free_stacks(&stack_a, &stack_b);
	return (0);
}
