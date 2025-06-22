/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <amile-ge@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:33:12 by amile-ge          #+#    #+#             */
/*   Updated: 2024/02/25 12:04:43 by amile-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *stackx)
{
	t_piece	*oldfirst;
	t_piece	*lastt;
	t_piece	*temp;

	temp = stackx->first;
	if (stackx->first != NULL && stackx->last == NULL)
	{
		while (temp->next != NULL)
			temp = temp->next;
		stackx->last = temp;
	}
	lastt = stackx->last;
	oldfirst = stackx->first;
	stackx->first = stackx->first->next;
	lastt->next = oldfirst;
	stackx->last = oldfirst;
	oldfirst->next = NULL;
	if (stackx->first == NULL && stackx->last != NULL)
		stackx->first = stackx->last;
}

void	ra(t_stack *stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
}

void	rb(t_stack *stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	ra(stack_a);
	rb(stack_b);
	write(1, "rr\n", 3);
}
