/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <amile-ge@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:39:31 by amile-ge          #+#    #+#             */
/*   Updated: 2024/02/21 11:15:30 by amile-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	smaller_cost(t_stack *stackx, int num, int chunks)
{
	t_piece	*temp;
	int		smaller_c;
	int		temp_smaller;
	int		indext;

	temp = stackx->first;
	smaller_c = -1;
	indext = -1;
	while (temp != NULL)
	{
		if (temp->index <= chunks * num)
		{
			temp_smaller = cost(stackx, temp->index, 'c');
			if (smaller_c == -1)
				searchsmaller(temp, smaller_c, temp_smaller, indext);
			else if (temp_smaller < smaller_c)
				searchsmaller(temp, smaller_c, temp_smaller, indext);
		}
		temp = temp->next;
	}
	return (indext);
}

void	searchsmaller(t_piece *temp, int smaller_c, int temp_smaller,
		int indext)
{
	smaller_c = temp_smaller;
	indext = temp->index;
}

int	cost(t_stack *stackx, int smalle, char type)
{
	t_piece	*tempf;
	t_piece	*templ;
	int		f;
	int		l;

	tempf = stackx->first;
	templ = stackx->last;
	f = count_mov(templ, tempf, smalle, 1);
	l = count_mov(templ, tempf, smalle, 0);
	if (type == 'c' && f < l)
		return (f);
	else if (type == 'c' && f >= l)
		return (l);
	else if (f < l)
		return (1);
	else
		return (0);
}

int	count_mov(t_piece *templ, t_piece *tempf, int smalle, int x)
{
	int	f;
	int	l;

	f = 0;
	l = 0;
	while (tempf->index != smalle)
	{
		tempf = tempf->next;
		f++;
	}
	if (x == 0)
	{
		templ = tempf;
		while (templ->next != NULL)
		{
			templ = templ->next;
			l++;
		}
		return (l);
	}
	return (f);
}
// 1 es que esta mas cerca de arriba,
// 0 es que esta mas cerca del final,
