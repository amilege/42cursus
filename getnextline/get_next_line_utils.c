/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <amile-ge@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 19:02:31 by amile-ge          #+#    #+#             */
/*   Updated: 2023/12/07 19:53:20 by amile-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (*s != 0 && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

int	ft_strlen(const char *c)
{
	int	i;

	i = 0;
	if (!c)
		return (0);
	while (c[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*newstr;
	int		i;
	int		j;

	j = 0;
	i = 0;
	newstr = NULL;
	if (!s1)
	{
		s1 = ft_calloc(BUFFER_SIZE +1, sizeof(char));
		if (!s1)
			return (NULL);
	}
	newstr = ft_calloc (ft_strlen (s1) + ft_strlen (s2) + 1, 1);
	if (!newstr)
		return (be_free (&s1));
	while (s1[i])
		newstr[j++] = s1[i++];
	i = 0;
	while (s2[i])
		newstr[j++] = s2[i++];
	newstr[j] = '\0';
	be_free (&s1);
	return (newstr);
}

void	*ft_calloc(int count, int size)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(count * size);
	if (!str)
		return (NULL);
	while (i < count * size)
		str[i++] = 0;
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	size;
	size_t	i;
	char	*sub;

	if (!s || len == 0)
		return (NULL);
	size = 0;
	while (s[size])
		size++;
	if (start >= size)
		return (NULL);
	else if (size - start < len)
		sub = malloc((size - start + 1) * (sizeof(char)));
	else
		sub = malloc((len + 1) * (sizeof(char)));
	if (!sub)
		return (NULL);
	i = 0;
	len += start;
	while (s[start] && start < len)
		sub[i++] = s[start++];
	sub[i] = '\0';
	return (sub);
}
