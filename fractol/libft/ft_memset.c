/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <amile-ge@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 09:35:46 by amile-ge          #+#    #+#             */
/*   Updated: 2023/09/22 22:58:40 by amile-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memset(void *str, int c, size_t size)
{
	unsigned char	*str_str;
	size_t			i;

	str_str = (unsigned char *)str;
	i = 0;
	while (i < size)
	{
		*str_str = (unsigned char)c;
		i++;
		str_str++;
	}
	return (str);
}
/*
int main(void)
{
	unsigned char	j;
	char hola[50] = "HOLAa que tal";
	printf("%s",ft_memset(hola, '$', 10));
	return (0);
}
*/
