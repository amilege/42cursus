/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <amile-ge@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:44:58 by amile-ge          #+#    #+#             */
/*   Updated: 2024/05/09 10:28:05 by amile-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_bzero(void *str, int size)
{
	unsigned char	*str_str;
	int				i;

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
