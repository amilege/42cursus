/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <amile-ge@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 10:39:59 by amile-ge          #+#    #+#             */
/*   Updated: 2023/10/08 12:32:42 by amile-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	while ((char)c != s[i])
	{
		if (i <= 0)
			return (NULL);
		else
			i--;
	}
	if ((char)c == s[i])
		return ((char *)&s[i]);
	return (NULL);
}
/*
int	main(void)
{
  int a;
  char frase[] = "Hola amareamev";
  a = 'a';
  printf("%s", ft_strrchr(frase, a));
  return (0);
 }
*/
