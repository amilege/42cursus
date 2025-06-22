/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <amile-ge@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 13:28:46 by amile-ge          #+#    #+#             */
/*   Updated: 2023/10/08 12:55:00 by amile-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] && ((char)c != *s))
		s++;
	if ((char)c == *s)
		return ((char *)&s[i]);
	return (NULL);
}
/*
int	main(void)
{
	int			n;
	const char	*hola;

	hola = "Hola meu ret";
	n = 109;
	printf("%s", ft_strchr(hola, n));
	return (0);
}
*/
