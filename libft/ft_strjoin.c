/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <amile-ge@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 09:13:50 by amile-ge          #+#    #+#             */
/*   Updated: 2023/10/08 12:52:20 by amile-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (s1 == 0 || s2 == 0 || (ft_strlen(s1) == 0 && ft_strlen(s2) == 0))
	{
		newstr = (char *)ft_calloc(1, 1);
		return (newstr);
	}
	newstr = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (newstr == 0)
		return (NULL);
	while (i < ft_strlen(s1) && s1[i] != '\0')
	{
		newstr[i] = s1[i];
		i++;
	}
	while (j < ft_strlen(s2) && s2[j] != '\0')
	{
		newstr[i + j] = s2[j];
		j++;
	}
	return (newstr);
}
