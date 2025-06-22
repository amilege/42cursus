/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <amile-ge@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:53:08 by amile-ge          #+#    #+#             */
/*   Updated: 2024/02/18 14:33:22 by amile-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	bigger(t_stack *stackx)
{
	int		i;
	int		bigge;
	t_piece	*temp;

	i = 0;
	temp = stackx->first;
	bigge = temp->index;
	while (temp != NULL)
	{
		if (bigge < temp->index)
			bigge = temp->index;
		i++;
		temp = temp->next;
	}
	return (bigge);
}

int	smaller(t_stack *stackx)
{
	int		i;
	int		smalle;
	t_piece	*temp;

	i = 0;
	temp = stackx->first;
	smalle = temp->index;
	while (temp != NULL)
	{
		if (smalle > temp->index)
			smalle = temp->index;
		i++;
		temp = temp->next;
	}
	return (smalle);
}

int	len(t_stack *stackx)
{
	int		i;
	t_piece	*temp;

	i = 0;
	temp = stackx->first;
	while (temp != NULL)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

int	check_if_ordered(t_stack *stacka)
{
	t_piece	*temp;
	t_piece	*temp2;

	temp = stacka->first;
	while (temp != NULL)
	{
		temp2 = temp->next;
		while (temp2 != NULL)
		{
			if (temp->index > temp2->index)
				return (1);
			temp2 = temp2->next;
		}
		temp = temp->next;
	}
	return (0);
}
