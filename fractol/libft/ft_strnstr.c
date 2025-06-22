/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <amile-ge@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 13:56:24 by amile-ge          #+#    #+#             */
/*   Updated: 2023/10/08 12:35:51 by amile-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	b;
	size_t	s;

	b = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[b] != '\0')
	{
		s = 0;
		while (haystack[b + s] == needle[s] && (b + s) < len)
		{
			if (haystack[b + s] == '\0' && needle[s] == '\0')
				return ((char *)haystack + b);
			s++;
		}
		if (needle[s] == '\0')
			return ((char *)&haystack[b]);
		b++;
	}
	return (0);
}
/*
int	main(int argc, char **argv)
{
	if (argc == 4)
		printf("%s", ft_strnstr(argv[1], argv[2], atoi(argv[3])));
	write(1, "\n", 1);
	write(1, "bien?", 6);
	return (0);
}
*/
