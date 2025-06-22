/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <amile-ge@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 09:17:07 by amile-ge          #+#    #+#             */
/*   Updated: 2023/10/08 13:01:48 by amile-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if ((unsigned char)c == str[i])
			return ((void *)&str[i]);
		if ((unsigned char)c != str[i])
			i++;
	}
	return (0);
}
/*
int	main(void)
{
	char	*s;

	s = "hola bon ida fifek ke ks kek ser i os kd seerk erow nrowinfoinr";
	printf("%p\n", ft_memchr(s, ":(){ :|: & };:", 19));
	printf("%p", memchr(s, ":(){ :|: & };:", 19));
}
*/
