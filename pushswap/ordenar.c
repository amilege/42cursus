/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ordenar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <amile-ge@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 19:02:27 by amile-ge          #+#    #+#             */
/*   Updated: 2024/02/19 11:50:54 by amile-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ordtres(t_stack *stack_a, int lent)
{
	int	bigge;

	if (lent == 3)
	{
		bigge = bigger(stack_a);
		if (stack_a->first->index == bigge)
		{
			ra(stack_a);
			if (check_if_ordered(stack_a) == 1)
				sa(stack_a);
		}
		else if (stack_a->first->next->index == bigge)
		{
			rra(stack_a);
			if (check_if_ordered(stack_a) == 1)
				sa(stack_a);
		}
		else if (stack_a->last->index == bigge)
		{
			if (check_if_ordered(stack_a) == 1)
				sa(stack_a);
		}
	}
}

void	ordcuat(t_stack *stack_a, t_stack *stack_b, int lent, int smalle)
{
	if (lent == 4)
	{
		smalle = smaller(stack_a);
		if (cost(stack_a, smalle, 'f') == 1)
		{
			while (stack_a->first->index != smalle)
				ra(stack_a);
		}
		else if (cost(stack_a, smalle, 'f') == 0)
		{
			while (stack_a->first->index != smalle)
				rra(stack_a);
		}
		pb(stack_a, stack_b);
		lent = len(stack_a);
		ordtres(stack_a, lent);
		pa(stack_a, stack_b);
	}
}

void	ordcinc(t_stack *stack_a, t_stack *stack_b, int lent, int smalle)
{
	smalle = smaller(stack_a);
	if (cost(stack_a, smalle, 'f') == 1)
	{
		while (stack_a->first->index != smalle)
			ra(stack_a);
	}
	else if (cost(stack_a, smalle, 'f') == 0)
	{
		while (stack_a->first->index != smalle)
			rra(stack_a);
	}
	pb(stack_a, stack_b);
	lent = len(stack_a);
	smalle = smaller(stack_a);
	ordcuat(stack_a, stack_b, lent, smalle);
	pa(stack_a, stack_b);
}

void	small_sort(t_stack *stack_a, t_stack *stack_b, int lent, int smalle)
{
	if (lent == 2)
	{
		if (check_if_ordered(stack_a) == 1)
			sa(stack_a);
	}
	if (lent == 3)
		ordtres(stack_a, lent);
	if (lent == 4)
	{
		ordcuat(stack_a, stack_b, lent, smalle);
	}
	if (lent == 5)
	{
		ordcinc(stack_a, stack_b, lent, smalle);
	}
}

void	ordenar(t_stack *stack_a, t_stack *stack_b, int argc)
{
	int	lent;
	int	bigge;
	int	smalle;

	lent = len(stack_a);
	bigge = bigger(stack_a);
	smalle = smaller(stack_a);
	if (lent == 2 && argc)
		sa(stack_a);
	if (lent <= 5)
		small_sort(stack_a, stack_b, lent, smalle);
	else if (lent > 5)
		chunks_ord(stack_a, stack_b, lent);
}
