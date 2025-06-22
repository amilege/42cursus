/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <amile-ge@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:44:58 by amile-ge          #+#    #+#             */
/*   Updated: 2023/10/08 13:19:20 by amile-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_bzero(void *str, size_t size)
{
	unsigned char	*str_str;
	size_t			i;

	str_str = (unsigned char *)str;
	i = 0;
	while (i < size)
	{
		*str_str = '\0';
		str_str++;
		i++;
	}
	return (str);
}
/*
int	main(void)
{
	char	hola[50] = "hola que tla";

	printf("%s\n", ft_bzero(hola, 10));
	printf("zz");
	return (0);
}
*/
