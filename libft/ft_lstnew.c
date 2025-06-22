/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <amile-ge@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:57:47 by amile-ge          #+#    #+#             */
/*   Updated: 2024/05/02 11:19:32 by amile-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*contento;

	contento = malloc(sizeof(t_list));
	if (!contento)
		return (NULL);
	contento->content = content;
	contento->next = NULL;
	return (contento);
}
