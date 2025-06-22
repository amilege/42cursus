/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <amile-ge@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 19:26:17 by amile-ge          #+#    #+#             */
/*   Updated: 2024/02/25 13:05:41 by amile-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **stackfrom, t_stack **stackto)
{
	t_piece	*temp;

	if ((*stackfrom)->first != NULL && (*stackfrom)->last == NULL)
		(*stackfrom)->last = (*stackfrom)->first;
	if ((*stackfrom) == NULL)
		return ;
	temp = (*stackfrom)->first;
	if (temp != NULL && (*stackfrom)->first != (*stackfrom)->last)
	{
		(*stackfrom)->first = temp->next;
		temp->next = (*stackto)->first;
		(*stackto)->first = temp;
	}
	else
	{
		(*stackfrom)->first = temp->next;
		temp->next = (*stackto)->first;
		(*stackto)->first = temp;
		(*stackfrom)->last = NULL;
	}
	if ((*stackto)->last == NULL && (*stackto)->first != NULL)
		(*stackto)->last = (*stackto)->first;
}

void	pa(t_stack *stacka, t_stack *stackb)
{
	int	a;

	push(&stackb, &stacka);
	a = len(stacka);
	stacka->len = a;
	a = len(stackb);
	stackb->len = a;
	write(1, "pa\n", 3);
}

void	pb(t_stack *stacka, t_stack *stackb)
{
	int	a;

	push(&stacka, &stackb);
	a = len(stacka);
	stacka->len = a;
	a = len(stackb);
	stackb->len = a;
	write(1, "pb\n", 3);
}
