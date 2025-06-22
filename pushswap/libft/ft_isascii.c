/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isascii.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <amile-ge@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:05:50 by amile-ge          #+#    #+#             */
/*   Updated: 2023/09/14 12:36:08 by amile-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int str)
{
	if (str >= 0 && str <= 127)
		return (1);
	return (0);
}
/*
int	isascii(int	str)
{
	return (str >= 0 && str <= 127)
}
int	main(void)
{
	int	j;

	j = isascii('a');
	printf("%d", j);

	return (0);
}
*/
