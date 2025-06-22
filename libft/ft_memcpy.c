/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <amile-ge@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:02:02 by amile-ge          #+#    #+#             */
/*   Updated: 2023/09/23 19:54:33 by amile-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *desti, const void *src, size_t size)
{
	unsigned char		*str_str_d;
	const unsigned char	*str_str_s;
	size_t				i;

	i = 0;
	str_str_d = desti;
	str_str_s = src;
	if (src == NULL && desti == NULL)
		return (NULL);
	while (i < size)
	{
		*(str_str_d++) = *(str_str_s++);
		i++;
	}
	return (desti);
}
/*
int	main(void)
{
	char dest[50];
	char src[10] = "hola q";

	printf("%s", ft_memcpy(dest, src, 3));
	return (0);
}
*/
