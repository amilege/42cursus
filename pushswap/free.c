/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <amile-ge@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:14:29 by amile-ge          #+#    #+#             */
/*   Updated: 2024/02/07 20:17:15 by amile-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
void	ft_lstdelone(t_stack *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst -> value);
	del(lst ->index);
	free(lst);
}
void	ft_lstclear(t_piece **lst, void (*del)(void*))
{
	t_piece	*temp;

	if (lst)
	{
		while(*lst)
		{
			temp = (*lst) -> next;
			ft_lstdelone(*lst, del);
			(*lst) = temp;
		}
	}
}
*/

void	free_stack(t_stack *stack)
{
	t_piece	*head;
	t_piece	*temp;

	head = stack->first;
	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

void	free_stacks(t_stack *stack_a, t_stack *stack_b)
{
	free_stack(stack_a);
	free_stack(stack_b);
}
