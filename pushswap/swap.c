/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <amile-ge@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 12:36:01 by amile-ge          #+#    #+#             */
/*   Updated: 2024/02/08 17:40:27 by amile-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stackx)

{
	t_piece	*temp;
	t_piece	*temp2;
	t_piece	*temp3;

	temp = stackx->first;
	temp2 = stackx->first->next;
	temp3 = stackx->first->next->next;
	stackx->first = stackx->first->next;
	stackx->first->next = temp;
	stackx->first->next->next = temp3;
}

void	sa(t_stack *stacka)
{
	swap(stacka);
	write(1, "sa\n", 3);
}

void	sb(t_stack *stackb)
{
	swap(stackb);
	write(1, "sb\n", 3);
}

void	ss(t_stack *stacka, t_stack *stackb)
{
	sa(stacka);
	sb(stackb);
	write(1, "ss\n", 3);
}
