/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <amile-ge@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 10:47:09 by amile-ge          #+#    #+#             */
/*   Updated: 2023/10/08 12:35:08 by amile-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*strcut;
	size_t	start;
	size_t	end;
	size_t	i;

	start = 0;
	i = 0;
	end = ft_strlen(s1);
	while (!s1 && !set)
		return (0);
	while (s1[start] != '\0' && ft_strchr(set, s1[start]))
		start++;
	while (end != 0 && ft_strchr(set, s1[end]))
		end--;
	strcut = ft_substr(s1, start, end - start + 1);
	return (strcut);
}
/*
int	main(void)
{
	char	*hola;
	char	*set;

  hola = "hola hey lolaho";
  set = "ho";
  printf("%s", ft_strtrim (hola, set));
  return (0);
}
*/
