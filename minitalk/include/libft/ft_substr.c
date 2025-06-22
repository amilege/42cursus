/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <amile-ge@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:33:21 by amile-ge          #+#    #+#             */
/*   Updated: 2023/10/08 12:30:45 by amile-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	i;

	i = start;
	if (len == 0 || ft_strlen(s) == 0 || start >= ft_strlen(s))
	{
		substring = (char *)malloc(1);
		if (substring == NULL)
			return (NULL);
		substring[0] = '\0';
		return (substring);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	substring = malloc(len + 1);
	if (substring == NULL)
		return (NULL);
	while (i < len + start && s[i] != '\0')
	{
		substring[i - start] = s[i];
		i++;
	}
	substring[i - start] = '\0';
	return (substring);
}
/*
int	main(void)
{
	const char	s[] = "Hola, mundo";
	int			start;
	size_t		len;
	char		*j;

	start = 5;
	len = 4;
	j = ft_substr(s, start, len);
	printf("%s", j);
	return (0);
}
*/
