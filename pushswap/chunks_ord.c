/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_ord.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <amile-ge@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:46:50 by amile-ge          #+#    #+#             */
/*   Updated: 2024/02/25 19:24:36 by amile-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	divlent(int lent, int *chunk)
{
	int	particio;

	particio = 6;
	if (lent <= 100)
	{
		*chunk = lent / particio;
		return (particio);
	}
	else if (lent <= 510)
	{
		*chunk = 40;
		particio = lent / *chunk;
	}
	return (particio);
}

void	chunks_ord(t_stack *stack_a, t_stack *stack_b, int lent)
{
	int	t_chunks;
	int	chunks;
	int	particio;
	int	num;

	t_chunks = 0;
	particio = divlent(lent, &t_chunks);
	num = 1;
	chunks = t_chunks;
	while (num <= particio)
	{
		while (chunks != 0)
		{
			if (stack_a->first->index < t_chunks * num)
			{
				pb(stack_a, stack_b);
				chunks -= 1;
			}
			else if (stack_a->first->index >= t_chunks * num)
				ra(stack_a);
		}
		chunks = t_chunks;
		num += 1;
	}
	return_ordered(lent, stack_a, stack_b);
}

void	return_ordered(int lent, t_stack *stack_a, t_stack *stack_b)
{
	lent = len(stack_a);
	if (lent != 0)
	{
		if (lent < 6)
			check_a(stack_a, stack_b, lent);
		else
		{
			while (lent != 0)
			{
				pb(stack_a, stack_b);
				lent = len(stack_a);
			}
		}
	}
	final_ord(lent, stack_a, stack_b);
}

void	final_ord(int lent, t_stack *stack_a, t_stack *stack_b)
{
	int	smalleb;
	int	small_c;

	lent = len(stack_b);
	while (lent != 0)
	{
		smalleb = bigger(stack_b);
		small_c = cost(stack_b, smalleb, 'f');
		if (small_c == 1)
			while (stack_b->first->index != smalleb)
				rb(stack_b);
		else
			while (stack_b->first->index != smalleb)
				rrb(stack_b);
		pa(stack_a, stack_b);
		lent = len(stack_b);
	}
}

void	check_a(t_stack *stack_a, t_stack *stack_b, int lent)
{
	int	smalleb;

	lent = len(stack_a);
	if (lent != 0)
	{
		smalleb = smaller(stack_a);
		if (lent <= 5)
			small_sort(stack_a, stack_b, lent, smalleb);
	}
}
