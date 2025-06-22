/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <amile-ge@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:21:45 by amile-ge          #+#    #+#             */
/*   Updated: 2023/10/08 12:36:10 by amile-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0 && str1[i] == 0 && str2[i] == 0)
		return (0);
	while ((unsigned char)(str1[i] != '\0' || (unsigned char)str2[i] != '\0')
		&& i < n)
	{
		if (str1[i] == str2[i])
			i++;
		else
			return ((unsigned char)(str1[i]) - (unsigned char)(str2[i]));
	}
	return (0);
}
/*
int	main(void)
{
	char	*str1;
	char	*str2;

	str1 = "Hol";
	str2 = "Hola";
	printf("%d\n",ft_strncmp(str1, str2, 5));
	printf("%d",strncmp(str1, str2, 5));
	return (0);
}
*/
