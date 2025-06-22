/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <amile-ge@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 17:27:19 by amile-ge          #+#    #+#             */
/*   Updated: 2023/09/26 13:31:08 by amile-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t destsize)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	if (destsize != 0)
	{
		while (src[j] != 0 && j < (destsize - 1))
		{
			dest[j] = src[j];
			j++;
		}
		dest[j] = '\0';
	}
	return (i);
}
/*
int main(void)
{
	char origen[] = "hola que tal";
	char dest[10];
	int tamano;
	int size = 8;

	tamano = ft_strlcpy(dest, origen, size);
	printf("%d", tamano);
	return (0);
}
*/
