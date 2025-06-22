/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <amile-ge@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 09:49:12 by amile-ge          #+#    #+#             */
/*   Updated: 2024/02/25 12:07:12 by amile-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse(t_stack *stack_a)
{
	t_piece	*prev;
	t_piece	*cursor;
	t_piece	*temp;

	if (stack_a->len == 2)
	{
		temp = stack_a->first;
		stack_a->first = stack_a->last;
		stack_a->last = temp;
		stack_a->first->next = stack_a->last;
		stack_a->last->next = NULL;
		return ;
	}
	prev = stack_a->first;
	cursor = prev;
	while (cursor->next)
	{
		prev = cursor;
		cursor = cursor->next;
	}
	temp = stack_a->first;
	stack_a->first = stack_a->last;
	stack_a->first->next = temp;
	prev->next = NULL;
	stack_a->last = prev;
}

void	rra(t_stack *stack_a)
{
	reverse(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack *stack_b)
{
	reverse(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	write(3, "rrr\n", 4);
}
