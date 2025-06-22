/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <amile-ge@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:40:44 by amile-ge          #+#    #+#             */
/*   Updated: 2023/10/08 13:01:00 by amile-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char	*str_dest;
	char	*str_src;
	size_t	i;

	str_dest = (char *)dest;
	str_src = (char *)src;
	i = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (dest > src)
	{
		while (len-- > 0)
		{
			str_dest[len] = str_src[len];
		}
	}
	else
	{
		while (i < len)
		{
			str_dest[i] = str_src[i];
			i++;
		}
	}
	return (dest);
}
/*
int	main(void)
{
	unsigned char	dest[10] = "";
	unsigned char	src[4] = "Lo";

	printf("%s\n", memmove(dest, src, 10));
	printf("%s", ft_memmove(dest, src, 10));
	return (0);
}
*/
